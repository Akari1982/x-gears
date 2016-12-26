#include "ScriptFile.h"
#include "Utilites.h"
#include "../../common/Logger.h"



ScriptFile::ScriptFile( File *pFile ):
    File( pFile )
{
}



ScriptFile::~ScriptFile()
{
}




void
ScriptFile::GetScripts( const int file_id )
{
    Logger* export_script = new Logger( "exported/maps/field/" + GetFieldName( file_id ) + ".lua" );
    export_script->Log( "Entity = {}\n\n\n\n" );

    u32 number_of_entity = GetU8( 0x80 );
    u32 offset_to_script = 0x84 + number_of_entity * 0x40;

    for( u32 i = 0; i < number_of_entity; ++i )
    {
        export_script->Log( "Entity[ \"" + IntToString( i ) + "\" ] = {\n" );

        for( u8 j = 0; j < 0x20; ++j )
        {

            u32 offset_in_script = GetU16LE( 0x84 + i * 0x40 + j * 2 );
            if( offset_in_script == 0 )
            {
                break;
            }

            if( j == 0 )
            {
                export_script->Log( "    on_start = function( self )\n" );
            }
            else if( j == 1 )
            {
                export_script->Log( "    on_update = function( self )\n" );
            }
            else if( j == 2 )
            {
                export_script->Log( "    on_talk = function( self )\n" );
            }
            else if( j == 3 )
            {
                export_script->Log( "    on_push = function( self )\n" );
            }
            else
            {
                export_script->Log( "    script_0x" + HexToString( j, 2, '0' ) + " = function( self )\n" );
            }



            u32 script_pointer_end = 0;
            for( u32 l = i; l < number_of_entity; ++l )
            {
                u32 offset_in_next_script = 0;
                for( int script_id = 0; script_id < 0x20; ++script_id )
                {
                    if( l == i && script_id <= j )
                    {
                        continue;
                    }

                    offset_in_next_script = GetU16LE( 0x84 + l * 0x40 + script_id * 2 );

                    if( offset_in_next_script == 0 )
                    {
                        continue;
                    }
                    else if( offset_in_script == offset_in_next_script )
                    {
                        offset_in_next_script = 0;
                        continue;
                    }

                    break;
                }

                if( offset_in_next_script != 0 )
                {
                    script_pointer_end = offset_in_next_script + offset_to_script;
                    break;
                }
            }
            if( script_pointer_end == 0 )
            {
                script_pointer_end = m_BufferSize;
            }

            u32 script_pointer = offset_to_script + offset_in_script;

            for( ; script_pointer < script_pointer_end; )
            {
                Ogre::String address = "0x" + HexToString( script_pointer - offset_to_script, 4, '0' );
                export_script->Log( "        " );


                u8 opcode = GetU8(script_pointer);
                script_pointer += 1;

                if( opcode == 0x00 )
                {
                    export_script->Log( "return;" );
                }
                else if( opcode == 0x01 )
                {
                    export_script->Log( "-- 0x01_JumpTo( 0x" + HexToString( GetU16LE( script_pointer ), 4, '0' ) + " );" );
                    script_pointer += 2;
                }
                else if( opcode == 0x02 )
                {
                    export_script->Log( "-- 0x02_ConditionalJumpTo( " );
                    u8 flag = GetU8( script_pointer + 4 );
                    switch( flag & 0xf0 )
                    {
                        case 0x00:
                        {
                            export_script->Log( "value1=" + GetVVariable( script_pointer + 0 ) + ", " );
                            export_script->Log( "value2=" + GetVVariable( script_pointer + 2 ) + ", " );
                        }
                        break;
                        case 0x40:
                        {
                            export_script->Log( "value1=" + GetVVariable( script_pointer + 0 ) + ", " );
                            export_script->Log( "value2=" + GetS16Variable( script_pointer + 2 ) + ", " );
                        }
                        break;
                        case 0x80:
                        {
                            export_script->Log( "value1=" + GetS16Variable( script_pointer + 0 ) + ", " );
                            export_script->Log( "value2=" + GetVVariable( script_pointer + 2 ) + ", " );
                        }
                        break;
                        case 0xc0:
                        {
                            export_script->Log( "value1=" + GetS16Variable( script_pointer + 0 ) + ", " );
                            export_script->Log( "value2=" + GetS16Variable( script_pointer + 2 ) + ", " );
                        }
                        break;
                    }
                    export_script->Log( "condition=\"" );
                    switch( flag & 0x0f )
                    {
                        case 0x00: export_script->Log( "value1 == value2" ); break;
                        case 0x01: export_script->Log( "value1 != value2" ); break;
                        case 0x02: export_script->Log( "value1 > value2" ); break;
                        case 0x03: export_script->Log( "value1 < value2" ); break;
                        case 0x04: export_script->Log( "value1 >= value2" ); break;
                        case 0x05: export_script->Log( "value1 <= value2" ); break;
                        case 0x06: export_script->Log( "value1 & value2" ); break;
                        case 0x07: export_script->Log( "value1 != value2" ); break;
                        case 0x08: export_script->Log( "value1 | value2" ); break;
                        case 0x09: export_script->Log( "value1 & value2" ); break;
                        case 0x0A: export_script->Log( "(0 NOR value1) & value2" ); break;
                    }
                    export_script->Log("\", jump_if_false=" + GetU16Variable( script_pointer + 5 ) + " );" );
                    script_pointer += 7;
                }
                else if( opcode == 0x0b )
                {
                    export_script->Log("-- 0x0B_EntityNPCSpriteInit( sprite_id=" + GetV80Variable( script_pointer ) + " );");
                    script_pointer += 2;
                }
                else if( opcode == 0x0c )
                {
                    export_script->Log( "-- 0x0C_Encounter();" );
                }
                else if (opcode == 0x16)
                {
                    export_script->Log( "entity:init_pc( " + GetV80Variable( script_pointer ) + " );" );
                    script_pointer += 2;
                }
                else if( opcode == 0x19 )
                {
                    export_script->Log( "-- 0x19_SetPosition( x=" + GetVF80Variable( script_pointer ) + ", z=" + GetVF40Variable( script_pointer + 2 ) + ", flag=" + GetFVariable( script_pointer + 5 ) + " )");
                    script_pointer += 5;
                }
                else if( opcode == 0x26 )
                {
                    export_script->Log( "-- 0x26_Wait( time=" + GetV80Variable( script_pointer ) + " );" );
                    script_pointer += 2;
                }
                else if( opcode == 0x2a )
                {
                    export_script->Log( "-- 0x2A();");
                }
                else if( opcode == 0x84 )
                {
                    export_script->Log( "-- 0x84_ProgressLessEqualJumpTo( value=" + GetV80Variable( script_pointer ) + ", jump=" + GetU16Variable( script_pointer + 2 ) + " );" );
                    script_pointer += 4;
                }
                else if( opcode == 0x86 )
                {
                    export_script->Log( "-- 0x86_ProgressNotEqualJumpTo( value=" + GetV80Variable( script_pointer ) + ", jump=" + GetU16Variable( script_pointer + 2 ) + " );" );
                    script_pointer += 4;
                }
                else if( opcode == 0xbc )
                {
                    export_script->Log("-- 0xBC_EntityNoModelInit();");
                }
                else if( opcode == 0xcb )
                {
                    export_script->Log( "-- 0xCB_TriggerJumpTo( trigger_id=" + GetV80Variable( script_pointer ) + ", jump=" + GetU16Variable( script_pointer + 2 ) + " );" );
                    script_pointer += 4;
                }
                else if( opcode == 0xfe )
                {
                    u8 eo_opcode = GetU8( script_pointer );
                    script_pointer += 1;

                    if( eo_opcode == 0x0D )
                    {
                        export_script->Log( "-- 0xFE0D_SetAvatar( character_id=" + GetV80Variable( script_pointer ) + " );" );
                        script_pointer += 2;
                    }
                    else
                    {
                        export_script->Log( "-- MISSING OPCODE 0xFE" + HexToString( eo_opcode, 2, '0' ) + "\n" );
                        break;
                    }
                }

/*
                else if (opcode == 0x20)
                {
                    LOGGER->Log("0x20_SetFlags");
                    GetV80Variable(script_pointer, "flags");
                    LOGGER->Log("; // set some flags for movement and collision.\n");
                }
                else if (opcode == 0x23)
                {
                    LOGGER->Log("0x23(); // add flag 0020 in 80114f2c + 58 of current entity.\n");
                }
                else if (opcode == 0x29)
                {
                    LOGGER->Log("0x29_EntityTurnOff");
                    GetEVariable(script_pointer);
                    LOGGER->Log("; // turn entity off (script will not be runned, close dialog from this entity and so on).\n");
                }
                else if (opcode == 0x69)
                {
                    LOGGER->Log("0x69_SetRotation");
                    GetV80Variable(script_pointer, "rotation");
                    LOGGER->Log(";\n");
                }
                else if (opcode == 0x6B)
                {
                    LOGGER->Log("0x6B_RotateClockwise");
                    GetV80Variable(script_pointer, "rotation");
                    LOGGER->Log(";\n");
                }
                else if (opcode == 0x6C)
                {
                    LOGGER->Log("0x6C_RotateAntiClockwise");
                    GetV80Variable(script_pointer, "rotation");
                    LOGGER->Log(";\n");
                }
                else if (opcode == 0x6F)
                {
                    LOGGER->Log("0x6F_RotateToEntity");
                    GetEVariable(script_pointer);
                    LOGGER->Log(";\n");
                }
                else if (opcode == 0xC4)
                {
                    LOGGER->Log("0xC4_DoorOpen(0x%02x); // 0 - clockwise, 1 - anticlockwise\n", GetU8(script_pointer));
                    script_pointer += 1;
                }
                else if (opcode == 0xC5)
                {
                    LOGGER->Log("0xC5_DoorClose(0x%02x); // 0 - clockwise, 1 - anticlockwise\n", GetU8(script_pointer));
                    script_pointer += 1;
                }
                else if (opcode == 0xD2)
                {
                    LOGGER->Log("0xD2_DialogShow");
                    GetU16Variable(script_pointer, "dialog_id");
                    GetU8Variable(script_pointer, "flags");
                    LOGGER->Log(";\n", GetU16LE(script_pointer));
                }
/*
                if (opcode == 0x10)
                {
                    u8 flag = GetU8(o + 1);

                    if (flag == 0)
                    {
                        size = 9;
                    }
                    else
                    {
                        size = 2;
                    }
                    LOGGER->Log("\t%s", opcodes_names[opcode].c_str());
                }
                else if (opcode == 0x57)
                {
                    u8 flag = GetU8(o + 1);
                    if ((flag & 3) == 0 || (flag & 3) == 1 || (flag & 3) == 2)
                    {
                        size = 0xB;
                    }
                    else
                    {
                        size = 0x2;
                    }
                    LOGGER->Log("\t%s", opcodes_names[opcode].c_str());
                }
*/
                else
                {
                    export_script->Log( "-- MISSING OPCODE 0x" + HexToString( opcode, 2, '0' ) + "\n" );
                    break;
                }

                export_script->Log( " -- " + address + " 0x" + HexToString( opcode, 2, '0' ) + "\n" );
            }

            export_script->Log( "    end,\n\n" );
        }

        export_script->Log( "}\n\n\n\n" );
    }
}



