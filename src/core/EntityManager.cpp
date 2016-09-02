#include "EntityManager.h"

#include <OgreEntity.h>
#include <OgreRoot.h>

#include "CameraManager.h"
#include "ConfigVar.h"
#include "DebugDraw.h"
#include "EntityModel.h"
#include "InputManager.h"
#include "Logger.h"
#include "Math.h"
#include "ScriptManager.h"
#include "Timer.h"



template<>EntityManager *Ogre::Singleton< EntityManager >::msSingleton = NULL;



ConfigVar cv_debug_grid( "debug_grid", "Draw debug grid", "false" );
ConfigVar cv_debug_axis( "debug_axis", "Draw debug axis", "false" );
ConfigVar cv_debug_walkmesh( "debug_walkmesh", "Draw walkmesh and walkmesh debug info", "0" );



EntityManager::EntityManager()
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
}



void
EntityManager::Update()
{
    for( size_t i = 0; i < m_Entity.size(); ++i )
    {
        m_Entity[ i ]->Update();
    }

    UpdateDebug();
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

    for( size_t i = 0; i < m_EntityTriggers.size(); ++i )
    {
        m_EntityTriggers[ i ]->UpdateDebug();
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


    for( unsigned int i = 0; i < m_EntityTriggers.size(); ++i )
    {
        delete m_EntityTriggers[ i ];
    }
    m_EntityTriggers.clear();

    m_SceneNode->removeAndDestroyAllChildren();
}



void
EntityManager::AddWalkmesh( Walkmesh* walkmesh )
{
    m_Walkmesh.push_back( walkmesh );
}



void
EntityManager::AddEntity( const Ogre::String& name, const Ogre::String& file_name, const Ogre::Vector3& position, const Ogre::Degree& rotation )
{
    Ogre::SceneNode* node = m_SceneNode->createChildSceneNode( "Model_" + name );
    EntityModel* entity = new EntityModel( name, file_name, node );
    entity->SetPosition( position );
    entity->SetRotation( rotation );
    m_Entity.push_back( entity );
}



void
EntityManager::AddSquareTrigger( const Ogre::String& name, const Ogre::Vector3& point1, const Ogre::Vector3& point2, const Ogre::Vector3& point3, const Ogre::Vector3& point4, const bool enabled )
{
    EntityTrigger* trigger = new EntityTrigger( name );
    trigger->SetSquareTrigger( point1, point2, point3, point4 );
    m_EntityTriggers.push_back( trigger );
}
