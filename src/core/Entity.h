#ifndef ENTITY_H
#define ENTITY_H

#include <OgreString.h>

#include "EntityCollision.h"
#include "EntityDirection.h"


class Entity
{
public:
    Entity( const Ogre::String& name, Ogre::SceneNode* node );
    virtual ~Entity();

    virtual void UpdateDebug();

    const Ogre::String& GetName() const;

    void SetModel( const Ogre::String file_name );

    void ScriptInitPC( const int character_id );
    void ScriptInitNPC( const int character_id );
    void ScriptInput();

    void SetPosition( const Ogre::Vector3& position );
    const Ogre::Vector3 GetPosition() const;

    void SetRotation( const Ogre::Degree& rotation );
    Ogre::Degree GetRotation() const;

    void SetVisible( const bool visible );
    bool IsVisible() const;

    void SetSolidRadius( const float radius );
    float GetSolidRadius() const;
    void SetSolid( const bool solid );
    bool IsSolid() const;

    void SetWalkmeshId( const int walkmesh_id );
    int GetWalkmeshId() const;
    void SetTriangleId( const int triangle_id );
    int GetTriangleId() const;

    bool IsPlayer() const;
    bool IsMove() const;

private:
    Entity();

protected:
    Ogre::String m_Name;

    Ogre::SceneNode* m_SceneNode;

    Ogre::Entity* m_Model;

    Ogre::SceneNode* m_SolidCollisionNode;
    EntityCollision* m_SolidCollision;
    Ogre::SceneNode* m_DirectionNode;
    EntityDirection* m_Direction;

    float m_SolidRadius;
    bool m_Solid;

    int m_WalkmeshId;
    int m_TriangleId;

    bool m_Player;
    bool m_Move;

    Ogre::Degree m_RotationY;
    float m_SizeY;
};



#endif // ENTITY_H
