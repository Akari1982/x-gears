#include "ScriptManager.h"
#include "ScriptManagerBinds.h"
#include "ScriptManagerCommands.h"

#include "ConfigVar.h"
#include "DebugDraw.h"
#include "Logger.h"
#include "Timer.h"
#include "Utilites.h"
extern "C"
{
    #include "library/lua/lua.h"
    #include "library/lua/lualib.h"
    #include "library/lua/lauxlib.h"
}
#include "library/luabind/luabind.hpp"
#include "library/luabind/yield_policy.hpp"



ConfigVar cv_debug_script( "debug_script", "Debug script", "false" );



bool
priority_queue_compare( QueueScript a, QueueScript b )
{
    return a.priority < b.priority;
}



template<>ScriptManager *Ogre::Singleton< ScriptManager >::ms_Singleton = NULL;



ScriptManager::ScriptManager():
    m_SystemTableName( "System" ),
    m_EntityTableName( "EntityContainer" ),
    m_UiTableName( "UiContainer" )
{
    LOG_TRIVIAL( "ScriptManager started." );

    m_LuaState = lua_open();
    luabind::open( m_LuaState );
    luaopen_base( m_LuaState );
    luaopen_string( m_LuaState );
    luaopen_table( m_LuaState );
    luaopen_math( m_LuaState );

    InitBinds();
    InitCmd();

    RunFile( "system/system.lua" );
    AddEntity( ScriptManager::SYSTEM, "MapChanger" );
}



ScriptManager::~ScriptManager()
{
    lua_close( m_LuaState );

    LOG_TRIVIAL( "ScriptManager closed." );
}



void
ScriptManager::Input( const Event& event )
{
    if( ( event.type == ET_KEY_PRESS || event.type == ET_KEY_REPEAT ) &&
                                      (
                                        event.param1 == OIS::KC_RETURN ||
                                        event.param1 == OIS::KC_LEFT ||
                                        event.param1 == OIS::KC_RIGHT ||
                                        event.param1 == OIS::KC_DOWN ||
                                        event.param1 == OIS::KC_UP ||
                                        event.param1 == OIS::KC_A ||
                                        event.param1 == OIS::KC_S ||
                                        event.param1 == OIS::KC_X ||
                                        event.param1 == OIS::KC_Z
                                      ) )
    {
        for( size_t i = 0; i < m_UiScriptEntity.size(); ++i )
        {
            Ogre::String argument2 = "";
            if( event.type == ET_KEY_PRESS )
            {
                argument2 = "Press";
            }
            else if( event.type == ET_KEY_REPEAT )
            {
                argument2 = "Repeat";
            }
            ScriptRequest( &m_UiScriptEntity[ i ], "on_button", 100, KeyToString( ( OIS::KeyCode )event.param1 ), argument2, false, false );
        }
    }
}



