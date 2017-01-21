#include "main.h"
#include "log.h"
#include "game.h"

#include <iostream>

#include <gl/gl.h>
#include <gl/glu.h>
#include <SDL/SDL.h>
#include <physfs.h>



SDL_Surface* screen;
SDL_Event event;

// ��������� ���������
unsigned char state;

Logger *logger; // Log object



// configure open gl staff
void
init_opengl()
{
	// ������������� ���� ��� ������� ������ �����
	glClearColor(0.1f, 0.1f, 0.1f, 0.0f);
	// ������������� �������� ��� ������� ������ �������
	glClearDepth(1.0);
	// ��������� Z ������
	glDepthFunc(GL_LESS);
	// �, �������, ���������
	glEnable(GL_DEPTH_TEST);
	// ��������� ����� ��������� ( flat ��� smooth )
	glShadeModel(GL_SMOOTH);
	// ������������� ������� �������� ������� �������
	glMatrixMode(GL_PROJECTION);
	// �������� ��� ����� �������
	glLoadIdentity();
	// ����������� ����������� ( ��� ���, ������� �� glu32 )
	gluPerspective(45.0f, (GLfloat)640 / (GLfloat)480, 50.0f, 300.0f);
	gluLookAt( 0, 50,-50, 0, 0, 0, 0, 1, 0);
	// � ������������� � ��������� �������
	glMatrixMode(GL_MODELVIEW);

	logger->log("Configure OpenGl complete.");
}


// Do all initialization stuff
void
init_engine()
{
	// add the main directory to PhysicsFS search path
	if (!PHYSFS_addToSearchPath("./", 1))
	{
		logger->log("Warning: Can't add search path. Error: %s", PHYSFS_getLastError());
	}

	// add the main directory to PhysicsFS write path
	if (!PHYSFS_setWriteDir("./"))
	{
		logger->log("Warning: Can't add wright path. Error: %s", PHYSFS_getLastError());
	}

	// �������������� �����
	logger = new Logger(std::string("game.log"));

	// Here we initialize SDL as we would do with any SDL application.
	SDL_Init(SDL_INIT_VIDEO);

	SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 5);     // Use at least 5 bits of Red
	SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 5);   // Use at least 5 bits of Green
	SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 5);    // Use at least 5 bits of Blue
	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 16);  // Use at least 16 bits for the depth buffer
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1); // Enable double buffering

	screen = SDL_SetVideoMode(640, 480, 16, SDL_OPENGLBLIT | SDL_HWSURFACE);
	logger->log("Initialize SDL and OpenGl.");

	// init opengl
	init_opengl();

	// We want unicode
	SDL_EnableUNICODE(1);
	// We want to enable key repeat
	SDL_EnableKeyRepeat(SDL_DEFAULT_REPEAT_DELAY, SDL_DEFAULT_REPEAT_INTERVAL);
	logger->log("Enable key repeat.");
}



/** Clear the engine */
void
exit_engine()
{
	delete logger;
	// Destroy SDL stuff
	SDL_Quit();
}



int
main(int argc, char *argv[])
{
	// Initialize PhysicsFS
	PHYSFS_init(argv[0]);

	init_engine();

	state = GAME;
	game();

	exit_engine();

	PHYSFS_deinit();

	return 0;
}