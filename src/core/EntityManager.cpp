#include "EntityManager.h"

#include <OgreEntity.h>
#include <OgreRoot.h>

#include "CameraManager.h"
#include "ConfigVar.h"
#include "DebugDraw.h"
#include "InputManager.h"
#include "Logger.h"
#include "Math.h"
#include "ScriptManager.h"
#include "Timer.h"



template<>EntityManager *Ogre::Singleton< EntityManager >::msSingleton = NULL;



ConfigVar cv_debug_grid( "debug_grid", "Draw debug grid", "false" );
ConfigVar cv_debug_axis( "debug_axis", "Draw debug axis", "false" );
ConfigVar cv_debug_walkmesh( "debug_walkmesh", "Draw walkmesh and walkmesh debug info", "0" );



EntityManager::EntityManager():
    m_MoveMask( 0x00 )
{
    LOG_TRIVIAL( "EntityManager created." );

    m_SceneNode = Ogre::Root::getSingleton().getSceneManager( "Scene" )->getRootSceneNode()->createChildSceneNode( "EntityManager" );

    m_Grid = Ogre::Root::getSingleton().getSceneManager( "Scene" )->createEntity( "Grid", "system/grid.mesh" );
    m_SceneNode->attachObject( m_Grid );
    m_Axis = Ogre::Root::getSingleton().getSceneManager( "Scene" )->createEntity( "Axis", "system/axis.mesh" );
    m_SceneNode->attachObject( m_Axis );
}



EntityManager::~EntityManager()
{
    if( m_Grid != NULL )
    {
        Ogre::Root::getSingleton().getSceneManager( "Scene" )->destroyEntity( m_Grid );
    }
    if( m_Axis != NULL )
    {
        Ogre::Root::getSingleton().getSceneManager( "Scene" )->destroyEntity( m_Axis );
    }

    Clear();

    Ogre::Root::getSingleton().getSceneManager( "Scene" )->getRootSceneNode()->removeAndDestroyChild( "EntityManager" );

    LOG_TRIVIAL( "EntityManager destroyed." );
}



void
EntityManager::Input( const Event& event )
{
    if( event.type == ET_REPEAT )
    {
        if( event.event == "walk_left" )
        {
            m_MoveMask |= 0x08;
        }
        else if( event.event == "walk_right" )
        {
            m_MoveMask |= 0x02;
        }
        else if( event.event == "walk_down" )
        {
            m_MoveMask |= 0x04;
        }
        else if( event.event == "walk_up" )
        {
            m_MoveMask |= 0x01;
        }
    }
}



bool
EntityManager::InputToRotation( Ogre::Degree& rotation )
{
    switch( m_MoveMask )
    {
        case 0x00: return false;
        case 0x01: rotation = Ogre::Degree( 0 ); return true;
        case 0x02: rotation = Ogre::Degree( 90 ); return true;
        case 0x03: rotation = Ogre::Degree( 45 ); return true;
        case 0x04: rotation = Ogre::Degree( 180 ); return true;
        case 0x05: rotation = Ogre::Degree( 0 ); return false;
        case 0x06: rotation = Ogre::Degree( 135 ); return true;
        case 0x07: rotation = Ogre::Degree( 90 ); return true;
        case 0x08: rotation = Ogre::Degree( 270 ); return true;
        case 0x09: rotation = Ogre::Degree( 315 ); return true;
        case 0x0a: rotation = Ogre::Degree( 0 ); return false;
        case 0x0b: rotation = Ogre::Degree( 0 ); return true;
        case 0x0c: rotation = Ogre::Degree( 225 ); return true;
        case 0x0d: rotation = Ogre::Degree( 270 ); return true;
        case 0x0e: rotation = Ogre::Degree( 180 ); return true;
        case 0x0f: rotation = Ogre::Degree( 0 ); return false;
    }
    return false;
}



void
EntityManager::Update()
{
    // update all entity scripts
    ScriptManager::getSingleton().Update( ScriptManager::ENTITY );



    // perform movement
    for( size_t i = 0; i < m_Entity.size(); ++i )
    {
    }



    UpdateDebug();



    // reset currently active move events
    m_MoveMask = 0x00;
}



void
EntityManager::UpdateDebug()
{
    m_Grid->setVisible( cv_debug_grid.GetB() );
    m_Axis->setVisible( cv_debug_axis.GetB() );

    for( size_t i = 0; i < m_Entity.size(); ++i )
    {
        m_Entity[ i ]->UpdateDebug();
    }

    for( size_t i = 0; i < m_Triggers.size(); ++i )
    {
        m_Triggers[ i ]->UpdateDebug();
    }

    int debug_w = cv_debug_walkmesh.GetI();
    for( size_t i = 0; i < m_Walkmesh.size(); ++i )
    {
        if( ( debug_w >> i ) & 1 )
        {
            m_Walkmesh[ i ]->UpdateDebug();
        }
    }
}



void
EntityManager::OnResize()
{
}



void
EntityManager::Clear()
{
    for( size_t i = 0; i < m_Walkmesh.size(); ++i )
    {
        delete m_Walkmesh[ i ];
    }
    m_Walkmesh.clear();

    for( unsigned int i = 0; i < m_Entity.size(); ++i )
    {
        delete m_Entity[ i ];
    }
    m_Entity.clear();


    for( unsigned int i = 0; i < m_Triggers.size(); ++i )
    {
        delete m_Triggers[ i ];
    }
    m_Triggers.clear();

    m_SceneNode->removeAndDestroyAllChildren();
}



void
EntityManager::AddWalkmesh( Walkmesh* walkmesh )
{
    m_Walkmesh.push_back( walkmesh );
}




void
EntityManager::AddEntity( const Ogre::String& name, const Ogre::String& file_name, const Ogre::Vector3& position, const Ogre::Degree& rotation, const bool script )
{
    Ogre::SceneNode* node = m_SceneNode->createChildSceneNode( "Model_" + name );
    Entity* entity = new Entity( name, node );

    if( file_name != "" )
    {
        entity->SetModel( file_name );
    }

    if( script == true )
    {
        ScriptManager::getSingleton().AddEntity( ScriptManager::ENTITY, name, entity );
    }

    entity->SetPosition( position );
    entity->SetRotation( rotation );
    m_Entity.push_back( entity );
}



void
EntityManager::AddSquareTrigger( const Ogre::String& name, const Ogre::Vector3& point1, const Ogre::Vector3& point2, const Ogre::Vector3& point3, const Ogre::Vector3& point4, const bool enabled )
{
    Trigger* trigger = new Trigger( name );
    trigger->SetSquareTrigger( point1, point2, point3, point4 );
    m_Triggers.push_back( trigger );
}
