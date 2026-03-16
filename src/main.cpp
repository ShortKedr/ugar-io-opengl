#include "ugar_io_opengl/game.h"
#include "ugar_io_opengl/GLBasics.h"
#include "ugar_io_opengl/ugarplayer.h"
#include "ugar_io_opengl/GameWindow.h"

int RunApp() {
	GameWindow::Initialize();
	GameWindow::Run();
	return 0;
}

#if defined(_WIN32)
#include <windows.h>

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	return RunApp();
}
#else
int main() {
	return RunApp();
}
#endif

