#include "EntityModel.h"

#include <OgreEntity.h>
#include <OgreRoot.h>

#include "../core/Logger.h"
#include "../core/Timer.h"



EntityModel::EntityModel( const Ogre::String& name, const Ogre::String file_name, Ogre::SceneNode* node ):
    Entity( name, node )
{
    Ogre::SceneManager* scene_manager;
    scene_manager = Ogre::Root::getSingleton().getSceneManager( "Scene" );
    m_Model = scene_manager->createEntity( m_Name, file_name );
    m_Model->setVisible( true );

    m_ModelNode->attachObject( m_Model );
}



EntityModel::~EntityModel()
{
    Ogre::Root::getSingleton().getSceneManager( "Scene" )->destroyEntity( m_Model );
}



void
EntityModel::Update()
{
    Entity::Update();
}



void
EntityModel::SetVisible( const bool visible )
{
    m_Model->setVisible( visible );
}



bool
EntityModel::IsVisible() const
{
    return m_Model->isVisible();
}
