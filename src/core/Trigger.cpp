#include "Trigger.h"

#include "ConfigVar.h"
#include "DebugDraw.h"
#include "Logger.h"



ConfigVar cv_debug_trigger( "debug_trigger", "Draw trigger debug info", "0" );



Trigger::Trigger( const Ogre::String& name ):
    m_Name( name ),
    m_Point1( Ogre::Vector3::ZERO ),
    m_Point2( Ogre::Vector3::ZERO ),
    m_Point3( Ogre::Vector3::ZERO ),
    m_Point4( Ogre::Vector3::ZERO )
{
}



Trigger::~Trigger()
{
}



void
Trigger::UpdateDebug()
{
    if( cv_debug_trigger.GetB() == true )
    {
        DEBUG_DRAW.SetColour( Ogre::ColourValue( 0.04f, 0.5f, 0.9f ) );

        DEBUG_DRAW.Line3d( m_Point1, m_Point2 );
        DEBUG_DRAW.Line3d( m_Point2, m_Point3 );
        DEBUG_DRAW.Line3d( m_Point3, m_Point4 );
        DEBUG_DRAW.Line3d( m_Point4, m_Point1 );

        Ogre::Vector3 center = m_Point3 - ( ( m_Point3 - m_Point1 ) / 2 );

        DEBUG_DRAW.SetColour( Ogre::ColourValue::White );
        DEBUG_DRAW.SetScreenSpace( true );
        DEBUG_DRAW.SetTextAlignment( DEBUG_DRAW.CENTER );
        DEBUG_DRAW.SetFadeDistance( 30, 40 );
        DEBUG_DRAW.Text( center, 0, 0, m_Name );
    }
}



const Ogre::String&
Trigger::GetName() const
{
    return m_Name;
}



void
Trigger::SetSquareTrigger( const Ogre::Vector3& point1, const Ogre::Vector3& point2, const Ogre::Vector3& point3, const Ogre::Vector3& point4 )
{
    m_Point1 = point1;
    m_Point2 = point2;
    m_Point3 = point3;
    m_Point4 = point4;
}
