#ifndef FOOD_H
#define FOOD_H
#include "Vector2.h"
#include "Color.h"
#include "RectF.h"

class Food {
public:

    float radius = 0.5f;
    Vector2 *position = nullptr;
    Color *color = nullptr;

    RectF *drawingRect = nullptr;


    Food();
    Food(float _radius, Vector2 *_position);

    ~Food();

    void UpdateDrawingRect(float xoffset, float yoffset, float scale);

    float GetSquare();
    void SetSquare(float square);

    void Draw();

};

#endif // FOOD_H
