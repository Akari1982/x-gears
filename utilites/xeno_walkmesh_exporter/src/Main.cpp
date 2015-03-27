#include <Ogre.h>
#include "../../common/OgreBase.h"
#include "../../common/Logger.h"

#include "Walkmesh.h"
#include "WalkmeshFile.h"



Walkmesh* walkmesh;



void Update( float delta )
{
    walkmesh->Update();
}



int
main( int argc, char *argv[] )
{
    InitializeOgreBase( "Xenogears Walkmesh Exporter" );



    walkmesh = new Walkmesh();
    WalkmeshFile* file = new WalkmeshFile( "data/field/1_walkmesh" );
    file->GetWalkmesh( walkmesh );
    delete file;

    walkmesh->SetUpWalkmesh();
    Ogre::SceneNode* node = Ogre::Root::getSingleton().getSceneManager("Scene")->getRootSceneNode()->createChildSceneNode();
    node->attachObject( walkmesh );



    Ogre::Root::getSingleton().startRendering();



    delete walkmesh;



    DeinitializeOgreBase();



    return 0;
}
