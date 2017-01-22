#ifndef XML_SPRITE_FILE_H
#define XML_SPRITE_FILE_H

#include "Sprite.h"
#include "XmlFile.h"



class XmlSpriteFile : public XmlFile
{
public:
    XmlSpriteFile( const Ogre::String& file );
    virtual ~XmlSpriteFile();

    void Load( Sprite* sprite );
};



#endif // XML_SPRITE_FILE_H
