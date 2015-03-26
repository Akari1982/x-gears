#include "ParticleSystemManager.h"



template<> ParticleSystemManager* Ogre::Singleton< ParticleSystemManager >::msSingleton = 0;



ParticleSystemManager::ParticleSystemManager()
{
}



ParticleSystemManager::~ParticleSystemManager()
{
    for( unsigned int i = 0; i < m_ParticleSystems.size(); ++i )
    {
        delete m_ParticleSystems[ i ];
    }
}



void
ParticleSystemManager::Update()
{
    for( unsigned int i = 0; i < m_ParticleSystems.size(); ++i )
    {
        m_ParticleSystems[ i ]->Update();
    }
}



void
ParticleSystemManager::renderQueueStarted( Ogre::uint8 queueGroupId, const Ogre::String& invocation, bool& skipThisInvocation )
{
    if( queueGroupId == Ogre::RENDER_QUEUE_OVERLAY )
    {
        Ogre::Root::getSingletonPtr()->getRenderSystem()->clearFrameBuffer( Ogre::FBT_DEPTH );

        for( unsigned int i = 0; i < m_ParticleSystemsm_ParticleSystems.size(); ++i )
        {
            m_ParticleSystems[ i ]->Render();
        }
    }
}