void
ScriptManager::Update( const ScriptManager::Type type )
{
    // select requested type
    std::vector< ScriptEntity >* se_pointer = NULL;
    switch( type )
    {
        case ScriptManager::SYSTEM: se_pointer = &m_SystemScriptEntity; break;
        case ScriptManager::ENTITY: se_pointer = &m_EntityScriptEntity; break;
        case ScriptManager::UI: se_pointer = &m_UiScriptEntity; break;
        default: return;
    }



    // resort all queue. This will give us correct info for debug draw.
    for( unsigned int i = 0; i < ( *se_pointer ).size(); ++i )
    {
        if( ( *se_pointer )[ i ].queue.size() > 0 )
        {

            if( ( *se_pointer )[ i ].resort == true )
            {
                std::stable_sort( ( *se_pointer )[ i ].queue.begin(), ( *se_pointer )[ i ].queue.end(), priority_queue_compare );
                ( *se_pointer )[ i ].resort = false;
            }
        }
    }



    // draw debug before update. This way it will be posible to see scripts that run once
    if( cv_debug_script.GetB() == true )
    {
        DEBUG_DRAW.SetTextAlignment( DEBUG_DRAW.LEFT );
        DEBUG_DRAW.SetScreenSpace( true );
        DEBUG_DRAW.SetColour( Ogre::ColourValue( 0.8, 0.8, 0, 1 ) );
        DEBUG_DRAW.Text( 10, 34, "Script entity:" );

        for( unsigned int i = 0; i < ( *se_pointer ).size(); ++i )
        {
            Ogre::String text = ( *se_pointer )[ i ].name;

            unsigned int queue_size = ( *se_pointer )[ i ].queue.size();
            if( queue_size > 0 )
            {
                text += ": ";
                DEBUG_DRAW.SetColour( Ogre::ColourValue( 0.8, 0.8, 0, 1 ) );
            }
            else
            {
                DEBUG_DRAW.SetColour( Ogre::ColourValue( 0.5, 0.5, 0.5, 1 ) );
            }
            for( unsigned int j = 0; j < queue_size; ++j )
            {
                if( j > 0 )
                {
                    text += ", ";
                }
                text += "(" + Ogre::StringConverter::toString( ( *se_pointer )[ i ].queue[ j ].priority ) + ")" + ( *se_pointer )[ i ].queue[ j ].function;

                if( ( *se_pointer )[ i ].queue[ j ].wait == true )
                {
                    if( ( *se_pointer )[ i ].queue[ j ].seconds_to_wait != 0 )
                    {
                        text += ":wait( " + Ogre::StringConverter::toString( ( *se_pointer )[ i ].queue[ j ].seconds_to_wait ) + " )";
                    }
                }
            }

            DEBUG_DRAW.Text( 20, 50 + i * 16, text );
        }
    }



    for( unsigned int i = 0; i < ( *se_pointer ).size(); ++i )
    {
        if( ( *se_pointer )[ i ].queue.size() > 0 )
        {
            m_CurrentScriptId.entity = ( *se_pointer )[ i ].name;
            m_CurrentScriptId.function = ( *se_pointer )[ i ].queue[ 0 ].function;

            if( ( *se_pointer )[ i ].queue[ 0 ].wait == false )
            {
                if( ( *se_pointer )[ i ].queue[ 0 ].yield == false)
                {
                    LOG_TRIVIAL( "[SCRIPT] Start script \"" + m_CurrentScriptId.function + "\" for entity \"" + m_CurrentScriptId.entity + "\"." );

                    if( ( *se_pointer )[ i ].queue[ 0 ].paused_script_start.entity != "" )
                    {
                        ContinueScriptExecution( ( *se_pointer )[ i ].queue[ 0 ].paused_script_start );
                        ( *se_pointer )[ i ].queue[ 0 ].paused_script_start.entity = "";
                    }

                    luabind::object table = GetTableByEntityName( m_CurrentScriptId.entity, ( *se_pointer )[ i ].queue[ 0 ].state );

                    if( table.is_valid() &&
                        luabind::type( table ) == LUA_TTABLE &&
                        luabind::type( table[ m_CurrentScriptId.function ] ) == LUA_TFUNCTION )
                    {
                        int ret = 0;

                        try
                        {
                            ret = luabind::resume_function< int >( table[ m_CurrentScriptId.function ], table, ( *se_pointer )[ i ].queue[ 0 ].argument1.c_str(), ( *se_pointer )[ i ].queue[ 0 ].argument2.c_str() );
                        }
                        catch( luabind::error& e )
                        {
                            luabind::object error_msg( luabind::from_stack( e.state(), -1 ) );
                            LOG_WARNING( Ogre::String( luabind::object_cast< std::string >( error_msg ) ) );
                        }

                        if( ret == 0 )
                        {
                            LOG_TRIVIAL( "[SCRIPT] Script \"" + m_CurrentScriptId.function + "\" for entity \"" + m_CurrentScriptId.entity + "\" finished." );
                            if( ( *se_pointer )[ i ].queue[ 0 ].function != "on_update" )
                            {
                                RemoveEntityTopScript( ( *se_pointer )[ i ] );
                            }
                        }
                        else if( ret == 1 )
                        {
                            LOG_TRIVIAL( "[SCRIPT] Script \"" + m_CurrentScriptId.function + "\" for entity \"" + m_CurrentScriptId.entity + "\" not paused and will be continued next cycle." );
                            ( *se_pointer )[ i ].queue[ 0 ].yield = true;
                        }
                        else
                        {
                            LOG_TRIVIAL( "[SCRIPT] Script \"" + m_CurrentScriptId.function + "\" for entity \"" + m_CurrentScriptId.entity + "\" not finished yet." );
                            ( *se_pointer )[ i ].queue[ 0 ].yield = true;
                            ( *se_pointer )[ i ].queue[ 0 ].wait = true;
                        }
                    }
                    else
                    {
                        LOG_WARNING( "Script \"" + m_CurrentScriptId.function + "\" for entity \"" + m_CurrentScriptId.entity + "\" doesn't exist." );
                        RemoveEntityTopScript( ( *se_pointer )[ i ] );
                    }
                }
                else
                {
                    LOG_TRIVIAL( "[SCRIPT] Continue function \"" + m_CurrentScriptId.function + "\" for entity \"" + m_CurrentScriptId.entity + "\"." );

                    int ret = 0;

                    try
                    {
                        ret = luabind::resume< int >( ( *se_pointer )[ i ].queue[ 0 ].state );
                    }
                    catch( luabind::error& e )
                    {
                        luabind::object error_msg( luabind::from_stack( e.state(), -1 ) );
                        LOG_WARNING( Ogre::String( luabind::object_cast< std::string >( error_msg ) ) );
                    }

                    if( ret == 0 ) // finished
                    {
                        LOG_TRIVIAL( "[SCRIPT] Script \"" + m_CurrentScriptId.function + "\" for entity \"" + m_CurrentScriptId.entity + "\" finished." );

                        // stop yield for on_update
                        ( *se_pointer )[ i ].queue[ 0 ].yield = false;

                        if( ( *se_pointer )[ i ].queue[ 0 ].function != "on_update" )
                        {
                            RemoveEntityTopScript( ( *se_pointer )[ i ] );
                        }
                    }
                    else if (ret == 1)
                    {
                        LOG_TRIVIAL( "[SCRIPT] Script \"" + m_CurrentScriptId.function + "\"for entity \"" + m_CurrentScriptId.entity + "\" not paused and will be continued next cycle." );
                    }
                    else
                    {
                        LOG_TRIVIAL( "[SCRIPT] Script \"" + m_CurrentScriptId.function + "\" for entity \"" + m_CurrentScriptId.entity + "\" not finished yet." );
                        ( *se_pointer )[ i ].queue[ 0 ].wait = true;
                    }
                }
            }
            else if( ( *se_pointer )[ i ].queue[ 0 ].seconds_to_wait > 0 )
            {
                ( *se_pointer )[ i ].queue[ 0 ].seconds_to_wait -= Timer::getSingleton().GetGameTimeDelta();
                ( *se_pointer )[ i ].queue[ 0 ].seconds_to_wait = ( ( *se_pointer )[ i ].queue[ 0 ].seconds_to_wait < 0 ) ? 0 : ( *se_pointer )[ i ].queue[ 0 ].seconds_to_wait;

                if( ( *se_pointer )[ i ].queue[ 0 ].seconds_to_wait == 0 )
                {
                    ( *se_pointer )[ i ].queue[ 0 ].wait = false;
                }
            }
        }
    }
}



