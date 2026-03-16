#ifndef LINE_H
#define LINE_H
#include "Vector2.h"
#include "Color.h"

class Line {

public:

    Vector2 start;
    Vector2 end;
    Color color;

    Vector2 drawableStart;
    Vector2 drawableEnd;


    Line();
    Line(const Vector2& _start, const Vector2& _end, const Color& _color);

    ~Line();

    void UpdateDrawableLine(float xoffset, float yoffset, float scale);

	void Draw();

};

#endif // LINE_H
