#include <stdio.h>
#include <cstdlib>

using namespace std;



int main()
{
    char* buffer;
    int buffer_size;

    FILE* file = fopen( "source.txt", "rb" );
    fseek( file, 0, SEEK_END );
    buffer_size = ftell( file );

    buffer = ( char* )malloc( sizeof( char ) * buffer_size );

    fseek( file, 0, SEEK_SET );
    fread( buffer, sizeof( char ), buffer_size, file );
    fclose( file );

    bool start_parse = false;

    char string[ 100 ];
    int str_pos = 0;

    for( int pos = 0; pos < buffer_size; ++pos )
    {
        char data = buffer[ pos ];

        if( data == '\t' )
        {
            start_parse = true;
            continue;
        }
        if( data == '\n' || ( pos + 1 >= buffer_size ) )
        {
            string[ str_pos ] = '\0';
            str_pos = 0;
            start_parse = false;

            printf( string );
            printf( "\n" );
            continue;
        }

        if( start_parse == true )
        {
            string[ str_pos ] = data;
            ++str_pos;
        }
    }

    return 0;
}