void
ScriptManager::RunString( const Ogre::String& lua )
{
    if( luaL_dostring( m_LuaState, lua.c_str() ) == 1 )
    {
        luabind::object error_msg( luabind::from_stack( m_LuaState, -1 ) );
        LOG_WARNING( Ogre::String( luabind::object_cast< std::string >( error_msg ) ) );
    }
}



void
ScriptManager::RunFile( const Ogre::String& file )
{
    if( luaL_dofile( m_LuaState, ( "./data/" + file ).c_str() ) == 1 )
    {
        luabind::object error_msg( luabind::from_stack( m_LuaState, -1 ) );
        LOG_WARNING( Ogre::String( luabind::object_cast< std::string >( error_msg ) ) );
    }
}



void
ScriptManager::AddEntity( const ScriptManager::Type type, const Ogre::String& entity_name )
{
    // select requested type
    std::vector< ScriptEntity >* se_pointer = NULL;
    Ogre::String name = "";
    switch( type )
    {
        case ScriptManager::SYSTEM: se_pointer = &m_SystemScriptEntity; name = m_SystemTableName + "." + entity_name; break;
        case ScriptManager::ENTITY: se_pointer = &m_EntityScriptEntity; name = m_EntityTableName + "." + entity_name; break;
        case ScriptManager::UI: se_pointer = &m_UiScriptEntity; name = m_UiTableName + "." + entity_name; break;
        default: return;
    }

    for( unsigned int i = 0; i < ( *se_pointer ).size(); ++i )
    {
        if( ( *se_pointer )[ i ].name == name )
        {
            LOG_ERROR( "Script entity \"" + name + "\" already exist in script manager." );
            return;
        }
    }

    luabind::object table = GetTableByEntityName( name, m_LuaState );
    if( table.is_valid() && luabind::type( table ) == LUA_TTABLE )
    {
        ScriptEntity script_entity;
        script_entity.name = name;

        // check "on_start" script
        if( luabind::type( table[ "on_start" ] ) == LUA_TFUNCTION )
        {
            QueueScript script;
            script.function = "on_start";
            script.priority = 0;
            script.state = lua_newthread( m_LuaState );
            // we dont want thread to be garbage collected so we store it
            script.state_id = luaL_ref( m_LuaState, LUA_REGISTRYINDEX );
            script.seconds_to_wait = 0;
            script.wait = false;
            script.yield = false;
            script_entity.queue.push_back( script );
        }

        // check "on_update" script
        if( luabind::type( table[ "on_update" ] ) == LUA_TFUNCTION )
        {
            QueueScript script;
            script.function = "on_update";
            script.priority = 999;
            script.state = lua_newthread( m_LuaState );
            // we dont want thread to be garbage collected so we store it
            script.state_id = luaL_ref( m_LuaState, LUA_REGISTRYINDEX );
            script.seconds_to_wait = 0;
            script.wait = false;
            script.yield = false;
            script_entity.queue.push_back( script );
        }

        ( *se_pointer ).push_back( script_entity );
    }
}



