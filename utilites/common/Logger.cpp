#include "Logger.h"
#include "FileSystem.h"

#include <OgreStringConverter.h>



Logger* LOGGER = NULL; // global and accessable from anywhere in our program



Ogre::String
HexToString( int value, unsigned short width, char fill )
{
    std::stringstream stream;
    stream.width( width );
    stream.fill( fill );
    stream.setf( std::ios::hex, std::ios::basefield );
    stream << value;
    return stream.str();
}



Ogre::String
BoolToString( bool value )
{
    return Ogre::StringConverter::toString( value );
}



Ogre::String
IntToString( int value )
{
    return Ogre::StringConverter::toString( value );
}



Ogre::String
FloatToString( float value )
{
    return Ogre::StringConverter::toString( value );
}



Logger::Logger( const Ogre::String& logFileName ):
    m_LogFile( logFileName ),
    m_BufferFill( 0 )
{
    FILESYSTEM->RemoveFile( m_LogFile );
}



Logger::~Logger()
{
    Flush();
}



void
Logger::Log( const Ogre::String& text )
{
    for( unsigned int i = 0; i < text.size(); ++i )
    {
        if( m_BufferFill == 4096 )
        {
            Flush();
        }

        m_Buffer[ m_BufferFill ] = text[ i ];
        ++m_BufferFill;
    }
}



void
Logger::LogW( const Ogre::UTFString& text )
{
    FILESYSTEM->WriteFile( m_LogFile, text.c_str(), text.size() * 2 );
}



void
Logger::Log( std::vector< unsigned char >& text )
{
    unsigned char* temp = new unsigned char[ text.size() ];
    for( unsigned int i = 0; i < text.size(); ++i )
    {
        temp[ i ] = text[ i ];
    }

    FILESYSTEM->WriteFile( m_LogFile, temp, text.size() );

    delete[] temp;
}



void
Logger::Flush()
{
    FILESYSTEM->WriteFile( m_LogFile, m_Buffer, m_BufferFill );
    m_BufferFill = 0;
}
