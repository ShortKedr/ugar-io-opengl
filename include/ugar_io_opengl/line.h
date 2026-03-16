#ifndef LINE_H
#define LINE_H
#include "ugar_io_opengl/Vector2.h"
#include "ugar_io_opengl/Color.h"

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