void
ScriptManager::RemoveEntity( const ScriptManager::Type type, const Ogre::String& entity_name )
{
    // select requested type
    std::vector< ScriptEntity >* se_pointer = NULL;
    Ogre::String name = "";
    switch( type )
    {
        case ScriptManager::SYSTEM: se_pointer = &m_SystemScriptEntity; name = m_SystemTableName + "." + entity_name; break;
        case ScriptManager::ENTITY: se_pointer = &m_EntityScriptEntity; name = m_EntityTableName + "." + entity_name; break;
        case ScriptManager::UI: se_pointer = &m_UiScriptEntity; name = m_UiTableName + "." + entity_name; break;
        default: return;
    }

    for( unsigned int i = 0; i < ( *se_pointer ).size(); ++i )
    {
        if( ( *se_pointer )[ i ].name == name )
        {
            while( ( *se_pointer )[ i ].queue.size() > 0 )
            {
                ScriptManager::RemoveEntityTopScript( ( *se_pointer )[ i ] );
            }

            ( *se_pointer ).erase( ( *se_pointer ).begin() + i );

            return;
        }
    }
}



void
ScriptManager::RemoveEntityTopScript( ScriptEntity& entity )
{
    if( entity.queue.size() > 0 )
    {
        // delete thread
        luaL_unref( m_LuaState, LUA_REGISTRYINDEX, entity.queue[ 0 ].state_id );

        if( entity.queue[ 0 ].paused_script_end.entity != "" )
        {
            ContinueScriptExecution( entity.queue[ 0 ].paused_script_end );
            entity.queue[ 0 ].paused_script_end.entity = "";
        }

        entity.queue.erase( entity.queue.begin() );
    }
}



