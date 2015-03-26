#ifndef PARTICLE_SYSTEM_MANAGER_H
#define PARTICLE_SYSTEM_MANAGER_H

#include <OgreSingleton.h>

#include "Particle.h"
//#include "ParticleSystem.h"



class ParticleSystemManager: public Ogre::Singleton< ParticleSystemManager >
{
public:
    ParticleSystemManager();
    ~ParticleSystemManager();

    void Update();

private:
    Ogre::SceneNode* m_SceneNode;

    Particle* m_Particle;
    //std::vector< ParticleSystem* > m_ParticleSystems;
};



#endif // PARTICLE_SYSTEM_MANAGER_H
