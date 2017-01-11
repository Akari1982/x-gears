#include "SpawnPoint.h"

#include "DebugDraw.h"



SpawnPoint::SpawnPoint( const Ogre::String& name, const Ogre::Vector2& position, const int walkmesh_id ):
    m_Name( name ),
    m_Position( position ),
    m_WalkmeshId( walkmesh_id )
{
}



SpawnPoint::~SpawnPoint()
{
}



void
SpawnPoint::UpdateDebug()
{
    DEBUG_DRAW.SetColour( Ogre::ColourValue::White );
    Ogre::Vector3 point1 = Ogre::Vector3( m_Position.x, 20, m_Position.y );
    Ogre::Vector3 point2 = Ogre::Vector3( m_Position.x, -20, m_Position.y );
    DEBUG_DRAW.Line3d( point1, point2 );
    DEBUG_DRAW.SetTextAlignment( DEBUG_DRAW.CENTER );
    DEBUG_DRAW.SetFadeDistance( 30, 40 );
    DEBUG_DRAW.Text( Ogre::Vector3( m_Position.x, 0, m_Position.y ), 0, 0, "Spawn:" + m_Name + " (" +  Ogre::StringConverter::toString( m_WalkmeshId ) + ")" );
}



const Ogre::String&
SpawnPoint::GetName() const
{
    return m_Name;
}



const Ogre::Vector2&
SpawnPoint::GetPosition() const
{
    return m_Position;
}



int
SpawnPoint::GetWalkmeshId() const
{
    return m_WalkmeshId;
}
