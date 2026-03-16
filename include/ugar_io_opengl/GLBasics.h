#ifndef GL_BASICS
#define GL_BASICS
#include "ugar_io_opengl/Color.h"
namespace GLBasics {

	void DrawCircle(float x, float y, float radius, Color* color, int segments = 16);
	void DrawLine(float x1, float y1, float x2, float y2, Color* color);
	void DrawStartText(float x, float y, Color* color, float a = 1.0f, float scale = 1.0f);
}

#endif
