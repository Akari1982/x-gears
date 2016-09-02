#ifndef ENTITY_MANAGER_H
#define ENTITY_MANAGER_H

#include <OgreSingleton.h>

#include "Event.h"
#include "Entity.h"
#include "EntityTrigger.h"
#include "Walkmesh.h"



class EntityManager : public Ogre::Singleton< EntityManager >
{
public:
    EntityManager();
    virtual ~EntityManager();

    void Input( const Event& event );
    void Update();
    void UpdateDebug();
    void OnResize();

    void Clear();

    void AddWalkmesh( Walkmesh* walkmesh );

    void AddEntity( const Ogre::String& name, const Ogre::String& file_name, const Ogre::Vector3& position, const Ogre::Degree& direction );
    void AddSquareTrigger( const Ogre::String& name, const Ogre::Vector3& point1, const Ogre::Vector3& point2, const Ogre::Vector3& point3, const Ogre::Vector3& point4, const bool enabled );

private:
    bool                          m_Paused;

    std::vector< Walkmesh* >      m_Walkmesh;

    std::vector< Entity* >        m_Entity;
    std::vector< EntityTrigger* > m_EntityTriggers;

    Ogre::SceneNode*              m_SceneNode;

    Ogre::Entity*                 m_Grid;
    Ogre::Entity*                 m_Axis;
};



#endif // ENTITY_MANAGER_H
