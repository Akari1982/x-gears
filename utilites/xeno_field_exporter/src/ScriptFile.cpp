#include "ScriptFile.h"
#include "../../common/Logger.h"



ScriptFile::ScriptFile( File *pFile ):
    File( pFile )
{
}



ScriptFile::~ScriptFile()
{
}




void
ScriptFile::GetScripts()
{
    Logger* export_script = new Logger( "exported/script.lua" );
    export_script->Log( "EntityContainer = {}\n\n\n\n" );

    u32 number_of_entity = GetU8( 0x80 );
    u32 offset_to_script = 0x84 + number_of_entity * 0x40;

    for( u32 i = 0; i < number_of_entity; ++i )
    {
        export_script->Log( "EntityContainer[ \"Entity_" + HexToString( i, 2, '0' ) + "\" ] = {\n" );

        for( u8 j = 0; j < 0x20; ++j )
        {

            u32 offset_in_script = GetU16LE( 0x84 + i * 0x40 + j * 2 );
            if( offset_in_script == 0 )
            {
                break;
            }
            export_script->Log( "    script_" + HexToString( j, 2, '0' ) + " = function( self )\n" );



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
                    export_script->Log( "Return();" );
                }
                else if( opcode == 0x01 )
                {
                    export_script->Log( "JumpTo( 0x" + HexToString( GetU16LE( script_pointer ), 4, '0' ) + " );" );
                    script_pointer += 2;
                }
                else if( opcode == 0x02 )
                {
                    export_script->Log( "ConditionalJumpTo( " );
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
                else if( opcode == 0x26 )
                {
                    export_script->Log( "Wait( time=" + GetV80Variable( script_pointer ) + " );" );
                    script_pointer += 2;
                }
                else if( opcode == 0x84 )
                {
                    export_script->Log( "ProgressLessEqualJumpTo( value=" + GetV80Variable( script_pointer ) + ", jump=" + GetU16Variable( script_pointer + 2 ) + " );" );
                    script_pointer += 4;
                }
                else if( opcode == 0x86 )
                {
                    export_script->Log( "ProgressNotEqualJumpTo( value=" + GetV80Variable( script_pointer ) + ", jump=" + GetU16Variable( script_pointer + 2 ) + " );" );
                    script_pointer += 4;
                }
                else if( opcode == 0xcb )
                {
                    export_script->Log( "TriggerJumpTo( trigger_id=" + GetV80Variable( script_pointer ) + ", jump=" + GetU16Variable( script_pointer + 2 ) + " );" );
                    script_pointer += 4;
                }

/*
                else if (opcode == 0x0B)
                {
                    LOGGER->Log("0x0B_EntityNPCInit");
                    GetV80Variable(script_pointer, "model_id");
                    LOGGER->Log("; // init values for entity with model.\n");
                }
                else if (opcode == 0x16)
                {
                    LOGGER->Log("0x16_EntityPCInit");
                    GetV80Variable(script_pointer, "character_id");
                    LOGGER->Log("; // init values for player character entity with model.\n");
                }
                else if (opcode == 0x19)
                {
                    LOGGER->Log("0x19_SetPosition");
                    GetVF80Variable(script_pointer, "x");
                    GetVF40Variable(script_pointer, "z");
                    GetFVariable(script_pointer);
                    LOGGER->Log("; // set entity on walkmesh based on given x and y.\n");
                }
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
                else if (opcode == 0x2A)
                {
                    LOGGER->Log("0x2A(); // add flag 00000002 in 80115cdc + 0 of current entity.\n");
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
                else if (opcode == 0xBC)
                {
                    LOGGER->Log("0xBC_EntityNoModelInit(); // init values for entity without model.\n");
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
                else if (opcode == 0xFE)
                {
                    u8 eo_opcode = GetU8(script_pointer);
                    script_pointer += 1;

                    if (eo_opcode == 0x0D)
                    {
                        LOGGER->Log("0xFE0D_SetAvatar");
                        GetV80Variable(script_pointer, "character_id");
                        LOGGER->Log("; // assign avatar for current entity.\n");
                    }
                    else
                    {
                        LOGGER->Log("MISSING OPCODE 0xFE%02x\n", eo_opcode);
                        break;
                    }
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
                    export_script->Log( "MISSING OPCODE 0x" + HexToString( opcode, 2, '0' ) + "\n" );
                    break;
                }

                export_script->Log( " -- " + address + " 0x" + HexToString( opcode, 2, '0' ) + "\n" );
            }

            export_script->Log( "    end,\n\n" );
        }

        export_script->Log( "}\n\n\n\n" );
    }
}



void
ScriptFile::GetEVariable( u32& script_pointer )
{
    u8 data = GetU8(script_pointer);
    //LOGGER->Log("(entity_id 0x%02x)", data);
    script_pointer += 1;
}



void
ScriptFile::GetFVariable( u32& script_pointer )
{
    u8 data = GetU8(script_pointer);
    //LOGGER->Log("(flags 0x%02x)", data);
    script_pointer += 1;
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



void
ScriptFile::GetVF40Variable( u32& script_pointer, const Ogre::String& name )
{
    u16 data = GetU16LE(script_pointer);
    //LOGGER->Log("(vf40 %s 0x%04x)", name.c_str(), data);
    script_pointer += 2;
}



void
ScriptFile::GetVF80Variable( u32& script_pointer, const Ogre::String& name )
{
    u16 data = GetU16LE(script_pointer);
    //LOGGER->Log("(vf80 %s 0x%04x)", name.c_str(), data);
    script_pointer += 2;
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
