#include <Ogre.h>
#include "../../common/OgreBase.h"
#include "../../common/Logger.h"

#include "FieldModule.h"



FieldModule* field;



void Update( float delta )
{
    field->Update();
}



int
main( int argc, char *argv[] )
{
    InitializeOgreBase( "Xenogears Walkmesh Exporter" );



    field = new FieldModule();



    field->LoadMap( "data/field/0608" );



    Ogre::Root::getSingleton().startRendering();



    delete field;



    DeinitializeOgreBase();



    return 0;
}
