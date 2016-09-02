#include "XmlWalkmeshFile.h"

#include "EntityManager.h"
#include "Logger.h"
#include "Utilites.h"
#include "Walkmesh.h"



XmlWalkmeshFile::XmlWalkmeshFile( const Ogre::String& file ):
    XmlFile( file )
{
}



XmlWalkmeshFile::~XmlWalkmeshFile()
{
}



void
XmlWalkmeshFile::Load()
{
    TiXmlNode* node = m_File.RootElement();

    if( node == NULL || node->ValueStr() != "walkmesh" )
    {
        LOG_ERROR( "Field XML Manager: " + m_File.ValueStr() + " is not a valid walkmesh file! No <walkmesh> in root." );
        return;
    }

    node = node->FirstChild();
    while( node != NULL )
    {
        if( node->Type() == TiXmlNode::TINYXML_ELEMENT && node->ValueStr() == "block" )
        {
            Walkmesh* walkmesh = new Walkmesh();
            TiXmlNode* node2 = node->FirstChild();
            while( node2 != NULL )
            {
                if( node2->Type() == TiXmlNode::TINYXML_ELEMENT && node2->ValueStr() == "triangle" )
                {
                    WalkmeshTriangle triangle;

                    triangle.a = GetVector3( node2, "a" );
                    triangle.b = GetVector3( node2, "b" );
                    triangle.c = GetVector3( node2, "c" );

                    triangle.access_side[ 0 ] = GetInt( node2, "a_b" );
                    triangle.access_side[ 1 ] = GetInt( node2, "b_c" );
                    triangle.access_side[ 2 ] = GetInt( node2, "c_a" );

                    triangle.material = GetInt( node2, "material" );

                    walkmesh->AddTriangle( triangle );
                }
                node2 = node2->NextSibling();
            }
            EntityManager::getSingleton().AddWalkmesh( walkmesh );
        }
        node = node->NextSibling();
    }
}
