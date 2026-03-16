#ifndef UGAR_H
#define UGAR_H
#include "Vector2.h"
#include "RectF.h"
#include "Color.h"
#include "food.h"

class Ugar {

public:

    Vector2 *position = nullptr;

    float radius = 0.5f;
    float showedRadius = 0.5f;

    Vector2 *currentSpeed = nullptr;
    float currentSpeedInc = 0.5f;

    Color *color = nullptr;

    RectF *drawingRect = nullptr;


    Ugar();
    Ugar(Vector2 *_position, float _radius);
    virtual ~Ugar();

    virtual void Update();
    void UpdateSize();
    void UpdateDrawingRect(float xoffset, float yoffset, float scale);
    void UpdateSpeedInc();

    bool CheckCollision(Ugar *target, bool *isLesser);
    bool CheckFoodCollision(Food *target);

    void SetPosition(float x, float y);

    void Move(float x, float y);
    void MoveDirection(float direction);

    float GetSquare();
    void SetSquare(float square);
	void Draw();

private:
    static const bool INVERT_X = false;
    static const bool INVERT_Y = true;

    static const float COLLISION_DISTANCE;
    static const float U_DIFFERENCE;
    static const float SIZE_LERP;

    static const float FRICTION;

	static const float MAX_SPEED_INC;
	static const float MAX_SPEED_SIZE_DEC;
	static const float SPEED_SIZE_DEC;

};

#endif // UGAR_H
