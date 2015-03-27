#ifndef PARTICLE_H
#define PARTICLE_H

#include <OgreSceneNode.h>

#include "ParticleAffector.h"

class ParticleAffector;



class Particle
{
public:
    Particle( Ogre::SceneNode* node );
    virtual ~Particle();

    virtual void Update();
    //virtual void UpdateDebug();

    virtual void SetVisible( const bool visible );
    virtual bool IsVisible() const;

    void AddAffector( ParticleAffector* affector );

    float GetCurrentTTL() const;

protected:
    Particle();

protected:
    Ogre::SceneNode* m_SceneNode;
    Ogre::SceneNode* m_ModelNode;
    Ogre::Entity* m_Model;

    std::vector< ParticleAffector* > m_Affectors;

    Ogre::Vector3 m_Position;
    Ogre::Vector3 m_Direction;
    float m_CurrentTTL;
    float m_DefaultTTL;
};



#endif // PARTICLE_H
