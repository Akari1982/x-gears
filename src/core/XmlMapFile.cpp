#include "XmlMapFile.h"

#include "EntityManager.h"
#include "Logger.h"
#include "ScriptManager.h"
#include "TextManager.h"
#include "Utilites.h"
#include "XmlWalkmeshFile.h"



XmlMapFile::XmlMapFile( const Ogre::String& file ):
    XmlFile( file )
{
}



XmlMapFile::~XmlMapFile()
{
}



void
XmlMapFile::LoadMap()
{
    TiXmlNode* node = m_File.RootElement();

    if( node == NULL || node->ValueStr() != "map" )
    {
        LOG_ERROR( m_File.ValueStr() + " is not a valid fields map file! No <map> in root." );
        return;
    }

    node = node->FirstChild();
    while( node != NULL )
    {
        if( node->Type() == TiXmlNode::TINYXML_ELEMENT && node->ValueStr() == "walkmesh" )
        {
            Ogre::String name = GetString( node, "file_name" );
            if( name != "" )
            {
                XmlWalkmeshFile file( "./data/" + name );
                file.Load();
            }
        }
        else if( node->Type() == TiXmlNode::TINYXML_ELEMENT && node->ValueStr() == "entity" )
        {
            Ogre::String name = GetString( node, "name" );
            if( name == "" )
            {
                LOG_ERROR( "There is no name specified for <entity> tag." );
                continue;
            }
            Ogre::String file_name = GetString( node, "file_name", "" );
            Ogre::Vector3 position = GetVector3( node, "position", Ogre::Vector3::ZERO );
            Ogre::Degree direction = Ogre::Degree( GetFloat( node, "direction" ) );
            bool script = GetBool( node, "script", false );

            EntityManager::getSingleton().AddEntity( name, file_name, position, direction, script );
        }
        else if( node->Type() == TiXmlNode::TINYXML_ELEMENT && node->ValueStr() == "square_trigger" )
        {
            Ogre::String name = GetString( node, "name" );
            if( name == "" )
            {
                LOG_ERROR( "There is no name specified for <square_trigger> tag." );
                continue;
            }

            Ogre::Vector3 point1 = GetVector3( node, "point1", Ogre::Vector3::ZERO );
            Ogre::Vector3 point2 = GetVector3( node, "point2", Ogre::Vector3::ZERO );
            Ogre::Vector3 point3 = GetVector3( node, "point3", Ogre::Vector3::ZERO );
            Ogre::Vector3 point4 = GetVector3( node, "point4", Ogre::Vector3::ZERO );
            bool enabled = GetBool( node, "enabled", false );

            EntityManager::getSingleton().AddSquareTrigger( name, point1, point2, point3, point4, enabled );
        }
        else if( node->Type() == TiXmlNode::TINYXML_ELEMENT && node->ValueStr() == "script" )
        {
            Ogre::String file_name = GetString( node, "file_name" );
            if( file_name != "" )
            {
                ScriptManager::getSingleton().RunFile( file_name );
            }
        }

        node = node->NextSibling();
    }
}
