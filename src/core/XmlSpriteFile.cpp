#include "XmlSpriteFile.h"

#include "EntityManager.h"
#include "Logger.h"
#include "Utilites.h"




XmlSpriteFile::XmlSpriteFile( const Ogre::String& file ):
    XmlFile( file )
{
}



XmlSpriteFile::~XmlSpriteFile()
{
}



void
XmlSpriteFile::Load( Sprite* sprite )
{
    TiXmlNode* node = m_File.RootElement();

    if( node == NULL || node->ValueStr() != "sprite" )
    {
        LOG_ERROR( "XmlSpriteFile: " + m_File.ValueStr() + " is not a valid sprite file! No <sprite> in root." );
        return;
    }

    node = node->FirstChild();
    while( node != NULL )
    {
        if( node->Type() == TiXmlNode::TINYXML_ELEMENT && node->ValueStr() == "frame" )
        {
            Sprite::Frame frame;
            TiXmlNode* node2 = node->FirstChild();
            while( node2 != NULL )
            {
                if( node2->Type() == TiXmlNode::TINYXML_ELEMENT && node2->ValueStr() == "tile" )
                {
                    Sprite::Tile tile;
                    tile.x = GetInt( node2, "x" );
                    tile.y = GetInt( node2, "y" );
                    tile.u = GetInt( node2, "u" );
                    tile.v = GetInt( node2, "v" );
                    tile.width = GetInt( node2, "width" );
                    tile.height = GetInt( node2, "height" );
                    frame.tile.push_back( tile );
                }
                node2 = node2->NextSibling();
            }
            sprite->AddFrame( frame );
        }
        node = node->NextSibling();
    }
}
