#ifndef SPAWN_POINT_H
#define SPAWN_POINT_H

#include <OgreString.h>
#include <OgreVector2.h>



class SpawnPoint
{
public:
    SpawnPoint( const Ogre::String& name, const Ogre::Vector2& position, const int walkmesh_id );
    virtual ~SpawnPoint();

    void UpdateDebug();

    const Ogre::String& GetName() const;
    const Ogre::Vector2& GetPosition() const;
    int GetWalkmeshId() const;

protected:
    Ogre::String m_Name;
    Ogre::Vector2 m_Position;
    int m_WalkmeshId;
    int m_CameraRotation;
    int m_EntityRotation;
};



#endif // SPAWN_POINT_H
