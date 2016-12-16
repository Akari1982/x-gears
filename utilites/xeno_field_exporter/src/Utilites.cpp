#include "Utilites.h"



const Ogre::String
GetFieldName( const int file_id )
{
    switch( file_id )
    {
        case 608: return "lahan_city";
        case 616: return "lahan_tutorial";
        case 618: return "lahan_shop";
        case 620: return "lahan_civilian_house1";
        case 622: return "lahan_civilian_house2";
        case 624: return "lahan_bar1";
        case 626: return "lahan_bar2";
        case 628: return "lahan_alice_house1";
        case 630: return "lahan_alice_house2";
        case 632: return "lahan_chief_house1";
        case 634: return "lahan_chief_house2";
    }

    return "";
}
