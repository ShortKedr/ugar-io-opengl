#include "ugar_io_opengl/line.h"
#include "ugar_io_opengl/Vector2.h"
#include "ugar_io_opengl/Color.h"
#include "ugar_io_opengl/GLBasics.h"

Line::Line() = default;

Line::Line(const Vector2& _start, const Vector2& _end, const Color& _color)
    : start(_start), end(_end), color(_color) {
}

Line::~Line() = default;

void Line::UpdateDrawableLine(float xoffset, float yoffset, float scale)
{
    drawableStart.x = (start.x * scale) - xoffset;
    drawableStart.y = (start.y * scale) - yoffset;

    drawableEnd.x = (end.x * scale) - xoffset;
    drawableEnd.y = (end.y * scale) - yoffset;
}

void Line::Draw()
{
	GLBasics::DrawLine(drawableStart.x, drawableStart.y, drawableEnd.x, drawableEnd.y, &color);
}

