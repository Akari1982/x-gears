#ifndef ENTITY_H
#define ENTITY_H

#include <OgreString.h>



class Entity
{
public:
                         Entity( const Ogre::String& name, Ogre::SceneNode* node );
    virtual              ~Entity();

    virtual void         Update();
    virtual void         UpdateDebug();

    const Ogre::String&  GetName() const;

    void                 SetPosition( const Ogre::Vector3& position );
    const Ogre::Vector3  GetPosition() const;

    void                 SetRotation( const Ogre::Degree& rotation );
    Ogre::Degree         GetRotation() const;

    virtual void         SetVisible( const bool visible ) = 0;
    virtual bool         IsVisible() const = 0;

private:
    Entity();

protected:
    Ogre::String            m_Name;

    Ogre::SceneNode*        m_SceneNode;
    Ogre::SceneNode*        m_ModelNode;
};



#endif // ENTITY_H
