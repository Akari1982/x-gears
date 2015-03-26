#ifndef PARTICLE_SYSTEM_H
#define PARTICLE_SYSTEM_H

#include "ParticleTechnique.h"



class ParticleSystem
{
public:
    ParticleSystem( const Ogre::String& name );
    virtual ~ParticleSystem();

    void Update();
    void Render();

private:
    UiWidget();

private:
    Ogre::String m_Name;

    std::vector< ParticleTechnique* > m_Techniques;
};



#endif // PARTICLE_SYSTEM_H
