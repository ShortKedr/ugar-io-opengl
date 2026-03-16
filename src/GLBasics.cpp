#include "ugar_io_opengl/GLBasics.h"
#include "ugar_io_opengl/Color.h"
#include <GLFW/glfw3.h>
#include <cmath>
#include <cstring>
#include <numbers>

void GLBasics::DrawCircle(float x, float y, float radius, Color* color, int segments)
{
	const Color c = color->normalized();
	glColor3f(c.r, c.g, c.b);

	float drawX = 0.0f;
	float drawY = 0.0f;

	glBegin(GL_POLYGON);
	float step = 360.0f / (float)segments;
	for (int i = 0; i < segments; i++) {
		const float angle = (i * step) * (std::numbers::pi_v<float> / 180.0f);
		drawX = x + std::cos(angle) * radius;
		drawY = y + std::sin(angle) * radius;
		glVertex2f(drawX, drawY);
	}
	glEnd();
}

void GLBasics::DrawLine(float x1, float y1, float x2, float y2, Color * color)
{
	const Color c = color->normalized();
	glColor3f(c.r, c.g, c.b);
	glBegin(GL_LINES);
	glVertex2f(x1, y1);
	glVertex2f(x2, y2);
	glEnd();
}

void GLBasics::DrawStartText(float x, float y, Color* color, float a, float scale) {

	char text[] = "Press Space to Play"; // length 19 
	float letterWidth = 25.0f * scale;
	float letterHeight = 40.0f * scale;
	float letterOffset = 4;

	const std::size_t textLength = std::strlen(text);
	float width = (letterWidth + letterOffset) * static_cast<float>(textLength) - letterOffset;
	float height = letterHeight;

	const Color c = color->normalized();
	glColor4f(c.r, c.g, c.b, a);

	for (std::size_t i = 0; i < textLength; i++) {
		if (text[i] == ' ') continue;
		float zx = x - width / 2 + static_cast<float>(i) * (letterWidth + letterOffset);
		float zy = y - letterHeight / 2;
		float width = letterWidth;
		float height = letterHeight;

		switch (text[i]) {
		case 'P':
			glBegin(GL_POLYGON);
			glVertex2f(zx, zy);
			glVertex2f(zx + width / 4.0, zy);
			glVertex2f(zx + width / 4.0, zy + height);
			glVertex2f(zx, zy + height);
			glEnd();

			glBegin(GL_POLYGON);
			glVertex2f(zx + width / 4.0*3.0, zy + height / 5.0);
			glVertex2f(zx + width, zy + height / 5.0);
			glVertex2f(zx + width, zy + height / 5.0*2.0);
			glVertex2f(zx + width / 4.0*3.0, zy + height / 5.0*2.0);
			glEnd();

			glBegin(GL_POLYGON);
			glVertex2f(zx + width / 4.0, zy);
			glVertex2f(zx + width, zy);
			glVertex2f(zx + width, zy + height / 5.0);
			glVertex2f(zx + width / 4.0, zy + height / 5.0);
			glEnd();

			glBegin(GL_POLYGON);
			glVertex2f(zx + width / 4.0, zy + height / 5.0*2.0);
			glVertex2f(zx + width, zy + height / 5.0*2.0);
			glVertex2f(zx + width, zy + height / 5.0*3.0);
			glVertex2f(zx + width / 4.0, zy + height / 5.0*3.0);
			glEnd();
			break;
		case 'r':
			zy += height / 3.0;
			height = height / 3.0*2.0;

			glBegin(GL_POLYGON);
			glVertex2f(zx, zy);
			glVertex2f(zx + width / 4.0, zy);
			glVertex2f(zx + width / 4.0, zy + height);
			glVertex2f(zx, zy + height);
			glEnd();

			glBegin(GL_POLYGON);
			glVertex2f(zx + width / 4.0, zy + height / 4.0);
			glVertex2f(zx + width / 2.0, zy);
			glVertex2f(zx + width, zy);
			glVertex2f(zx + width, zy + height / 4.0);
			glVertex2f(zx + width / 2.0, zy + height / 4.0);
			glVertex2f(zx + width / 4.0, zy + height / 4.0*2.0);
			glEnd();
			break;
		case 'e':
			zy += height / 3.0;
			height = height / 3.0*2.0;

			glBegin(GL_POLYGON);
			glVertex2f(zx, zy);
			glVertex2f(zx + width / 4.0, zy);
			glVertex2f(zx + width / 4.0, zy + height);
			glVertex2f(zx, zy + height);
			glEnd();

			glBegin(GL_POLYGON);
			glVertex2f(zx + width / 4.0, zy);
			glVertex2f(zx + width, zy);
			glVertex2f(zx + width, zy + height / 5.0);
			glVertex2f(zx + width / 4.0, zy + height / 5.0);
			glEnd();

			glBegin(GL_POLYGON);
			glVertex2f(zx + width / 4.0, zy + height / 5.0*2.0);
			glVertex2f(zx + width, zy + height / 5.0*2.0);
			glVertex2f(zx + width, zy + height / 5.0*3.0);
			glVertex2f(zx + width / 4.0, zy + height / 5.0*3.0);
			glEnd();

			glBegin(GL_POLYGON);
			glVertex2f(zx + width / 4.0, zy + height / 5.0*4.0);
			glVertex2f(zx + width, zy + height / 5.0*4.0);
			glVertex2f(zx + width, zy + height / 5.0*5.0);
			glVertex2f(zx + width / 4.0, zy + height / 5.0*5.0);
			glEnd();

			break;
		case 'S':

			glBegin(GL_POLYGON);
			glVertex2f(zx, zy + height / 5.0);
			glVertex2f(zx + width / 4.0, zy + height / 5.0);
			glVertex2f(zx + width / 4.0, zy + height / 5.0*2.0);
			glVertex2f(zx, zy + height / 5.0*2.0);
			glEnd();

			glBegin(GL_POLYGON);
			glVertex2f(zx + width / 4.0*3.0, zy + height / 5.0*3.0);
			glVertex2f(zx + width, zy + height / 5.0*3.0);
			glVertex2f(zx + width, zy + height / 5.0*4.0);
			glVertex2f(zx + width / 4.0*3.0, zy + height / 5.0*4.0);
			glEnd();

			glBegin(GL_POLYGON);
			glVertex2f(zx, zy);
			glVertex2f(zx + width, zy);
			glVertex2f(zx + width, zy + height / 5.0);
			glVertex2f(zx, zy + height / 5.0);
			glEnd();

			glBegin(GL_POLYGON);
			glVertex2f(zx, zy + height / 5.0*2.0);
			glVertex2f(zx + width, zy + height / 5.0*2.0);
			glVertex2f(zx + width, zy + height / 5.0*3.0);
			glVertex2f(zx, zy + height / 5.0*3.0);
			glEnd();

			glBegin(GL_POLYGON);
			glVertex2f(zx, zy + height / 5.0*4.0);
			glVertex2f(zx + width, zy + height / 5.0*4.0);
			glVertex2f(zx + width, zy + height / 5.0*5.0);
			glVertex2f(zx, zy + height / 5.0*5.0);
			glEnd();
			break;
		case 's':
			zy += height / 3.0;
			height = height / 3.0*2.0;

			glBegin(GL_POLYGON);
			glVertex2f(zx, zy + height / 5.0);
			glVertex2f(zx + width / 4.0, zy + height / 5.0);
			glVertex2f(zx + width / 4.0, zy + height / 5.0*2.0);
			glVertex2f(zx, zy + height / 5.0*2.0);
			glEnd();

			glBegin(GL_POLYGON);
			glVertex2f(zx + width / 4.0*3.0, zy + height / 5.0*3.0);
			glVertex2f(zx + width, zy + height / 5.0*3.0);
			glVertex2f(zx + width, zy + height / 5.0*4.0);
			glVertex2f(zx + width / 4.0*3.0, zy + height / 5.0*4.0);
			glEnd();

			glBegin(GL_POLYGON);
			glVertex2f(zx, zy);
			glVertex2f(zx + width, zy);
			glVertex2f(zx + width, zy + height / 5.0);
			glVertex2f(zx, zy + height / 5.0);
			glEnd();

			glBegin(GL_POLYGON);
			glVertex2f(zx, zy + height / 5.0*2.0);
			glVertex2f(zx + width, zy + height / 5.0*2.0);
			glVertex2f(zx + width, zy + height / 5.0*3.0);
			glVertex2f(zx, zy + height / 5.0*3.0);
			glEnd();

			glBegin(GL_POLYGON);
			glVertex2f(zx, zy + height / 5.0*4.0);
			glVertex2f(zx + width, zy + height / 5.0*4.0);
			glVertex2f(zx + width, zy + height / 5.0*5.0);
			glVertex2f(zx, zy + height / 5.0*5.0);
			glEnd();
			break;
		case 'a':
			zy += height / 3.0;
			height = height / 3.0*2.0;

			glBegin(GL_POLYGON);
			glVertex2f(zx, zy);
			glVertex2f(zx + width / 4.0, zy);
			glVertex2f(zx + width / 4.0, zy + height);
			glVertex2f(zx, zy + height);
			glEnd();

			glBegin(GL_POLYGON);
			glVertex2f(zx + width / 4.0*3.0, zy);
			glVertex2f(zx + width, zy);
			glVertex2f(zx + width, zy + height);
			glVertex2f(zx + width / 4.0*3.0, zy + height);
			glEnd();

			glBegin(GL_POLYGON);
			glVertex2f(zx + width / 4.0, zy);
			glVertex2f(zx + width / 4.0*3.0, zy);
			glVertex2f(zx + width / 4.0*3.0, zy + height / 5.0);
			glVertex2f(zx + width / 4.0, zy + height / 5.0);
			glEnd();

			glBegin(GL_POLYGON);
			glVertex2f(zx + width / 4.0, zy + height / 5.0*2.0);
			glVertex2f(zx + width / 4.0*3.0, zy + height / 5.0*2.0);
			glVertex2f(zx + width / 4.0*3.0, zy + height / 5.0*3.0);
			glVertex2f(zx + width / 4.0, zy + height / 5.0*3.0);
			glEnd();
			break;
		case 'p':
			zy += height / 3.0;
			height = height / 3.0*2.0;

			glBegin(GL_POLYGON);
			glVertex2f(zx, zy);
			glVertex2f(zx + width / 4.0, zy);
			glVertex2f(zx + width / 4.0, zy + height);
			glVertex2f(zx, zy + height);
			glEnd();

			glBegin(GL_POLYGON);
			glVertex2f(zx + width / 4.0*3.0, zy + height / 5.0);
			glVertex2f(zx + width, zy + height / 5.0);
			glVertex2f(zx + width, zy + height / 5.0*2.0);
			glVertex2f(zx + width / 4.0*3.0, zy + height / 5.0*2.0);
			glEnd();

			glBegin(GL_POLYGON);
			glVertex2f(zx + width / 4.0, zy);
			glVertex2f(zx + width, zy);
			glVertex2f(zx + width, zy + height / 5.0);
			glVertex2f(zx + width / 4.0, zy + height / 5.0);
			glEnd();

			glBegin(GL_POLYGON);
			glVertex2f(zx + width / 4.0, zy + height / 5.0*2.0);
			glVertex2f(zx + width, zy + height / 5.0*2.0);
			glVertex2f(zx + width, zy + height / 5.0*3.0);
			glVertex2f(zx + width / 4.0, zy + height / 5.0*3.0);
			glEnd();
			break;
		case 'c':
			zy += height / 3.0;
			height = height / 3.0*2.0;

			glBegin(GL_POLYGON);
			glVertex2f(zx, zy);
			glVertex2f(zx + width / 4.0, zy);
			glVertex2f(zx + width / 4.0, zy + height);
			glVertex2f(zx, zy + height);
			glEnd();

			glBegin(GL_POLYGON);
			glVertex2f(zx + width / 4.0, zy);
			glVertex2f(zx + width, zy);
			glVertex2f(zx + width, zy + height / 5.0);
			glVertex2f(zx + width / 4.0, zy + height / 5.0);
			glEnd();

			glBegin(GL_POLYGON);
			glVertex2f(zx + width / 4.0, zy + height / 5.0*4.0);
			glVertex2f(zx + width, zy + height / 5.0*4.0);
			glVertex2f(zx + width, zy + height / 5.0*5.0);
			glVertex2f(zx + width / 4.0, zy + height / 5.0*5.0);
			glEnd();
			break;
		case 't':
			zy += height / 3.0;
			height = height / 3.0*2.0;

			glBegin(GL_POLYGON);
			glVertex2f(zx, zy);
			glVertex2f(zx + width, zy);
			glVertex2f(zx + width, zy + height / 4.0);
			glVertex2f(zx, zy + height / 4.0);
			glEnd();

			glBegin(GL_POLYGON);
			glVertex2f(zx + width / 2.0 - width / 8.0, zy + height / 4.0);
			glVertex2f(zx + width / 2.0 + width / 8.0, zy + height / 4.0);
			glVertex2f(zx + width / 2.0 + width / 8.0, zy + height);
			glVertex2f(zx + width / 2.0 - width / 8.0, zy + height);
			glEnd();
			break;
		case 'o':
			zy += height / 3.0;
			height = height / 3.0*2.0;

			glBegin(GL_POLYGON);
			glVertex2f(zx, zy);
			glVertex2f(zx + width / 4.0, zy);
			glVertex2f(zx + width / 4.0, zy + height);
			glVertex2f(zx, zy + height);
			glEnd();

			glBegin(GL_POLYGON);
			glVertex2f(zx + width / 4.0*3.0, zy + height / 5.0);
			glVertex2f(zx + width, zy + height / 5.0);
			glVertex2f(zx + width, zy + height / 5.0*4.0);
			glVertex2f(zx + width / 4.0*3.0, zy + height / 5.0*4.0);
			glEnd();

			glBegin(GL_POLYGON);
			glVertex2f(zx + width / 4.0, zy);
			glVertex2f(zx + width, zy);
			glVertex2f(zx + width, zy + height / 5.0);
			glVertex2f(zx + width / 4.0, zy + height / 5.0);
			glEnd();

			glBegin(GL_POLYGON);
			glVertex2f(zx + width / 4.0, zy + height / 5.0*4.0);
			glVertex2f(zx + width, zy + height / 5.0*4.0);
			glVertex2f(zx + width, zy + height / 5.0*5.0);
			glVertex2f(zx + width / 4.0, zy + height / 5.0*5.0);
			glEnd();
			break;
		case 'l':
			zy += height / 3.0;
			height = height / 3.0*2.0;

			glBegin(GL_POLYGON);
			glVertex2f(zx + width / 4.0, zy + height / 5.0*4.0);
			glVertex2f(zx + width, zy + height / 5.0*4.0);
			glVertex2f(zx + width, zy + height / 5.0*5.0);
			glVertex2f(zx + width / 4.0, zy + height / 5.0*5.0);
			glEnd();

			glBegin(GL_POLYGON);
			glVertex2f(zx, zy);
			glVertex2f(zx + width / 4.0, zy);
			glVertex2f(zx + width / 4.0, zy + height);
			glVertex2f(zx, zy + height);
			glEnd();


			break;
		case 'y':
			zy += height / 3.0;
			height = height / 3.0*2.0;

			glBegin(GL_POLYGON);
			glVertex2f(zx, zy);
			glVertex2f(zx + width / 4.0, zy);
			glVertex2f(zx + width / 4.0, zy + height / 5.0*3.0);
			glVertex2f(zx, zy + height / 5.0*3.0);
			glEnd();

			glBegin(GL_POLYGON);
			glVertex2f(zx + width / 4.0*3.0, zy);
			glVertex2f(zx + width, zy);
			glVertex2f(zx + width, zy + height / 2.0);
			glVertex2f(zx + width / 4.0*3.0, zy + height / 2.0);
			glEnd();

			glBegin(GL_POLYGON);
			glVertex2f(zx + width / 4.0*3.0, zy + height / 2.0);
			glVertex2f(zx + width, zy + height / 2.0);
			glVertex2f(zx + width, zy + height);
			glVertex2f(zx + width / 4.0*3.0, zy + height);
			glEnd();

			glBegin(GL_POLYGON);
			glVertex2f(zx + width / 4.0, zy + height / 5.0*2.0);
			glVertex2f(zx + width / 4.0*3.0, zy + height / 5.0*2.0);
			glVertex2f(zx + width / 4.0*3.0, zy + height / 5.0*3.0);
			glVertex2f(zx + width / 4.0, zy + height / 5.0*3.0);
			glEnd();

			glBegin(GL_POLYGON);
			glVertex2f(zx, zy + height / 5.0*4.0);
			glVertex2f(zx + width / 4.0*3.0, zy + height / 5.0*4.0);
			glVertex2f(zx + width / 4.0*3.0, zy + height / 5.0*5.0);
			glVertex2f(zx, zy + height / 5.0*5.0);
			glEnd();
			break;
		}

	}
}

