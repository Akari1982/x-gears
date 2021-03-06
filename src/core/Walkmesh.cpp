#include "Walkmesh.h"

#include "ConfigVar.h"
#include "DebugDraw.h"
#include "Logger.h"



Walkmesh::Walkmesh()
{
}



Walkmesh::~Walkmesh()
{
}



void
Walkmesh::UpdateDebug()
{
    DEBUG_DRAW.SetScreenSpace( true );
    DEBUG_DRAW.SetTextAlignment( DEBUG_DRAW.CENTER );

    for( size_t i = 0; i < m_Triangles.size(); ++i )
    {
        if( m_Triangles[ i ].access_side[ 0 ] == -1 || m_Triangles[ i ].locked == true || m_Triangles[ m_Triangles[ i ].access_side[ 0 ] ].locked == true )
        {
            DEBUG_DRAW.SetColour( Ogre::ColourValue( 1, 0, 0, 1 ) );
        }
        else
        {
            DEBUG_DRAW.SetColour( Ogre::ColourValue( 1, 1, 1, 1 ) );
        }
        DEBUG_DRAW.Line3d( m_Triangles[ i ].a, m_Triangles[ i ].b );

        if( m_Triangles[ i ].access_side[ 1 ] == -1 || m_Triangles[ i ].locked == true || m_Triangles[ m_Triangles[ i ].access_side[ 1 ] ].locked == true )
        {
            DEBUG_DRAW.SetColour( Ogre::ColourValue( 1, 0, 0, 1 ) );
        }
        else
        {
            DEBUG_DRAW.SetColour( Ogre::ColourValue( 1, 1, 1, 1 ) );
        }
        DEBUG_DRAW.Line3d( m_Triangles[ i ].b, m_Triangles[ i ].c );

        if( m_Triangles[ i ].access_side[ 2 ] == -1 || m_Triangles[ i ].locked == true || m_Triangles[ m_Triangles[ i ].access_side[ 2 ] ].locked == true )
        {
            DEBUG_DRAW.SetColour( Ogre::ColourValue( 1, 0, 0, 1 ) );
        }
        else
        {
            DEBUG_DRAW.SetColour( Ogre::ColourValue( 1, 1, 1, 1 ) );
        }
        DEBUG_DRAW.Line3d( m_Triangles[ i ].c, m_Triangles[ i ].a );

        DEBUG_DRAW.SetColour( Ogre::ColourValue( 1, 1, 1, 1 ) );
        DEBUG_DRAW.SetFadeDistance( 400, 500 );
        Ogre::Vector3 triangle_pos = ( m_Triangles[ i ].a + m_Triangles[ i ].b + m_Triangles[ i ].c) / 3;
        DEBUG_DRAW.Text( triangle_pos, 0, 0, Ogre::StringConverter::toString( m_Triangles[ i ].material ) );
    }
}



void
Walkmesh::AddTriangle( const WalkmeshTriangle& triangle )
{
    m_Triangles.push_back( triangle );
}



int
Walkmesh::GetAccessSide( unsigned int triangle_id, unsigned char side ) const
{
    if( triangle_id >= m_Triangles.size() )
    {
        LOG_ERROR( "Triangle_id greater than number of triangles in walkmesh or less than zero." );
        return -1;
    }

    if( side >= 3 )
    {
        LOG_ERROR( "Side greater than 2. Side indexed from 0 to 2." );
        return -1;
    }

    return m_Triangles[ triangle_id ].access_side[ side ];
}



const Ogre::Vector3&
Walkmesh::GetA( unsigned int triangle_id ) const
{
    if( triangle_id >= m_Triangles.size() )
    {
        LOG_ERROR( "Triangle_id greater than number of triangles in walkmesh or less than zero." );
        return Ogre::Vector3::ZERO;
    }

    return m_Triangles[ triangle_id ].a;
}



const Ogre::Vector3&
Walkmesh::GetB( unsigned int triangle_id ) const
{
    if( triangle_id >= m_Triangles.size() )
    {
        LOG_ERROR( "Triangle_id greater than number of triangles in walkmesh or less than zero." );
        return Ogre::Vector3::ZERO;
    }

    return m_Triangles[ triangle_id ].b;
}



const Ogre::Vector3&
Walkmesh::GetC( unsigned int triangle_id ) const
{
    if( triangle_id >= m_Triangles.size() )
    {
        LOG_ERROR( "Triangle_id greater than number of triangles in walkmesh or less than zero." );
        return Ogre::Vector3::ZERO;
    }

    return m_Triangles[ triangle_id ].c;
}



size_t
Walkmesh::GetNumberOfTriangles() const
{
    return m_Triangles.size();
}



void
Walkmesh::LockWalkmesh( unsigned int triangle_id, bool lock )
{
    if( triangle_id >= m_Triangles.size() )
    {
        LOG_ERROR( "Triangle_id greater than number of triangles in walkmesh or less than zero." );
        return;
    }

    m_Triangles[ triangle_id ].locked = lock;
}



bool
Walkmesh::IsLocked( unsigned int triangle_id ) const
{
    if( triangle_id >= m_Triangles.size() )
    {
        LOG_ERROR( "Triangle_id greater than number of triangles in walkmesh or less than zero." );
        return false;
    }

    return m_Triangles[ triangle_id ].locked;
}
