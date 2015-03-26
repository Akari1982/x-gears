#include "../../common/OgreBase.h"
#include "../../common/Logger.h"

#include "SoundParser.h"
#include "engine/SoundManager.h"



float timer = 0;

void Update( float delta )
{
    if( timer >= 0.015 )
    {
        timer = 0;
        SoundParser::getSingleton().Update();
    }
    timer += delta;

    SOUNDMAN->Update();
}



int
main( int argc, char *argv[] )
{
    InitializeOgreBase( "Xenogears Sound Exporter" );

    SoundManager* SOUNDMAN = new SoundManager();
    SoundParser* sound_parser = new SoundParser();

    if( argc == 2 )
    {
        int number = Ogre::StringConverter::parseInt( argv[ 1 ] );
        sound_parser->LoadInstruments( "data/0" + Ogre::StringConverter::toString( number ) + ".snd" );
        sound_parser->LoadSequence( "data/0" + Ogre::StringConverter::toString( number + 1 ) + ".smd" );
    }
    else
    {
        sound_parser->LoadInstruments( "data/0216.snd" );
        sound_parser->LoadSequence( "data/0217.smd" );
    }

    Ogre::Root::getSingleton().startRendering();

    delete sound_parser;
    delete SOUNDMAN;

    DeinitializeOgreBase();

    return 0;
}
