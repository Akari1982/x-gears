#include <vector>

#include <gl/gl.h>

#include "main.h"
#include "game.h"
#include "log.h"

#include "resource/file.h"
#include "resource/battle/model3d.h"
#include "resource/image/image.h"
#include "resource/image/tim.h"



Model3D *bag;
char **file_name;
GLfloat scale = 0.003f;
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

/*
    File *file;
    file = new File("watermark.bmp");
    file->loadFile();

    Image *image;
    image = new Image(file->buffer, file->size);
*/

    file_name = PHYSFS_enumerateFiles("battle");
    if (*file_name == NULL)
    {
        logger->log("No files");
    }
    // add the main directory to PhysicsFS search path
    if (!PHYSFS_addToSearchPath("./battle", 1))
    {
        logger->log("Warning: Can't add search path. Error: %s", PHYSFS_getLastError());
    }
    // add the main directory to PhysicsFS search path
    if (!PHYSFS_addToSearchPath("./test_2", 1))
    {
        logger->log("Warning: Can't add search path. Error: %s", PHYSFS_getLastError());
    }
    bag = new Model3D(*(file_name + 1), *file_name);

    bag->loadModel3D();

    while (state != EXIT)
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

//        TrotX += 0.1f;
//        TrotY += 0.7f;
//        TrotZ += 0.1f;

//        image->draw(screen, 0, 0, 0, 0, image->getWidth(), image->getHeight());

        glLoadIdentity();

        glTranslatef(-20.0f, -0.0f, -10.0f);
        glRotatef(TrotX, 1.0f, 0.0f, 0.0f);
        glRotatef(TrotY, 0.0f, 1.0f, 0.0f);
        glRotatef(TrotZ, 0.0f, 0.0f, 1.0f);

        axis();

        glScalef(scale, scale, scale);

//        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

//        glEnable(GL_ALPHA_TEST);
//        glAlphaFunc(GL_GREATER, 0);

        glEnable(GL_TEXTURE_2D);


        bag->viewModel3D();


        glDisable(GL_TEXTURE_2D);

//        glDisable(GL_ALPHA_TEST);




        do_input();

        // Update the screen
        SDL_GL_SwapBuffers();
    }

//  delete image;
//  delete file;
    delete bag;

    PHYSFS_freeList(file_name);

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
            else if(event.key.keysym.sym == SDLK_l)
            {
                file_name += 2;
                if (*file_name != NULL)
                {
                    delete bag;
                    bag = new Model3D(*(file_name + 1), *file_name);
                    bag->loadModel3D();
                }
                else
                {
                    file_name -= 2;
                }
            }
            else if(event.key.keysym.sym == SDLK_k)
            {
                file_name += 2;
                delete bag;
                bag = new Model3D(*(file_name + 1), *file_name);
                bag->loadModel3D();
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
                scale += 0.001f;
            }
            else if(event.key.keysym.sym == SDLK_a)
            {
                scale -= 0.001f;
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