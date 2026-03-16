#ifndef LINE_H
#define LINE_H
#include "Vector2.h"
#include "Color.h"

class Line {

public:

    Vector2 *start = nullptr;
    Vector2 *end = nullptr;
    Color *color = nullptr;

    Vector2* drawableStart = nullptr;
    Vector2* drawableEnd = nullptr;


    Line();
    Line(Vector2 *_start, Vector2 *_end, Color *_color);

    ~Line();

    void UpdateDrawableLine(float xoffset, float yoffset, float scale);

	void Draw();

};

#endif // LINE_H
