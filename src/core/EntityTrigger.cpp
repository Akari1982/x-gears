#include "EntityTrigger.h"

#include "DebugDraw.h"
#include "Entity.h"
#include "ConfigVar.h"



ConfigVar cv_debug_trigger( "debug_trigger", "Draw entity trigger debug info", "0" );



EntityTrigger::EntityTrigger( const Ogre::String& name ):
    m_Name( name ),
    m_Type( TT_NONE ),
    m_Enabled( false ),
    m_Point1( Ogre::Vector3::ZERO ),
    m_Point2( Ogre::Vector3::ZERO ),
    m_Point3( Ogre::Vector3::ZERO ),
    m_Point4( Ogre::Vector3::ZERO )
{
}



EntityTrigger::~EntityTrigger()
{
}



void
EntityTrigger::UpdateDebug()
{
    if( cv_debug_trigger.GetB() == true )
    {
        if( m_Enabled == false )
        {
            DEBUG_DRAW.SetColour( Ogre::ColourValue( 0.5f, 0.5f, 0.5f ) );
        }
        else if( m_Activators.size() > 0 )
        {
            DEBUG_DRAW.SetColour( Ogre::ColourValue( 0.04f, 0.9f, 0.5f ) );
        }
        else
        {
            DEBUG_DRAW.SetColour( Ogre::ColourValue( 0.04f, 0.5f, 0.9f ) );
        }

        Ogre::Vector3 center;

        switch( m_Type )
        {
            case TT_LINE:
            {
                DEBUG_DRAW.Line3d( m_Point1, m_Point2 );

                DEBUG_DRAW.SetColour( Ogre::ColourValue::White );
                DEBUG_DRAW.SetScreenSpace( true );
                DEBUG_DRAW.SetTextAlignment( DEBUG_DRAW.CENTER );
                DEBUG_DRAW.SetFadeDistance( 30, 40 );

                center = m_Point2 - ( ( m_Point2 - m_Point1 ) / 2 );
            }
            break;

            case TT_SQUARE:
            {
                DEBUG_DRAW.Line3d( m_Point1, m_Point2 );
                DEBUG_DRAW.Line3d( m_Point2, m_Point3 );
                DEBUG_DRAW.Line3d( m_Point3, m_Point4 );
                DEBUG_DRAW.Line3d( m_Point4, m_Point1 );

                center = m_Point3 - ( ( m_Point3 - m_Point1 ) / 2 );
            }
            break;
        }

        DEBUG_DRAW.SetColour( Ogre::ColourValue::White );
        DEBUG_DRAW.SetScreenSpace( true );
        DEBUG_DRAW.SetTextAlignment( DEBUG_DRAW.CENTER );
        DEBUG_DRAW.SetFadeDistance( 30, 40 );
        DEBUG_DRAW.Text( center, 0, 0, m_Name );

        DEBUG_DRAW.SetColour( Ogre::ColourValue( 0.04f, 0.9f, 0.5f ) );
        for( size_t i = 0; i < m_Activators.size(); ++i )
        {
            DEBUG_DRAW.Text( center, 0, ( i + 1 ) * 16, m_Activators[ i ]->GetName() );
        }
    }
}



const Ogre::String&
EntityTrigger::GetName() const
{
    return m_Name;
}



void
EntityTrigger::SetEnabled( const bool enabled )
{
    m_Enabled = enabled;

    if( enabled == false )
    {
        m_Activators.clear();
    }
}



bool
EntityTrigger::IsEnabled() const
{
    return m_Enabled;
}



