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
FieldModule::LoadMap( const Ogre::String& file )
{
    LOG_TRIVIAL( "Start load field \"" + file + "\"." );



    FieldPackFile* field_pack = new FieldPackFile( file );
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
    temp->WriteFile( "exported/8" );
    delete temp;



    delete field_pack;
}



void
FieldModule::Update()
{
    walkmesh->Update();
}
