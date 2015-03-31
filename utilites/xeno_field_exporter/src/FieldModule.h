#ifndef FIELD_MODULE_H
#define FIELD_MODULE_H

#include <OgreString.h>



class FieldModule
{
public:
    FieldModule();
    virtual ~FieldModule();
    void LoadMap( const Ogre::String& file );

    void Update();
};



#endif // FIELD_MODULE_H
