#include <vector>

#include <gl/gl.h>

#include "main.h"
#include "game.h"
#include "log.h"

#include "resource/file.h"
#include "resource/battle/xg3d.h"



GLfloat scale = 0.001f;
GLfloat TrotX = 10.0f;
GLfloat TrotY = -10.0f;
GLfloat TrotZ = 0.0f;
unsigned int mesh = 0;


void
axis()
{
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glLineWidth(2);
    glBegin(GL_LINES);
        glColor3f(1.0f, 0.0f, 0.0f); glVertex3f( 0.0f,     0.0f,     0.0f);
        glColor3f(1.0f, 0.0f, 0.0f); glVertex3f( 0.0f,     50.0f, 0.0f);
        glColor3f(0.0f, 1.0f, 0.0f); glVertex3f( 0.0f,     0.0f,     0.0f);
        glColor3f(0.0f, 1.0f, 0.0f); glVertex3f( 50.0f, 0.0f,     0.0f);
        glColor3f(0.0f, 0.0f, 1.0f); glVertex3f( 0.0f,     0.0f,     0.0f);
        glColor3f(0.0f, 0.0f, 1.0f); glVertex3f( 0.0f,     0.0f,     50.0f);
        glColor3f(1.0f, 1.0f, 1.0f);
    glEnd();
    glLineWidth(1);
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
}



void game()
{
    do_init();


    if (!PHYSFS_addToSearchPath("./test", 1))
    {
        logger->log("Warning: Can't add search path. Error: %s", PHYSFS_getLastError());
    }
    XG3D *bag = new XG3D("3964_u");

    bag->loadXG3D();

    while (state != EXIT)
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

//        TrotX += 0.1f;
//        TrotY += 0.7f;
//        TrotZ += 0.1f;

        glLoadIdentity();

        glTranslatef(20.0f, -0.0f, -10.0f);
        glRotatef(TrotX, 1.0f, 0.0f, 0.0f);
        glRotatef(TrotY, 0.0f, 1.0f, 0.0f);
        glRotatef(TrotZ, 0.0f, 0.0f, 1.0f);

        axis();

        glScalef(scale, scale, scale);

        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

//        glEnable(GL_ALPHA_TEST);
//        glAlphaFunc(GL_GREATER, 0);

//        glEnable(GL_TEXTURE_2D);


        bag->viewXG3D(mesh);


//        glDisable(GL_TEXTURE_2D);

//        glDisable(GL_ALPHA_TEST);




        do_input();

        // Update the screen
        SDL_GL_SwapBuffers();
    }

    delete bag;

    do_exit();
}


void do_init()
{
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
            else if(event.key.keysym.sym == SDLK_q)
            {
                mesh++;
            }
            else if(event.key.keysym.sym == SDLK_w)
            {
                mesh--;
            }
            else if(event.key.keysym.sym == SDLK_s)
            {
                scale *= 2;
            }
            else if(event.key.keysym.sym == SDLK_a)
            {
                scale /= 2;
            }
            else if(event.key.keysym.sym == SDLK_RIGHT)
            {
                TrotY += 1.0f;
            }
            else if(event.key.keysym.sym == SDLK_LEFT)
            {
                TrotY -= 1.0f;
            }
            else if(event.key.keysym.sym == SDLK_x)
            {
                TrotX += 1.0f;
            }
            else if(event.key.keysym.sym == SDLK_z)
            {
                TrotX -= 1.0f;
            }
            else if(event.key.keysym.sym == SDLK_DOWN)
            {
                TrotZ += 1.0f;
            }
            else if(event.key.keysym.sym == SDLK_UP)
            {
                TrotZ -= 1.0f;
            }
        }
        else if(event.type == SDL_QUIT)
        {
            logger->log("Event: SDL_QUIT happened");
            state = EXIT;
        }
    }
}