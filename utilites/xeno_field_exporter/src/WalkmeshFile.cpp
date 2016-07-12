#include "WalkmeshFile.h"

#include "../../common/Logger.h"

#include <OgreStringConverter.h>



WalkmeshFile::WalkmeshFile( File* pFile ):
    File( pFile )
{
}



WalkmeshFile::~WalkmeshFile()
{
}



void
WalkmeshFile::GetWalkmesh( Walkmesh* walkmesh )
{
    // numbers of subblock
    u32 block_count = GetU32LE( 0x00 );

    for( unsigned int i = 0; i < block_count; ++i )
    {
        Logger* export_script = new Logger( "exported/wm" + IntToString( i ) + ".xml" );
        export_script->Log( "<walkmesh>\n" );
        u32 block_size   = GetU32LE( 0x04 + i * 0x04 );
        u32 block_start  = GetU32LE( 0x04 + 0x14 + i * 0x08 + 0x00 );
        u32 block_vertex = GetU32LE( 0x04 + 0x14 + i * 0x08 + 0x04 );

        for( unsigned int j = 0; j < block_size; )
        {
            u16 a_offset = block_vertex + GetU16LE(block_start + j + 0x00) * 0x08;
            u16 b_offset = block_vertex + GetU16LE(block_start + j + 0x02) * 0x08;
            u16 c_offset = block_vertex + GetU16LE(block_start + j + 0x04) * 0x08;

            WalkmeshTriangle triangle;
            triangle.a = Ogre::Vector3(-(s16)GetU16LE(0x00 + a_offset), -(s16)GetU16LE(0x04 + a_offset), -(s16)GetU16LE(0x02 + a_offset));
            triangle.b = Ogre::Vector3(-(s16)GetU16LE(0x00 + b_offset), -(s16)GetU16LE(0x04 + b_offset), -(s16)GetU16LE(0x02 + b_offset));
            triangle.c = Ogre::Vector3(-(s16)GetU16LE(0x00 + c_offset), -(s16)GetU16LE(0x04 + c_offset), -(s16)GetU16LE(0x02 + c_offset));
            triangle.a /= 64;
            triangle.b /= 64;
            triangle.c /= 64;
/*
            Ogre::Matrix3 matrix;
            matrix.FromEulerAnglesXYZ(
                Ogre::Radian( Ogre::Degree( 90.0f ) ),
                Ogre::Radian( Ogre::Degree( 0.0f ) ),
                Ogre::Radian( Ogre::Degree( 90.0f ) ) );

            triangle.a = triangle.a * matrix;
            triangle.b = triangle.b * matrix;
            triangle.c = triangle.c * matrix;
*/
            //thisSceneNode->roll(  );
            //thisSceneNode->yaw(  );
            //thisSceneNode->pitch(  );


            triangle.access_side[0] = (s16)GetU16LE(block_start + j + 0x06);
            triangle.access_side[1] = (s16)GetU16LE(block_start + j + 0x08);
            triangle.access_side[2] = (s16)GetU16LE(block_start + j + 0x0a);

            triangle.unknown1 = GetU8(block_start + j + 0x0c);
            triangle.unknown2 = GetU8(block_start + j + 0x0d);

            export_script->Log(
                "    <triangle a=\"" +
                Ogre::StringConverter::toString( triangle.a ) +
                "\" b=\"" +
                Ogre::StringConverter::toString( triangle.b ) +
                "\" c=\"" +
                Ogre::StringConverter::toString( triangle.c ) +
                "\" a_b=\"" +
                IntToString( triangle.access_side[ 0 ] ) +
                "\" b_c=\"" +
                IntToString( triangle.access_side[ 1 ] ) +
                "\" c_a=\"" +
                IntToString( triangle.access_side[ 2 ] ) +
                "\"/>\n"
            );

            walkmesh->AddTriangle(triangle);

            j += 0x0e;
        }

        export_script->Log( "</walkmesh>" );
        delete export_script;
    }
}
