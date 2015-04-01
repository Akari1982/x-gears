#include <OgreRoot.h>

#include "Logger.h"
#include "ParticleSystemManager.h"

template<> ParticleSystemManager* Ogre::Singleton< ParticleSystemManager >::msSingleton = 0;



ParticleSystemManager::ParticleSystemManager()
{
    LOG_TRIVIAL( "ParticleSystemManager created." );

    //m_SceneNode = Ogre::Root::getSingleton().getSceneManager( "Scene" )->getRootSceneNode()->createChildSceneNode( "ParticleSystemManager" );



    //Ogre::SceneNode* node = m_SceneNode->createChildSceneNode( "TestParticle" );
    //m_Particle = new Particle( node );
    //m_Particle->AddAffector( new ParticleAffector() );
}



ParticleSystemManager::~ParticleSystemManager()
{
/*
    for( unsigned int i = 0; i < m_ParticleSystems.size(); ++i )
    {
        delete m_ParticleSystems[ i ];
    }
*/

    //delete m_Particle;

    //m_SceneNode->removeAndDestroyAllChildren();

    //Ogre::Root::getSingleton().getSceneManager( "Scene" )->getRootSceneNode()->removeAndDestroyChild( "ParticleSystemManager" );

    LOG_TRIVIAL( "ParticleSystemManager destroyed." );
}



void
ParticleSystemManager::Update()
{
    //m_Particle->Update();

/*
    for( unsigned int i = 0; i < m_ParticleSystems.size(); ++i )
    {
        m_ParticleSystems[ i ]->Update();
    }
*/
}
