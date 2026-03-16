#ifndef GAME_WINDOW
#define GAME_WINDOW

#include <GL/freeglut.h>
#include "game.h"
#include "GLBasics.h"
#include "ugarplayer.h"

namespace GameWindow
{

	static const  int WINDOW_WIDTH = 800;
	static const  int WINDOW_HEIGHT = 600;

	int GetScreenWidth();
	int GetScreenHeight();

	void ResizeOrtho(int w, int h);
	void Initialize(int argc, char** argv);
	
	void Input(unsigned char key, int, int);

	void Update(int);
	void Redraw(int);
	void Draw();
};
#endif
