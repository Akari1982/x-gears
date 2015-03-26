#ifndef EVENT_H
#define EVENT_H

// add this include because this is only common file between everything that uses Input function.
#include <OIS.h>



enum EventType
{
    ET_NULL = 0,
    ET_PRESS,
    ET_REPEAT_WAIT,
    ET_REPEAT,
    ET_RELEASE,
    ET_MOUSE_MOVE,
    ET_MOUSE_SCROLL
};



struct Event
{
    Event():
        type( ET_NULL ),
        param1( 0 ),
        param2( 0 ),
        event( "" )
    {
    };

    EventType type;
    float param1;
    float param2;
    Ogre::String event;
};



#endif // EVENT_H
