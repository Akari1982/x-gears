#include "Entity.h"

#include <OgreSceneNode.h>

#include "ConfigVar.h"
#include "DebugDraw.h"
#include "Logger.h"



ConfigVar cv_debug_entity( "debug_entity", "Draw entity debug info", "0" );



Entity::Entity( const Ogre::String& name, Ogre::SceneNode* node ):
    m_Name( name ),
    m_SceneNode( node )
{
    m_ModelNode = m_SceneNode->createChildSceneNode();

    m_ModelNode->setPosition( Ogre::Vector3::ZERO );
    m_SceneNode->setPosition( Ogre::Vector3::ZERO );

    LOG_TRIVIAL( "Entity \"" + m_Name + "\" created." );
}



Entity::~Entity()
{
    m_SceneNode->removeAndDestroyAllChildren();

    LOG_TRIVIAL( "Entity \"" + m_Name + "\" destroyed." );
}



void
Entity::Update()
{
}



void
Entity::UpdateDebug()
{
    int debug = cv_debug_entity.GetI();

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
    float angle = rotation.valueDegrees() - Ogre::Math::Floor( rotation.valueDegrees() / 360.0f ) * 360.0f;

    if( angle < 0 )
    {
        angle = 360 + angle;
    }

    Ogre::Quaternion q;
    Ogre::Vector3 vec = Ogre::Vector3::UNIT_Y;
    q.FromAngleAxis( Ogre::Radian( Ogre::Degree( angle ) ), vec );
    m_ModelNode->setOrientation( q );
}



Ogre::Degree
Entity::GetRotation() const
{
    Ogre::Quaternion q = m_ModelNode->getOrientation();
    Ogre::Degree temp;
    Ogre::Vector3 vec = Ogre::Vector3::UNIT_Z;
    q.ToAngleAxis( temp, vec );

    return temp;
}
