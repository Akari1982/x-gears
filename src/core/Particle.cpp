#include <OgreEntity.h>
#include <OgreRoot.h>

#include "Logger.h"
#include "Particle.h"
#include "Timer.h"



Particle::Particle( Ogre::SceneNode* node ):
    m_SceneNode( node ),

    m_Position( Ogre::Vector3::ZERO ),
    m_Direction( Ogre::Vector3::ZERO ),
    m_CurrentTTL( 0.0f ),
    m_DefaultTTL( 10.0f )
{
    m_ModelNode = m_SceneNode->createChildSceneNode();

    Ogre::SceneManager* scene_manager;
    scene_manager = Ogre::Root::getSingleton().getSceneManager( "Scene" );
    m_Model = scene_manager->createEntity( "Test", "models/ffvii/battle/effects/machinegun_fire.mesh" );
    m_Model->setVisible( true );

    m_ModelNode->attachObject( m_Model );



    m_ModelNode->setPosition( Ogre::Vector3::ZERO );
    m_SceneNode->setPosition( Ogre::Vector3::ZERO );
}



Particle::~Particle()
{
    for( unsigned int i = 0; i < m_Affectors.size(); ++i )
    {
        delete m_Affectors[ i ];
    }
}



void
Particle::Update()
{
    float delta_time = Timer::getSingleton().GetGameTimeDelta();
    m_CurrentTTL += delta_time;

    if( m_CurrentTTL >= m_DefaultTTL )
    {
        m_CurrentTTL = m_DefaultTTL;
        SetVisible( false );
    }
    else
    {
        m_Position += m_Direction * delta_time;

        for( unsigned int i = 0; i < m_Affectors.size(); ++i )
        {
            m_Affectors[ i ]->Update( this );
        }
    }
}



void
Particle::SetVisible( const bool visible )
{
    m_Model->setVisible( visible );
}



bool
Particle::IsVisible() const
{
    return m_Model->isVisible();
}



void
Particle::AddAffector( ParticleAffector* affector )
{
    m_Affectors.push_back( affector );
}



float
Particle::GetCurrentTTL() const
{
    return m_CurrentTTL;
}
