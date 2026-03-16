#ifndef GAME_WINDOW
#define GAME_WINDOW

#include <GLFW/glfw3.h>
#include "ugar_io_opengl/game.h"
#include "ugar_io_opengl/GLBasics.h"
#include "ugar_io_opengl/ugarplayer.h"

namespace GameWindow
{

	static const  int WINDOW_WIDTH = 800;
	static const  int WINDOW_HEIGHT = 600;

	int GetWindowWidth();
	int GetWindowHeight();
	bool IsKeyPressed(int key);

	void Initialize();
	void Run();
};
#endif

