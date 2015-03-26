#ifndef PARTICLE_H
#define PARTICLE_H



class Particle
{
public:
    Particle( Ogre::SceneNode* node );
    virtual ~Particle();

    virtual void Update();
    virtual void UpdateDebug();

protected:
    Particle();

protected:
    Ogre::SceneNode* m_SceneNode;
    Ogre::SceneNode* m_ModelNode;
    Ogre::Entity* m_Model;

    Ogre::Vector3 m_Position;
    Ogre::Vector3 m_Direction;
    float m_CurrentTTL;
    float m_DefaultTTL;
};



#endif // PARTICLE_H
