#include <Ogre.h>

#include "FieldModule.h"
#include "FieldPackFile.h"
//#include "ScriptFile.h"
#include "Walkmesh.h"
#include "WalkmeshFile.h"
#include "../../common/Logger.h"

Walkmesh* walkmesh;



FieldModule::FieldModule()
{
}



FieldModule::~FieldModule()
{
}



void
FieldModule::LoadMap( const int file_id )
{
    LOG_TRIVIAL( "Start load field \"" + file + "\"." );

    FieldPackFile* field_pack = new FieldPackFile( "data/0" + Ogre::StringConverter::toString( file_id ) + "" );
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
        File* texture = new File( "data/0" + Ogre::StringConverter::toString( file_id + 1 ) + ".raw2" );
        model.Export( temp, texture );
        delete texture;
    }
    temp->WriteFile( "exported/2_3dmodel" );
    delete temp;

    // part 3
    temp = field_pack->Extract( 3 );
    temp->WriteFile( "exported/3_2dsprite" );
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
}



void
FieldModule::Update()
{
    walkmesh->Update();
}
