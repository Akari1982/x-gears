#include <Ogre.h>
#include "../../common/OgreBase.h"
#include "../../common/Logger.h"

#include "Walkmesh.h"
#include "WalkmeshFile.h"



int
main( int argc, char *argv[] )
{
    InitializeOgreBase( "Xenogears Walkmesh Exporter" );



    Walkmesh* walkmesh = new Walkmesh();
    WalkmeshFile* file = new WalkmeshFile( "data/field/1_walkmesh" );
    file->GetWalkmesh( walkmesh );
    delete file;

    walkmesh->SetUpWalkmesh();
    //walkmesh->setVisible( true );
    Ogre::SceneNode* node = Ogre::Root::getSingleton().getSceneManager("Scene")->getRootSceneNode()->createChildSceneNode();
    node->attachObject( walkmesh );



    Ogre::Root::getSingleton().startRendering();



    DeinitializeOgreBase();



    return 0;
}