luabind::object
ScriptManager::GetTableByEntityName( const Ogre::String& name, lua_State* state ) const
{
    // get real table by name
    Ogre::StringVector table_path = StringTokenise( name, "." );
    luabind::object table = luabind::globals( state );
    for( size_t i = 0; i < table_path.size(); ++i )
    {
        table = table[ table_path[ i ] ];

        if( luabind::type( table ) != LUA_TTABLE )
        {
            return luabind::object();
        }
    }

    return table;
}



QueueScript*
ScriptManager::GetScriptByScriptId( const ScriptId& script ) const
{
    for( unsigned int i = 0; i < m_SystemScriptEntity.size(); ++i )
    {
        if( script.entity == m_SystemScriptEntity[ i ].name )
        {
            for( unsigned int j = 0; j < m_SystemScriptEntity[ i ].queue.size(); ++j )
            {
                if( script.function == m_SystemScriptEntity[ i ].queue[ j ].function )
                {
                    return (QueueScript*) &( m_SystemScriptEntity[ i ].queue[ j ] );
                }
            }

            return NULL;
        }
    }

    for( unsigned int i = 0; i < m_EntityScriptEntity.size(); ++i )
    {
        if( script.entity == m_EntityScriptEntity[ i ].name )
        {
            for( unsigned int j = 0; j < m_EntityScriptEntity[ i ].queue.size(); ++j )
            {
                if( script.function == m_EntityScriptEntity[ i ].queue[ j ].function )
                {
                    return (QueueScript*) &( m_EntityScriptEntity[ i ].queue[ j ] );
                }
            }

            return NULL;
        }
    }

    for( unsigned int i = 0; i < m_UiScriptEntity.size(); ++i )
    {
        if( script.entity == m_UiScriptEntity[ i ].name )
        {
            for( unsigned int j = 0; j < m_UiScriptEntity[ i ].queue.size(); ++j )
            {
                if( script.function == m_UiScriptEntity[ i ].queue[ j ].function )
                {
                    return (QueueScript*) &( m_UiScriptEntity[ i ].queue[ j ] );
                }
            }

            return NULL;
        }
    }

    return NULL;
}



ScriptEntity*
ScriptManager::GetScriptEntityByName( const Type type, const Ogre::String& entity_name ) const
{
    // select requested type
    const std::vector< ScriptEntity >* se_pointer = NULL;
    Ogre::String name = "";
    switch( type )
    {
        case ScriptManager::SYSTEM: se_pointer = &m_SystemScriptEntity; name = m_SystemTableName + "." + entity_name; break;
        case ScriptManager::ENTITY: se_pointer = &m_EntityScriptEntity; name = m_EntityTableName + "." + entity_name; break;
        case ScriptManager::UI: se_pointer = &m_UiScriptEntity; name = m_UiTableName + "." + entity_name; break;
        default: return NULL;
    }

    for( size_t i = 0; i < ( *se_pointer ).size(); ++i )
    {
        if( ( *se_pointer )[ i ].name == name )
        {
            return ( ScriptEntity* ) &( ( *se_pointer )[ i ] );
        }
    }

    return NULL;
}



const ScriptId
ScriptManager::GetCurrentScriptId() const
{
    return m_CurrentScriptId;
}



void
ScriptManager::ContinueScriptExecution( const ScriptId& script )
{
    QueueScript* script_pointer = GetScriptByScriptId( script );

    if( script_pointer == NULL )
    {
        LOG_ERROR( "There is no script \"" + script.function + "\" for entity \"" + script.entity + "\". Can't continue script execution." );
        return;
    }

    script_pointer->wait = false;
}



int
ScriptManager::ScriptWait( const float seconds )
{
    LOG_TRIVIAL( "script:wait: We set script wait for " + Ogre::StringConverter::toString( seconds ) + " seconds." );

    QueueScript* script = GetScriptByScriptId( m_CurrentScriptId );

    if( script == NULL )
    {
        LOG_ERROR( "script:wait: Currently no any script running." );
        return 1;
    }

    if( seconds == 0 )
    {
        return 1;
    }

    script->seconds_to_wait = seconds;

    return -1;
}