Ogre::String
ScriptFile::GetEVariable( const u32 script_pointer )
{
    return "(entity)0x" + HexToString( GetU8( script_pointer ), 2, '0' );
}



Ogre::String
ScriptFile::GetFVariable( const u32 script_pointer )
{
    return "(flag)0x" + HexToString( GetU8( script_pointer ), 2, '0' );
}



Ogre::String
ScriptFile::GetU8Variable( const u32 script_pointer )
{
    return "0x" + HexToString( GetU8( script_pointer ), 2, '0' );
}



Ogre::String
ScriptFile::GetS16Variable( const u32 script_pointer )
{
    return "(s16)0x" + HexToString( GetU16LE( script_pointer ), 4, '0' );
}



Ogre::String
ScriptFile::GetU16Variable( const u32 script_pointer )
{
    return "0x" + HexToString( GetU16LE( script_pointer ), 4, '0' );
}



Ogre::String
ScriptFile::GetVF40Variable( const u32 script_pointer )
{
    return "(vf40)0x" + HexToString( GetU16LE( script_pointer ), 4, '0' );
}



Ogre::String
ScriptFile::GetVF80Variable( const u32 script_pointer )
{
    return "(vf80)0x" + HexToString( GetU16LE( script_pointer ), 4, '0' );
}



Ogre::String
ScriptFile::GetVVariable( const u32 script_pointer )
{
    return "GetVar( 0x" + HexToString( GetU16LE( script_pointer ), 4, '0' ) + " )";
}



Ogre::String
ScriptFile::GetV80Variable( const u32 script_pointer )
{
    u16 data = GetU16LE( script_pointer );
    if( data & 0x8000 )
    {
        return "0x" + HexToString( GetU16LE( script_pointer ) & 0x7fff, 4, '0' );
    }
    else
    {
        return GetVVariable( script_pointer );
    }
}
