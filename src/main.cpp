#include "ugar_io_opengl/game.h"
#include "ugar_io_opengl/GLBasics.h"
#include "ugar_io_opengl/ugarplayer.h"
#include "ugar_io_opengl/GameWindow.h"

int main() {
	GameWindow::Initialize();
	GameWindow::Run();
	return 0;
}

