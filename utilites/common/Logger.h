#ifndef LOGGER_H
#define LOGGER_H

#include <OgreString.h>
#include <OgreLogManager.h>
#include <OgreUTFString.h>



#define LOG_ERROR( message ) Ogre::LogManager::getSingleton().logMessage( "[ERROR] " + Ogre::String( __FILE__ ) + " " + Ogre::StringConverter::toString( __LINE__ ) + ": " + message, Ogre::LML_CRITICAL )
#define LOG_WARNING( message ) Ogre::LogManager::getSingleton().logMessage( "[WARNING] " + Ogre::String( __FILE__ ) + " " + Ogre::StringConverter::toString( __LINE__ ) + ": " + message, Ogre::LML_NORMAL )
#define LOG_TRIVIAL( message ) Ogre::LogManager::getSingleton().logMessage( message, Ogre::LML_TRIVIAL )



Ogre::String HexToString( int value, unsigned short width, char fill );
Ogre::String BoolToString( bool value );
Ogre::String IntToString( int value );
Ogre::String FloatToString( float value );



class Logger
{
public:
    explicit Logger( const Ogre::String& logFileName );
    virtual ~Logger();

    void     Log( const Ogre::String& text );
    void     LogW( const Ogre::UTFString& text );
    void     Log( std::vector<unsigned char>& text );

private:
    Ogre::String m_LogFile;
};



extern Logger *LOGGER;



#endif // LOGGER_H