void
EntityTrigger::CheckTrigger( Entity* entity, Ogre::Vector3& position )
{
    if( entity->IsSolid() == false )
    {
        return;
    }

    ScriptEntity* scr_entity = ScriptManager::getSingleton().GetScriptEntityByName( ScriptManager::ENTITY, m_Name );

    if( scr_entity != NULL && m_Enabled == true )
    {
        switch( m_Type )
        {
            case TT_LINE:
            {
            Ogre::Vector3 mp1 = entity->GetPosition();
            Ogre::Vector3 proj;

            // calculate distance
            float square_dist = SquareDistanceToLine( mp1, m_Point1, m_Point2, proj );
            float solid = entity->GetSolidRadius();

            if( square_dist != -1 && square_dist < solid * solid )
            {
                if( IsActivator( entity ) == false )
                {
                    bool added = ScriptManager::getSingleton().ScriptRequest( scr_entity, "on_enter_line", 1, entity->GetName(), "", false, false );
                    if( added == false )
                    {
                        LOG_WARNING( "Script \"on_enter_line\" for entity \"" + m_Name + "\" doesn't exist." );
                    }
                    AddActivator( entity );
                }

                // check that 1st and 2nd points are on different side of line
                float cond1 = ( ( m_Point2.x - m_Point1.x ) * ( mp1.y - m_Point1.y ) ) - ( ( mp1.x - m_Point1.x ) * ( m_Point2.y - m_Point1.y ) );
                float cond2 = ( ( m_Point2.x - m_Point1.x ) * ( position.y - m_Point1.y ) ) - ( ( position.x - m_Point1.x ) * ( m_Point2.y - m_Point1.y ) );

                // if we cross the line
                if( ( cond1 > 0 && cond2 <= 0 ) || ( cond2 > 0 && cond1 <= 0 ) || ( cond1 >= 0 && cond2 < 0 ) || ( cond2 >= 0 && cond1 < 0 ) )
                {
                    bool added = ScriptManager::getSingleton().ScriptRequest( scr_entity, "on_cross_line", 1, entity->GetName(), "", false, false );
                    if( added == false )
                    {
                        LOG_WARNING( "Script \"on_cross_line\" for entity \"" +  m_Name + "\" doesn't exist." );
                    }
                }

                // if we not move in line
                if( mp1 == position )
                {
                    bool added = ScriptManager::getSingleton().ScriptRequest( scr_entity, "on_move_to_line", 1, entity->GetName(), "", false, false );
                    if( added == false )
                    {
                        LOG_WARNING( "Script \"on_move_to_line\" for entity \"" +  m_Name + "\" doesn't exist." );
                    }
                }
                else
                {
                    const Ogre::Degree direction_to_line = GetDirectionToPoint( mp1, proj );
                    const Ogre::Degree movement_direction = GetDirectionToPoint( mp1, position );

                    // if we move to line
                    Ogre::Degree angle = direction_to_line - movement_direction + Ogre::Degree( 90 );
                    angle = ( angle > Ogre::Degree( 360 ) ) ? angle - Ogre::Degree( 360 ) : angle;

                    if( angle < Ogre::Degree( 180 ) && angle > Ogre::Degree( 0 ) )
                    {
                        bool added = ScriptManager::getSingleton().ScriptRequest( scr_entity, "on_move_to_line", 1, entity->GetName(), "", false, false );
                        if( added == false )
                        {
                            LOG_WARNING( "Script \"on_move_to_line\" for entity \"" +  m_Name + "\" doesn't exist." );
                        }
                    }
                }
            }
            else
            {
                if( IsActivator( entity ) == true )
                {
                    bool added = ScriptManager::getSingleton().ScriptRequest( scr_entity, "on_leave_line", 1, entity->GetName(), "", false, false );
                    if( added == false )
                    {
                        LOG_WARNING( "Script \"on_leave_line\" for entity \"" +  m_Name + "\" doesn't exist." );
                    }
                    RemoveActivator( entity );
                }
            }
        }
        break



        case TT_SQUARE:
        {
        }
        break;
    }
}



void
EntityTrigger::AddActivator( Entity* activator )
{
    // add only if this activator don't exist
    size_t i = 0;
    for( ; i < m_Activators.size(); ++i )
    {
        if( m_Activators[ i ] == activator )
        {
            break;
        }
    }
    if( i == m_Activators.size() )
    {
        m_Activators.push_back( activator );
    }
}



void
EntityTrigger::RemoveActivator( Entity* activator )
{
    for( size_t i = 0; i < m_Activators.size(); ++i )
    {
        if( m_Activators[ i ] == activator )
        {
            m_Activators.erase( m_Activators.begin() + i );
            return;
        }
    }
}



bool
EntityTrigger::IsActivator( Entity* activator )
{
    for( size_t i = 0; i < m_Activators.size(); ++i )
    {
        if( m_Activators[ i ] == activator )
        {
            return true;
        }
    }

    return false;
}



void
EntityTrigger::SetLineTrigger( const Ogre::Vector3& point1, const Ogre::Vector3& point2 )
{
    m_Type = TT_LINE;
    m_Point1 = point1;
    m_Point2 = point2;
}



void
EntityTrigger::SetSquareTrigger( const Ogre::Vector3& point1, const Ogre::Vector3& point2, const Ogre::Vector3& point3, const Ogre::Vector3& point4 )
{
    m_Type = TT_SQUARE;
    m_Point1 = point1;
    m_Point2 = point2;
    m_Point3 = point3;
    m_Point4 = point4;
}
