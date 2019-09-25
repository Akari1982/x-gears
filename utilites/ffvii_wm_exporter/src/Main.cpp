#include <Ogre.h>
#include "../../common/OgreBase.h"
#include "../../common/Logger.h"
#include "BszFile.h"
#include "ScriptFile.h"



void Update( float delta )
{
}



int
main( int argc, char *argv[] )
{
    InitializeOgreBase( "FFVII Exporter" );

    {
        BszFile* lzs = new BszFile( "data/WORLD/WM0.TXZ" );
        lzs->WriteFile( "exported/WM0.TXZ_u" );

        int file_id = 4; // script
        ScriptFile* script = new ScriptFile( lzs, 4 + lzs->GetU32LE( 4 + file_id * 4 ), 0x7000 );
        script->WriteFile( "exported/WM0.EV" );
        script->Export();
        delete script;

        delete lzs;

/*
        lzs = new BszFile( "data/WORLD/WM1.TXZ" );
        lzs->WriteFile( "exported/WM1.TXZ_u" );
        delete lzs;

        lzs = new BszFile( "data/WORLD/WM2.TXZ" );
        lzs->WriteFile( "data/WORLD/WM2.TXZ_u" );
        delete lzs;

        lzs = new BszFile( "data/WORLD/WM3.TXZ" );
        lzs->WriteFile( "data/WORLD/WM3.TXZ_u" );
        delete lzs;

        lzs = new BszFile( "data/WORLD/WM4.TXZ" );
        lzs->WriteFile( "data/WORLD/WM4.TXZ_u" );
        delete lzs;

        lzs = new BszFile( "data/WORLD/WM5.TXZ" );
        lzs->WriteFile( "data/WORLD/WM5.TXZ_u" );
        delete lzs;

        lzs = new BszFile( "data/WORLD/WM6.TXZ" );
        lzs->WriteFile( "data/WORLD/WM6.TXZ_u" );
        delete lzs;

        lzs = new BszFile( "data/WORLD/WM7.TXZ" );
        lzs->WriteFile( "data/WORLD/WM7.TXZ_u" );
        delete lzs;

        lzs = new BszFile( "data/WORLD/WM8.TXZ" );
        lzs->WriteFile( "data/WORLD/WM8.TXZ_u" );
        delete lzs;

        lzs = new BszFile( "data/WORLD/WM9.TXZ" );
        lzs->WriteFile( "data/WORLD/WM9.TXZ_u" );
        delete lzs;

        lzs = new BszFile( "data/WORLD/WMA.TXZ" );
        lzs->WriteFile( "data/WORLD/WMA.TXZ_u" );
        delete lzs;

        lzs = new BszFile( "data/WORLD/WMB.TXZ" );
        lzs->WriteFile( "data/WORLD/WMB.TXZ_u" );
        delete lzs;

        lzs = new BszFile( "data/WORLD/WMC.TXZ" );
        lzs->WriteFile( "data/WORLD/WMC.TXZ_u" );
        delete lzs;

        lzs = new BszFile( "data/WORLD/WM1.BSZ" );
        lzs->WriteFile( "data/WORLD/WM1.BSZ_u" );
        delete lzs;

        lzs = new BszFile( "data/WORLD/WM2.BSZ" );
        lzs->WriteFile( "data/WORLD/WM2.BSZ_u" );
        delete lzs;

        lzs = new BszFile( "data/WORLD/WM3.BSZ" );
        lzs->WriteFile( "data/WORLD/WM3.BSZ_u" );
        delete lzs;
*/
    }

    {
/*
        MeshData data;
        data.name = "robo1";
        data.tex_width = 4096;
        data.tex_height = 256;
        ModelInfo model_info;
        model_info.data = data;
        model_info.model_file = "2203.model";
        model_info.animation_file = "2202.animation";
        model_info.animations.push_back( "Idle" );
        model_info.animations.push_back( "ToIdle" );
        model_info.animations.push_back( "ToFire" );
*/
/*
        MeshData data;
        data.name = "weltall";
        data.tex_width = 4096;
        data.tex_height = 256;

        ModelInfo model_info;
        model_info.data = data;
        model_info.model_file = "2145.model";
        model_info.animation_file = "2144.animation";
        model_info.animations.push_back( "Idle" );
        model_info.animations.push_back( "1" );
        model_info.animations.push_back( "2" );
        model_info.animations.push_back( "3" );
        model_info.animations.push_back( "4" );
        model_info.animations.push_back( "5" );
        model_info.animations.push_back( "6" );
        model_info.animations.push_back( "7" );
        model_info.animations.push_back( "8" );
        model_info.animations.push_back( "9" );
        model_info.animations.push_back( "10" );
        model_info.animations.push_back( "11" );
        model_info.animations.push_back( "12" );
        model_info.animations.push_back( "14" );
        model_info.animations.push_back( "15" );
        model_info.animations.push_back( "16" );
        model_info.animations.push_back( "17" );
        model_info.animations.push_back( "18" );
        model_info.animations.push_back( "19" );
        model_info.animations.push_back( "20" );
        model_info.animations.push_back( "21" );
        model_info.animations.push_back( "22" );
        model_info.animations.push_back( "23" );
        model_info.animations.push_back( "24" );
        model_info.animations.push_back( "25" );
        model_info.animations.push_back( "26" );
        model_info.animations.push_back( "27" );

        AnimatedModel model;
        Ogre::Entity* exported_entity = model.Export( model_info );

        if( exported_entity != NULL )
        {
            entitys.push_back( exported_entity );
            entitys[ 0 ]->setVisible( true );
        }
*/
    }



    Ogre::Root::getSingleton().startRendering();



    DeinitializeOgreBase();



    return 0;
}
