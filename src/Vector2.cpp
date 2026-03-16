#include "ugar_io_opengl/Vector2.h"

Vector2::Vector2()
{
	x = 0.0f;
	y = 0.0f;
}

Vector2::~Vector2(){
	
}

Vector2::Vector2(float _x, float _y)
{
	x = _x;
	y = _y;
}

const Vector2 Vector2::zero() {
	return Vector2(0.0f, 0.0f);
}

const Vector2 operator+(const Vector2 & first, const Vector2 & second)
{
	return Vector2(first.x+second.x, first.y+second.y);
}

const Vector2 operator-(const Vector2 & first, const Vector2 & second)
{
	return Vector2(first.x-second.x, first.y-second.y);
}

const Vector2 operator*(const Vector2 & first, const float second)
{
	return Vector2(first.x*second, first.y*second);
}

const Vector2 operator/(const Vector2 & first, const Vector2 & second)
{
	return Vector2(first.x/second.x, first.y/second.y);
}

const Vector2 operator/(const Vector2 & first, const float second)
{
	return Vector2(first.x/second, first.y/second);
}

const bool operator==(const Vector2 & first, const Vector2 & second)
{
	return first.x==second.x && first.y == second.y;
}

const bool operator!=(const Vector2 & first, const Vector2 & second)
{
	return first.x != second.x || first.y != second.y;
}

