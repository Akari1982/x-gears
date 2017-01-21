#include <vector>

#include <gl/gl.h>

#include "main.h"
#include "game.h"
#include "log.h"

#include "resource/file.h"
#include "resource/battle/enemy2d.h"
#include "resource/image/image.h"
#include "resource/image/tim.h"



Enemy2D *enemy;



void game()
{
    do_init();

    File *file;
    file = new File("watermark.bmp");
    file->loadFile();

    Image *image;
    image = new Image(file->buffer, file->size);


    enemy = new Enemy2D("2757.unk2");
    enemy->loadEnemy2D();



    while (state != EXIT)
    {
        image->draw(screen, 0, 0, 0, 0, image->getWidth(), image->getHeight());

        do_input();

        // Update the screen
        SDL_GL_SwapBuffers();
    }



    delete image;
    delete file;

    delete enemy;

    do_exit();
}


void do_init()
{
    if (!PHYSFS_addToSearchPath("./battle", 1))
    {
        logger->log("Warning: Can't add search path. Error: %s", PHYSFS_getLastError());
    }

    logger->log("Init");
}



void do_exit()
{
    logger->log("Exit");
}



void do_input()
{
    // Poll SDL events
    while(SDL_PollEvent(&event))
    {
        if (event.type == SDL_KEYDOWN)
        {
            if (event.key.keysym.sym == SDLK_ESCAPE)
            {
                logger->log("Key: SDLK_ESCAPE pressed");
                state = EXIT;
            }
        }
        else if(event.type == SDL_QUIT)
        {
            logger->log("Event: SDL_QUIT happened");
            state = EXIT;
        }
    }
}