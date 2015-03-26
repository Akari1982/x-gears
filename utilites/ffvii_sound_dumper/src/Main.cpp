#include "../../common/OgreBase.h"
#include "../../common/Logger.h"

#include "AkaoParser.h"
#include "engine/SoundManager.h"



float timer = 0;

void Update( float delta )
{
    if( timer >= 0.003 )
    {
        timer = 0;
        AkaoParser::getSingleton().Update();
    }
    timer += delta;

    SOUNDMAN->Update();
}



int
main( int argc, char *argv[] )
{
    InitializeOgreBase( "FFVII Sound Exporter" );



    SoundManager* SOUNDMAN = new SoundManager();
    AkaoParser* AKAOPARSER = new AkaoParser();



    AKAOPARSER->LoadInstruments( "data/INSTR.ALL", "data/INSTR.DAT" );



    if( argc == 2 )
    {
        AKAOPARSER->PlayMusic( Ogre::String( "data/music/") + argv[ 1 ] );
        AKAOPARSER->DumpSequenceData( Ogre::String( "dump_" ) + argv[ 1 ] + ".txt" );
    }



    Ogre::Root::getSingleton().startRendering();



    delete AKAOPARSER;
    delete SOUNDMAN;



    DeinitializeOgreBase();



    return 0;
}
