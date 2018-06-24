#include "Extract.h"

#include "../../common/Logger.h"
#include "../../common/OgreBase.h"


#include <OgreString.h>



void Update( float delta )
{
}



int
main( int argc, char *argv[] )
{
    InitializeOgreBase( "Xenogears Exporter" );

    Ogre::String directory = "STRIPCD";

    LOGGER->Log( "Xenogears Main Disk Dumper v0.9.67\n  Created by Graph and _Ombra_\n\n" );

    if( argc != 2 )
    {
        LOGGER->Log("USAGE:'extract.exe isofile' extract files from xeno cd image.\n");
        return EXIT_FAILURE;
    }

    extract( directory );



    DeinitializeOgreBase();

    return 0;
}
