#ifndef VECTOR2_H
#define VECTOR2_H
class Vector2{

public:
	float x;
	float y;

	Vector2();
	~Vector2();
	Vector2(float _x, float _y);

	friend const Vector2 operator +(const Vector2& first, const Vector2& second);

	friend const Vector2 operator -(const Vector2& first, const Vector2& second);

	friend const Vector2 operator *(const Vector2& first, const float second);

	friend const Vector2 operator /(const Vector2& first, const Vector2& second);
	friend const Vector2 operator /(const Vector2& first, const float second);

	friend const bool operator ==(const Vector2& first, const Vector2& second);
	friend const bool operator !=(const Vector2& first, const Vector2& second);

    static const Vector2 zero();
};
#endif

