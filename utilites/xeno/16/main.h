#ifndef MAIN_H

#include <SDL/SDL.h>



enum {
	EXIT,
	GAME
};



// ��� SDL
extern SDL_Surface* screen;
extern SDL_Event event;

extern unsigned char state;


#define MAIN_H
#endif