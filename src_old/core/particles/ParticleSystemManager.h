#ifndef PARTICLE_SYSTEM_MANAGER_H
#define PARTICLE_SYSTEM_MANAGER_H

#include <OgreRenderQueueListener.h>
#include <OgreSingleton.h>

#include "ParticleSystem.h"



class ParticleSystemManager: public Ogre::RenderQueueListener, public Ogre::Singleton< ParticleSystemManager >
{
public:
    ParticleSystemManager();
    ~ParticleSystemManager();

    void Update();

    void renderQueueStarted( Ogre::uint8 queueGroupId, const Ogre::String& invocation, bool& skipThisInvocation );

private:
    std::vector< ParticleSystem* > m_ParticleSystems;
};



#endif // PARTICLE_SYSTEM_MANAGER_H
