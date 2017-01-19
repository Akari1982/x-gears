#ifndef SPRITE_H
#define SPRITE_H

#include <OgreString.h>



class Sprite
{
public:
    Sprite( const Ogre::String& name );
    virtual ~Sprite();

    void UpdateDebug();

protected:
};



#endif // SPRITE_H
