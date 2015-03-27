#include "Particle.h"
#include "ParticleAffector.h"



ParticleAffector::ParticleAffector()
{
}



ParticleAffector::~ParticleAffector()
{
}



void
ParticleAffector::Update( Particle* particle )
{
    int cttl = ( int )( particle->GetCurrentTTL() * 10.0f );
    if( cttl & 1 )
    {
        particle->SetVisible( false );
    }
    else
    {
        particle->SetVisible( true );
    }
}
