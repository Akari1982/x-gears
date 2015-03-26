#ifndef PARTICLE_TECHNIQUE_H
#define PARTICLE_TECHNIQUE_H

#include "Particle.h"
#include "ParticleEmitter.h"



class ParticleTechnique
{
public:
    ParticleTechnique();
    virtual ~ParticleTechnique();

    void Update();
    void Render();

private:
    std::vector< Particle* > m_Particles;
    std::vector< ParticleEmitter* > m_Emitters;
};



#endif // PARTICLE_TECHNIQUE_H
