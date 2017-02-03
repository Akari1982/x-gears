#include <OgreStringConverter.h>

#include "ConfigCmdManager.h"
#include "ConfigVarManager.h"
#include "EntityManager.h"
#include "Logger.h"
#include "XmlMapFile.h"
#include "XmlMapsFile.h"



void
CmdMap( const Ogre::StringVector& params )
{
    if( params.size() != 2 )
    {
        Console::getSingleton().AddTextToOutput( "Usage: /map [map_id]" );
        return;
    }

    EntityManager::getSingleton().Clear();

    XmlMapsFile xml( "./data/maps.xml" );
    Ogre::String file_name = xml.GetMapFileNameByName( params[ 1 ] );

    XmlMapFile xml_map( "./data/" + file_name );
    xml_map.LoadMap();
}



void
CmdMapCompletion( Ogre::StringVector& complete_params )
{
    XmlMapsFile xml( "./data/maps.xml" );
    xml.GetMapNames( complete_params );
}



void
CmdSprite( const Ogre::StringVector& params )
{
    if( params.size() != 2 )
    {
        Console::getSingleton().AddTextToOutput( "Usage: /sprite [sprite_name]" );
        return;
    }

    EntityManager::getSingleton().AddSprite( params[ 1 ] );
}



void
EntityManager::InitCmd()
{
    AddCommand( "map", "Run game module", "", CmdMap, CmdMapCompletion );
    AddCommand( "sprite", "debug sprite", "", CmdSprite, NULL );
}
