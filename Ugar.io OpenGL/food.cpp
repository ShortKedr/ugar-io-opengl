#include "Vector2.h"
#include "Color.h"
#include "food.h"
#include <cstdlib>
#include <cmath>
#include <numbers>
#include "GLBasics.h"

Food::Food() {
	radius = 0.0f;
    position = new Vector2();
    color = new Color(0, 0, 0);
    drawingRect = new RectF(0, 0 ,0 ,0);
}

Food::Food(float _radius, Vector2 *_position)
{
    position = new Vector2();
    drawingRect = new RectF(0, 0 ,0 ,0);

    color = new Color(std::rand() % 50, std::rand() % 50, std::rand() % 50);
    radius = _radius;
    *position = *_position;
}

Food::~Food()
{
    if (position) delete position;
    if (color) delete color;
    if (drawingRect) delete drawingRect;
}

void Food::UpdateDrawingRect(float xoffset, float yoffset, float scale) {
    drawingRect->setX((position->x - radius) * scale - xoffset);
    drawingRect->setY((position->y - radius) * scale - yoffset);
    drawingRect->setW(radius * 2.0f * scale);
    drawingRect->setH(radius * 2.0f * scale);
}

float Food::GetSquare()
{
    return std::numbers::pi_v<float> * radius * radius;
}

void Food::SetSquare(float square)
{
    radius = std::sqrt(square / std::numbers::pi_v<float>);
}

void Food::Draw()
{
	GLBasics::DrawCircle(drawingRect->getX() + drawingRect->getW() / 2.0f, drawingRect->getY() + drawingRect->getH() / 2.0f, drawingRect->getW() / 2.0f, color);
}

