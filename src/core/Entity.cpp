#include "Entity.h"

#include <OgreSceneNode.h>
#include <OgreEntity.h>

#include "ConfigVar.h"
#include "DebugDraw.h"
#include "EntityManager.h"
#include "Logger.h"



ConfigVar cv_debug_entity( "debug_entity", "Draw entity debug info", "0" );



Entity::Entity( const Ogre::String& name, Ogre::SceneNode* node ):
    m_Name( name ),
    m_SceneNode( node ),
    m_Model( NULL ),
    m_SolidRadius( 0.24f ),
    m_Solid( false ),
    m_Player( false ),
    m_Move( false ),
    m_RotationY( Ogre::Degree( 0.0f ) ),
    m_SizeY( 10.0f )
{
    m_SceneNode->setPosition( Ogre::Vector3::ZERO );

    m_SolidCollision = new EntityCollision();
    m_SolidCollision->setMaterial( "entity/solid_collision" );
    m_SolidCollisionNode = m_SceneNode->createChildSceneNode();
    m_SolidCollisionNode->setScale( m_SolidRadius, -m_SizeY, m_SolidRadius );
    m_SolidCollisionNode->attachObject( m_SolidCollision );

    m_Direction = new EntityDirection();
    m_Direction->setMaterial( "entity/direction" );
    m_DirectionNode = m_SceneNode->createChildSceneNode();
    m_DirectionNode->attachObject( m_Direction );

    LOG_TRIVIAL( "Entity \"" + m_Name + "\" created." );
}



Entity::~Entity()
{
    delete m_SolidCollision;
    delete m_Direction;

    if( m_Model != NULL )
    {
        Ogre::Root::getSingleton().getSceneManager( "Scene" )->destroyEntity( m_Model );
    }
    m_SceneNode->removeAndDestroyAllChildren();

    LOG_TRIVIAL( "Entity \"" + m_Name + "\" destroyed." );
}



void
Entity::UpdateDebug()
{
    int debug = cv_debug_entity.GetI();

    m_SolidCollisionNode->setVisible( m_Solid );
    m_DirectionNode->setVisible( true );

    // debug output
    if( debug > 0 )
    {
        DEBUG_DRAW.SetColour( Ogre::ColourValue::White );
        DEBUG_DRAW.SetScreenSpace( true );
        DEBUG_DRAW.SetTextAlignment( DEBUG_DRAW.CENTER );
        DEBUG_DRAW.SetFadeDistance( 40, 50 );

        Ogre::Vector3 entity_pos = GetPosition();

        DEBUG_DRAW.Text( entity_pos, 0, 0, m_Name );
        DEBUG_DRAW.Text( entity_pos, 0, 24, Ogre::StringConverter::toString( entity_pos ) );
    }
}



const Ogre::String&
Entity::GetName() const
{
    return m_Name;
}



void
Entity::SetModel( const Ogre::String file_name )
{
    Ogre::SceneManager* scene_manager;
    scene_manager = Ogre::Root::getSingleton().getSceneManager( "Scene" );
    m_Model = scene_manager->createEntity( m_Name, file_name );
    m_Model->setVisible( true );

    m_SceneNode->attachObject( m_Model );
}



void
Entity::ScriptInitPC( const int character_id )
{
    m_Solid = true;
    m_Player = true;
}



void
Entity::ScriptInput()
{
    if( m_Player == true )
    {
        Ogre::Degree rotation = m_RotationY;
        m_Move = EntityManager::getSingleton().InputToRotation( rotation );
        SetRotation( rotation );
    }
}



void
Entity::SetPosition( const Ogre::Vector3& position )
{
    m_SceneNode->setPosition( position );
}



const Ogre::Vector3
Entity::GetPosition() const
{
    return m_SceneNode->getPosition();
}



void
Entity::SetRotation( const Ogre::Degree& rotation )
{
    m_RotationY = rotation;

    float angle = rotation.valueDegrees() - Ogre::Math::Floor( rotation.valueDegrees() / 360.0f ) * 360.0f;
    if( angle < 0 )
    {
        angle = 360 + angle;
    }

    Ogre::Quaternion q;
    Ogre::Vector3 vec = Ogre::Vector3::UNIT_Y;
    q.FromAngleAxis( Ogre::Radian( Ogre::Degree( angle ) ), vec );
    m_SceneNode->setOrientation( q );
}



Ogre::Degree
Entity::GetRotation() const
{
    return m_RotationY;
}



void
Entity::SetVisible( const bool visible )
{
    if( m_Model != NULL )
    {
        m_Model->setVisible( visible );
    }
}



bool
Entity::IsVisible() const
{
    if( m_Model != NULL )
    {
        return m_Model->isVisible();
    }
    return false;
}



void
Entity::SetSolidRadius( const float radius )
{
    m_SolidRadius = radius;
    m_SolidCollisionNode->setScale( m_SolidRadius, -m_SizeY, m_SolidRadius );
}



float
Entity::GetSolidRadius() const
{
    return m_SolidRadius;
}



void
Entity::SetSolid( const bool solid )
{
    m_Solid = solid;
}



bool
Entity::IsSolid() const
{
    return m_Solid;
}



bool
Entity::IsPlayer() const
{
    return m_Player;
}



bool
Entity::IsMove() const
{
    return m_Move;
}
