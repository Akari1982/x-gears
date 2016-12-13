#include "DialogFile.h"
#include "../../common/Logger.h"



DialogFile::DialogFile( File *pFile ):
    File( pFile )
{
}



DialogFile::~DialogFile()
{
}




void
DialogFile::GetDialogs( const int file_id )
{
    Logger* export_script = new Logger( "exported/debug/0" + IntToString( file_id ) + "_7_dialogs.txt" );

    u32 number_of_dialogs = GetU32LE( 0x00 ) + 1;

    for( u32 i = 0; i < number_of_dialogs; ++i )
    {
        int size_offset = 0x04 + number_of_dialogs * 0x02 + i * 0x02;
        int data_offset = GetU16LE( 0x04 + i * 0x02 );
        export_script->Log( "Dialog 0x" + HexToString( i, 2, '0' ) + "\n" );
        export_script->Log( "width = " + IntToString( GetU8( size_offset + 0 ) ) + ", height = " + IntToString( GetU8( size_offset + 1 ) ) + "\n" );

        while( true )
        {
            u8 temp = GetU8( data_offset );
            ++data_offset;
            export_script->Log( "" + HexToString( temp, 2, '0' ) + "\n" );
            break;
        }
    }
}
