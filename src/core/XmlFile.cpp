#include "XmlFile.h"

#include <OgreStringConverter.h>

#include "Logger.h"



XmlFile::XmlFile( const Ogre::String& file ):
    m_File( file.c_str() )
{
    m_File.SetCondenseWhiteSpace( false );
    m_NormalFile = m_File.LoadFile();

    if( m_NormalFile == false )
    {
        LOG_ERROR( "Can't open " + file + ". TinyXml Error: " + m_File.ErrorDesc() );
    }
}



XmlFile::~XmlFile()
{
}
