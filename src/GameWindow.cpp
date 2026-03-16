#include "ugar_io_opengl/GameWindow.h"
#include <GLFW/glfw3.h>
#include <memory>

namespace {
std::unique_ptr<Game> game = std::make_unique<Game>();
GLFWwindow* window = nullptr;
int framebufferWidth = GameWindow::WINDOW_WIDTH;
int framebufferHeight = GameWindow::WINDOW_HEIGHT;

void UpdateProjection(int width, int height) {
	framebufferWidth = width;
	framebufferHeight = height;
	game->cam->viewportSize.x = static_cast<float>(width);
	game->cam->viewportSize.y = static_cast<float>(height);

	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, static_cast<double>(width), static_cast<double>(height), 0.0, -1.0, 1.0);
	glMatrixMode(GL_MODELVIEW);
}

void FramebufferSizeCallback(GLFWwindow*, int width, int height) {
	UpdateProjection(width, height);
}

void KeyCallback(GLFWwindow*, int key, int, int action, int) {
	if (key == GLFW_KEY_SPACE && action == GLFW_PRESS) {
		game->Start();
	}
}
}

int GameWindow::GetWindowWidth() {
	return framebufferWidth;
}

int GameWindow::GetWindowHeight() {
	return framebufferHeight;
}

bool GameWindow::IsKeyPressed(int key) {
	return window != nullptr && glfwGetKey(window, key) == GLFW_PRESS;
}

void GameWindow::Initialize() {
	if (!glfwInit()) {
		return;
	}

	window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Ugar.io", nullptr, nullptr);
	if (window == nullptr) {
		glfwTerminate();
		return;
	}

	glfwMakeContextCurrent(window);
	glfwSwapInterval(1);
	glfwSetFramebufferSizeCallback(window, FramebufferSizeCallback);
	glfwSetKeyCallback(window, KeyCallback);

	if (GLFWmonitor* monitor = glfwGetPrimaryMonitor()) {
		if (const GLFWvidmode* mode = glfwGetVideoMode(monitor)) {
			glfwSetWindowPos(window, (mode->width - WINDOW_WIDTH) / 2, (mode->height - WINDOW_HEIGHT) / 2);
		}
	}

	glfwGetFramebufferSize(window, &framebufferWidth, &framebufferHeight);
	UpdateProjection(framebufferWidth, framebufferHeight);

	glEnable(GL_CULL_FACE);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glClearColor(1.0, 1.0, 1.0, 1.0);
}

void GameWindow::Run() {
	if (window == nullptr) {
		return;
	}

	double lastTick = glfwGetTime();
	double accumulator = 0.0;
	constexpr double tickSeconds = 0.008;

	while (!glfwWindowShouldClose(window)) {
		double now = glfwGetTime();
		accumulator += now - lastTick;
		lastTick = now;

		glfwPollEvents();

		while (accumulator >= tickSeconds) {
			game->Update();
			accumulator -= tickSeconds;
		}

		glClear(GL_COLOR_BUFFER_BIT);
		game->Draw();
		glCullFace(GL_FRONT);
		glfwSwapBuffers(window);
	}

	glfwDestroyWindow(window);
	window = nullptr;
	glfwTerminate();
}

