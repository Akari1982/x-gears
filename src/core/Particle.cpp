#include "Particle.h"

#include "Timer.h"



Particle::Particle( Ogre::SceneNode* node ):
    m_SceneNode( node ),

    m_Position( Ogre::Vector3::ZERO ),
    m_Direction( Ogre::Vector3::ZERO ),
    m_CurrentTTL( 10.0f ),
    m_DefaultTTL( 10.0f )
{
    m_ModelNode = m_SceneNode->createChildSceneNode();

    Ogre::SceneManager* scene_manager;
    scene_manager = Ogre::Root::getSingleton().getSceneManager( "Scene" );
    m_Model = scene_manager->createEntity( "Test", "models\ffvii\battle\effects\machinegun_fire.mesh" );
    m_Model->setVisible( true );

    PlayAnimation( m_AnimationDefault, Entity::AUTO_ANIMATION, Entity::PLAY_LOOPED, 0, -1 );

    m_ModelNode->attachObject( m_Model );



    m_ModelNode->setPosition( Ogre::Vector3::ZERO );
    m_SceneNode->setPosition( Ogre::Vector3::ZERO );
};



Particle::~Particle()
{
};



void
Particle::Update()
{
    float delta_time = Timer::getSingleton().GetGameTimeDelta();
    m_Position += m_Direction * delta_time;
}
