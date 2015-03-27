#ifndef PARTICLE_AFFECTOR_H
#define PARTICLE_AFFECTOR_H

class Particle;



class ParticleAffector
{
public:
    ParticleAffector();
    virtual ~ParticleAffector();

    virtual void Update( Particle* particle );
};



#endif // PARTICLE_AFFECTOR_H
