#include "Console.h"
#include "Logger.h"
#include "Entity.h"
#include "EntityManager.h"
#include "Timer.h"
#include "UiManager.h"
#include "UiWidget.h"
#include "XmlMapFile.h"
#include "XmlMapsFile.h"



void
ScriptPrint( const char* text )
{
    Console::getSingleton().AddTextToOutput( text );
}



void
ScriptMap( const char* text )
{
    EntityManager::getSingleton().Clear();

    XmlMapsFile xml( "./data/maps.xml" );
    Ogre::String file_name = xml.GetMapFileNameByName( text );

    XmlMapFile xml_map( "./data/" + file_name );
    xml_map.LoadMap();
}



void
ScriptConsole( const char* text )
{
    Console::getSingleton().ExecuteCommand( text );
}



void
ScriptManager::InitBinds()
{
    // globals
    luabind::module( m_LuaState )
    [
        luabind::def( "print", ( void( * )( const char* ) ) &ScriptPrint ),
        luabind::def( "map", ( void( * )( const char* ) ) &ScriptMap ),
        luabind::def( "console", ( void( * )( const char* ) ) &ScriptConsole )
    ];

    // entity access
    luabind::module( m_LuaState )
    [
        luabind::class_< Entity >( "Entity" )
            .def( "init_pc", ( void( Entity::* )( const int ) ) &Entity::ScriptInitPC )
            .def( "input", ( void( Entity::* )() ) &Entity::ScriptInput )
    ];

    // ui widget access
    luabind::module( m_LuaState )
    [
        luabind::class_< UiWidget >( "UiWidget" )
            .def( "set_visible", ( void( UiWidget::* )( const bool ) ) &UiWidget::SetVisible )
            .def( "is_visible", ( bool( UiWidget::* )() ) &UiWidget::IsVisible )
            .def( "play_animation", ( void( UiWidget::* )( const char* ) ) &UiWidget::ScriptPlayAnimation )
            .def( "play_animation_stop", ( void( UiWidget::* )( const char* ) ) &UiWidget::ScriptPlayAnimationStop )
            .def( "play_animation", ( void( UiWidget::* )( const char*, const float, const float ) ) &UiWidget::ScriptPlayAnimation )
            .def( "play_animation_stop", ( void( UiWidget::* )( const char*, const float, const float ) ) &UiWidget::ScriptPlayAnimationStop )
            .def( "set_default_animation", ( void( UiWidget::* )( const char* ) ) &UiWidget::ScriptSetDefaultAnimation )
            .def( "animation_sync", ( int( UiWidget::* )() ) &UiWidget::ScriptAnimationSync, luabind::yield )
            .def( "set_colour", ( void( UiWidget::* )( const float, const float, const float ) ) &UiWidget::SetColour )
            .def( "set_alpha", ( void( UiWidget::* )( const float ) ) &UiWidget::SetAlpha )
            .def( "set_x", ( void( UiWidget::* )( const float, const float ) ) &UiWidget::SetX )
            .def( "set_y", ( void( UiWidget::* )( const float, const float ) ) &UiWidget::SetY )
            .def( "set_z", ( void( UiWidget::* )( const float ) ) &UiWidget::SetZ )
            .def( "set_width", ( void( UiWidget::* )( const float, const float ) ) &UiWidget::SetWidth )
            .def( "set_height", ( void( UiWidget::* )( const float, const float ) ) &UiWidget::SetHeight )

    ];

    // ui access
    luabind::module( m_LuaState )
    [
        luabind::class_< UiManager >( "UiManager" )
            .def( "get_widget", ( UiWidget*( UiManager::* )( const char* ) ) &UiManager::ScriptGetWidget )
    ];

    // timer access
    luabind::module( m_LuaState )
    [
        luabind::class_< Timer >( "Timer" )
            .def( "get_game_time_total", ( float( Timer::* )() ) &Timer::GetGameTimeTotal )
            .def( "set_timer", ( float( Timer::* )( const float ) ) &Timer::SetGameTimer )
            .def( "get_timer", ( int( Timer::* )() ) &Timer::GetGameTimer )
    ];

    // script access
    luabind::module( m_LuaState )
    [
        luabind::class_< ScriptManager >( "Script" )
            .def( "wait", ( int( ScriptManager::* )( const float ) ) &ScriptManager::ScriptWait, luabind::yield )
            .def( "request", ( void( ScriptManager::* )( const ScriptManager::Type, const char*, const char*, const int ) ) &ScriptManager::ScriptRequest )
            .def( "request_start_sync", ( int( ScriptManager::* )( const ScriptManager::Type, const char*, const char*, const int ) ) &ScriptManager::ScriptRequestStartSync, luabind::yield )
            .def( "request_end_sync", ( int( ScriptManager::* )( const ScriptManager::Type, const char*, const char*, const int ) ) &ScriptManager::ScriptRequestEndSync, luabind::yield )
            .enum_( "constants" )
            [
                luabind::value( "SYSTEM", ScriptManager::SYSTEM ),
                luabind::value( "ENTITY", ScriptManager::ENTITY ),
                luabind::value( "UI", ScriptManager::UI )
            ]
    ];

    luabind::globals( m_LuaState )[ "ui_manager" ] = boost::ref( *( UiManager::getSingletonPtr() ) );
    luabind::globals( m_LuaState )[ "timer" ] = boost::ref( *( Timer::getSingletonPtr() ) );
    luabind::globals( m_LuaState )[ "script" ] = boost::ref( *this );
}
