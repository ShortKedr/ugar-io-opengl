#ifndef FOOD_H
#define FOOD_H
#include "ugar_io_opengl/Vector2.h"
#include "ugar_io_opengl/Color.h"
#include "ugar_io_opengl/RectF.h"

class Food {
public:
    float radius = 0.5f;
    Vector2 position;
    Color color;

    RectF drawingRect;


    Food();
    Food(float _radius, const Vector2& _position);

    ~Food();

    void UpdateDrawingRect(float xoffset, float yoffset, float scale);

    float GetSquare();
    void SetSquare(float square);

    void Draw();
};

#endif // FOOD_H
