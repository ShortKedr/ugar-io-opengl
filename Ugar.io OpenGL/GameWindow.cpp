#include "GameWindow.h"
#include <memory>

namespace {
std::unique_ptr<Game> game = std::make_unique<Game>();
}

int GameWindow::GetScreenWidth() {
	return GetSystemMetrics(SM_CXSCREEN);
}

int GameWindow::GetScreenHeight() {
	return GetSystemMetrics(SM_CYSCREEN);
}

void GameWindow::ResizeOrtho(int w, int h) {
	game->cam->viewportSize.x = static_cast<float>(w);
	game->cam->viewportSize.y = static_cast<float>(h);
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, w, h, 0);
	glMatrixMode(GL_MODELVIEW);
	glutInitWindowSize(w, h);
}

void GameWindow::Input(unsigned char key, int, int) {
	if (key == 32) game->Start();
}

void GameWindow::Initialize(int argc, char** argv) {
	glutInit(&argc, argv);
	glutSetOption(GLUT_MULTISAMPLE, 2);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_MULTISAMPLE | GLUT_RGB);
	glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
	glutInitWindowPosition((GetScreenWidth() / 2 - WINDOW_WIDTH / 2), GetScreenHeight() / 2 - WINDOW_HEIGHT / 2);
	glutCreateWindow("Ugar.io");
	glutDisplayFunc(Draw);
	glutReshapeFunc(ResizeOrtho);
	glutKeyboardFunc(Input);
	glutTimerFunc(8, Redraw, 0);
	glutTimerFunc(8, Update, 1);
	glEnable(GL_CULL_FACE);

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glClearColor(1.0, 1.0, 1.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, WINDOW_WIDTH, WINDOW_HEIGHT, 0);
	glMatrixMode(GL_MODELVIEW);

	glutMainLoop();
}

void GameWindow::Draw() {
	if (game == nullptr) return;
	glClear(GL_COLOR_BUFFER_BIT);
	game->Draw();
	glCullFace(GL_FRONT);
	glFlush();//glutSwapBuffers();

}

void GameWindow::Update(int) {
	game->Update();
	glutTimerFunc(8, Update, 1);
}

void GameWindow::Redraw(int) {
	glutPostRedisplay();
	glutTimerFunc(8, Redraw, 0);
}
