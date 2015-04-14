#include <Ogre.h>

#include "FieldModel.h"
#include "FieldModule.h"
#include "FieldPackFile.h"
#include "PacketFile.h"
//#include "ScriptFile.h"
#include "SpriteFile.h"
#include "Walkmesh.h"
#include "WalkmeshFile.h"
#include "../../common/Logger.h"

SpriteFile* sprite = NULL;
Walkmesh* walkmesh = NULL;



FieldModule::FieldModule()
{
}



FieldModule::~FieldModule()
{
}



void
FieldModule::LoadMap( const int file_id )
{
    LOGGER->Log( "Start load field with id \"" + IntToString( file_id ) + "\".\n" );

    LOGGER->Log( "Load textures:\n" );
    Vram* vram = new Vram();
    File* texture = new File( "data/field/0" + IntToString( file_id + 1 ) + ".raw2" );
    for( u32 i = 0; i < texture->GetFileSize(); )
    {
        u32 texture_header_id = texture->GetU32LE( i + 0x00 );
        u16 texture_header_vram_x = texture->GetU16LE( i + 0x04 );
        u16 texture_header_vram_y = texture->GetU16LE( i + 0x06 );
        u16 texture_header_move_x = texture->GetU16LE( i + 0x08 );
        u16 texture_header_move_y = texture->GetU16LE( i + 0x0a );
        u16 texture_header_width = texture->GetU16LE( i + 0x0c );
        u16 texture_header_height = texture->GetU16LE( i + 0x0e );

        LOGGER->Log( "    texture_header_id     = 0x" + HexToString( texture_header_id, 8, '0' ) + "\n" );
        LOGGER->Log( "    texture_header_vram_x = 0x" + HexToString( texture_header_vram_x, 8, '0' ) + "\n" );
        LOGGER->Log( "    texture_header_vram_y = 0x" + HexToString( texture_header_vram_y, 8, '0' ) + "\n" );
        LOGGER->Log( "    texture_header_move_x = 0x" + HexToString( texture_header_move_x, 8, '0' ) + "\n" );
        LOGGER->Log( "    texture_header_move_y = 0x" + HexToString( texture_header_move_y, 8, '0' ) + "\n" );
        LOGGER->Log( "    texture_header_width  = 0x" + HexToString( texture_header_width, 8, '0' ) + "\n" );
        LOGGER->Log( "    texture_header_height = 0x" + HexToString( texture_header_height, 8, '0' ) + "\n" );

        u32 number_of_chunk = texture->GetU32LE( i + 0x18 );

        u16 vram_x = ( texture_header_vram_x + texture_header_move_x ) * 2;
        u16 vram_y = texture_header_vram_y + texture_header_move_y;

        // move to data (header always in separate sector)
        u32 temp_i = i;
        i += 0x0800;

        for( u32 j = 0; j < number_of_chunk; ++j )
        {
            // get height of current chunk
            u16 height = texture->GetU16LE( temp_i + 0x1c + j * 0x02 );
            // palette
            if( texture_header_id == 0x00001201 )
            {
                for( int y = 0; y < height; ++y )
                {
                    for( int x = 0; x < texture_header_width; ++x )
                    {
                        u16 color = texture->GetU16LE( i + x * 0x02 + y * texture_header_width * 0x02 );
                        vram->PutU16( x * 2 + vram_x, y + vram_y, color );
                    }
                }
            }

            // textures
            else if( texture_header_id == 0x00001200 )
            {
                for( int y = 0; y < height; ++y )
                {
                    for( int x = 0; x < texture_header_width * 2; ++x )
                    {
                        u8 data = texture->GetU8( i + x + y * texture_header_width * 2 );
                        vram->PutU8( x + vram_x, y + vram_y, data );
                    }
                }
            }

            // unimplemented
            else
            {
                LOGGER->Log( "UNIMPLEMENTED texture header \"" + HexToString( texture_header_id, 8, '0' ) + "\" - texture not loaded." );
            }

            // move pointer to start of next texture
            i += ceil( ( float )( texture_header_width * 2 * height) / 0x0800 ) * 0x0800;
            // update height
            texture_header_height += height;
            vram_y += height;
        }
    }
    delete texture;
    vram->Save( "exported/texture.png" );



    FieldPackFile* field_pack = new FieldPackFile( "data/field/0" + Ogre::StringConverter::toString( file_id ) + "" );
    File* temp;

    // part 0
    temp = field_pack->Extract( 0 );
    temp->WriteFile( "exported/0" );
    delete temp;

    // part 1
    temp = field_pack->Extract( 1 );
    WalkmeshFile* walk = new WalkmeshFile( temp );
    temp->WriteFile( "exported/1_walkmesh" );
    walkmesh = new Walkmesh();
    walk->GetWalkmesh( walkmesh );
    delete temp;
    delete walk;
    walkmesh->SetUpWalkmesh();
    Ogre::SceneNode* node = Ogre::Root::getSingleton().getSceneManager("Scene")->getRootSceneNode()->createChildSceneNode();
    node->attachObject( walkmesh );

    // part 2
    temp = field_pack->Extract( 2 );
    {
        FieldModel model;
        model.Export( temp, vram, file_id );
    }
    temp->WriteFile( "exported/2_3dmodel" );
    delete temp;

    // part 3
    temp = field_pack->Extract( 3 );
    temp->WriteFile( "exported/3_2dsprite" );
    PacketFile* pack = new PacketFile( temp );
    //for( u32 i = 0; i < pack->GetNumberOfFiles(); ++i )
    {
        File* file = pack->ExtractFile( 4 );
        file->WriteFile( "exported/3_2dsprite_" + IntToString( 4 ) );

        sprite = new SpriteFile( file, vram );

        delete file;
    }
    delete pack;
    delete temp;

    // part 4
    temp = field_pack->Extract( 4 );
    temp->WriteFile( "exported/4_2dsprite_tex" );
    delete temp;

    // script
    temp = field_pack->Extract( 5 );
    //ScriptFile* script_file = new ScriptFile( temp );
    temp->WriteFile( "exported/5_script" );
    delete temp;
    //script_file->GetScripts();
    //delete script_file;

    // part 6
    temp = field_pack->Extract( 6 );
    temp->WriteFile( "exported/6" );
    delete temp;

    // part 7
    temp = field_pack->Extract( 7 );
    temp->WriteFile( "exported/7_dialogs" );
    delete temp;

    // part 8
    temp = field_pack->Extract( 8 );
    temp->WriteFile( "exported/8.trigger" );

    Logger* triggers_script = new Logger( "exported/triggers.xml" );
    triggers_script->Log( "<map>\n" );
    u8 number_of_triggers = temp->GetFileSize() / 0x18;
    for( u8 i = 0; i < number_of_triggers; ++i )
    {
        Ogre::Vector3 point1 = Ogre::Vector3( ( s16 )temp->GetU16LE( i * 0x18 + 0x00 ), ( s16 )temp->GetU16LE( i * 0x18 + 0x04 ), 0 ) / 64;
        Ogre::Vector3 point2 = Ogre::Vector3( ( s16 )temp->GetU16LE( i * 0x18 + 0x06 ), ( s16 )temp->GetU16LE( i * 0x18 + 0x0a ), 0 ) / 64;
        Ogre::Vector3 point3 = Ogre::Vector3( ( s16 )temp->GetU16LE( i * 0x18 + 0x0c ), ( s16 )temp->GetU16LE( i * 0x18 + 0x10 ), 0 ) / 64;
        Ogre::Vector3 point4 = Ogre::Vector3( ( s16 )temp->GetU16LE( i * 0x18 + 0x12 ), ( s16 )temp->GetU16LE( i * 0x18 + 0x16 ), 0 ) / 64;

        triggers_script->Log( "    <square_trigger name=\"Gateway" + IntToString( i ) + "\" point1=\"" + Ogre::StringConverter::toString( point1 ) + "\" point2=\"" + Ogre::StringConverter::toString( point2 ) + "\" point3=\"" + Ogre::StringConverter::toString( point3 ) + "\" point4=\"" + Ogre::StringConverter::toString( point4 ) + "\" enabled=\"true\" />\n" );
    }
    triggers_script->Log( "</map>\n" );

    delete temp;

    delete field_pack;

    delete vram;
}



void
FieldModule::Update()
{
    if( sprite != NULL )
    {
        sprite->Update();
    }

    if( walkmesh != NULL )
    {
        walkmesh->Update();
    }
}