void
ScriptManager::ScriptRequest( const Type type, const char* entity, const char* function, const int priority )
{
    LOG_TRIVIAL( "[SCRIPT] script:request: Request function \"" + Ogre::String( function ) + "\" for entity \"" + Ogre::String( entity ) + "\" with priority " + Ogre::StringConverter::toString( priority ) + "." );

    ScriptEntity* script_entity = GetScriptEntityByName( type, Ogre::String( entity ) );

    if( script_entity == NULL )
    {
        LOG_WARNING( "[SCRIPT] script:request: Entity \"" + Ogre::String( entity ) + "\" doesn't exist." );
        return;
    }

    bool added = ScriptRequest( script_entity, function, priority, "", "", false, false );

    if( added == false )
    {
        LOG_WARNING( "Script '" + Ogre::String( function ) + "' for entity '" +  Ogre::String( entity ) + "' doesn't exist." );
    }
}



int
ScriptManager::ScriptRequestStartSync( const Type type, const char* entity, const char* function, const int priority )
{
    LOG_TRIVIAL( "[SCRIPT] script:request_start_sync: Request function \"" + Ogre::String( function ) + "\" for entity \"" + Ogre::String( entity ) + "\" with priority " + Ogre::StringConverter::toString( priority ) + "." );

    ScriptEntity* script_entity = GetScriptEntityByName( type, Ogre::String( entity ) );

    if( script_entity == NULL )
    {
        LOG_ERROR( "[SCRIPT] script:request_start_sync: Entity \"" + Ogre::String( entity ) + "\" doesn't exist." );
        return 1;
    }

    bool added = ScriptRequest( script_entity, function, priority, "", "", true, false );

    if( added == false )
    {
        LOG_WARNING( "Script '" + Ogre::String( function ) + "' for entity '" +  Ogre::String( entity ) + "' doesn't exist." );
        return 1;
    }

    return -1;
}



int
ScriptManager::ScriptRequestEndSync( const Type type, const char* entity, const char* function, const int priority )
{
    LOG_TRIVIAL( "[SCRIPT] script:request_end_sync: Request function \"" + Ogre::String( function ) + "\" for entity \"" + Ogre::String( entity ) + "\" with priority " + Ogre::StringConverter::toString( priority ) + "." );

    ScriptEntity* script_entity = GetScriptEntityByName( type, Ogre::String( entity ) );

    if( script_entity == NULL )
    {
        LOG_ERROR( "[SCRIPT] script:request_end_sync: Entity \"" + Ogre::String( entity ) + "\" doesn't exist." );
        return 1;
    }

    bool added = ScriptRequest( script_entity, function, priority, "", "", false, true );

    if( added == false )
    {
        LOG_WARNING( "Script '" + Ogre::String( function ) + "' for entity '" +  Ogre::String( entity ) + "' doesn't exist." );
        return 1;
    }

    return -1;
}



bool
ScriptManager::ScriptRequest( ScriptEntity* script_entity, const Ogre::String& function, const int priority, const Ogre::String& argument1, const Ogre::String& argument2, bool start_sync, bool end_sync )
{
    luabind::object table = GetTableByEntityName( script_entity->name, m_LuaState );
    if( table.is_valid() && luabind::type( table ) == LUA_TTABLE && luabind::type( table[ function ] ) == LUA_TFUNCTION )
    {
        QueueScript script;
        script.function = function;
        script.argument1 = argument1;
        script.argument2 = argument2;
        script.priority = priority;
        script.state = lua_newthread( m_LuaState );
        // we dont want thread to be garbage collected so we store it
        script.state_id = luaL_ref( m_LuaState, LUA_REGISTRYINDEX );
        script.seconds_to_wait = 0;
        script.wait = false;
        script.yield = false;
        if( start_sync == true )
        {
            script.paused_script_start = GetCurrentScriptId();
        }
        if( end_sync == true )
        {
            script.paused_script_end = GetCurrentScriptId();
        }
        script_entity->queue.push_back( script );
        script_entity->resort = true;

        return true;
    }

    return false;
}



void
ScriptManager::AddValueToStack( const float value )
{
    QueueScript* script = GetScriptByScriptId( m_CurrentScriptId );
    if( script != NULL )
    {
        lua_pushnumber( script->state, value );
    }
}
