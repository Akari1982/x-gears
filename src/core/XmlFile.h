#ifndef XML_FILE_H
#define XML_FILE_H

#include <OgreString.h>

#include "library/tinyxml/tinyxml.h"



class XmlFile
{
public:
    XmlFile( const Ogre::String& file );
    virtual ~XmlFile();

protected:
    bool m_NormalFile;

    TiXmlDocument m_File;
};



#endif // XML_FILE_H
