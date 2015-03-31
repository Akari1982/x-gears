#ifndef ENTITY_TRIGGER_H
#define ENTITY_TRIGGER_H

#include <OgreRoot.h>

class Entity;



class EntityTrigger
{
public:
    EntityTrigger( const Ogre::String& name );
    virtual ~EntityTrigger();

    void UpdateDebug();

    const Ogre::String& GetName() const;

    void SetEnabled( const bool enabled );
    bool IsEnabled() const;

    void CheckTrigger( Entity* entity, Ogre::Vector3& position );

    void AddActivator( Entity* activator );
    void RemoveActivator( Entity* activator );
    bool IsActivator( Entity* activator );

    void SetLineTrigger( const Ogre::Vector3& point1, const Ogre::Vector3& point2 );
    void SetSquareTrigger( const Ogre::Vector3& point1, const Ogre::Vector3& point2, const Ogre::Vector3& point3, const Ogre::Vector3& point4 );

private:
    enum TriggerType
    {
        TT_NONE = 0,
        TT_LINE,
        TT_SQUARE
    };

    Ogre::String m_Name;
    TriggerType m_Type;
    bool m_Enabled;

    std::vector< Entity* > m_Activators;

    Ogre::Vector3 m_Point1;
    Ogre::Vector3 m_Point2;
    Ogre::Vector3 m_Point3;
    Ogre::Vector3 m_Point4;
};



#endif // ENTITY_TRIGGER_H
