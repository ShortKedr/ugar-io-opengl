#ifndef CAMERA_H
#define CAMERA_H
#include "Vector2.h"

class Camera {

public:

    Vector2 viewportSize;
	Vector2 observedPosition;
    float scale = 1.0f;


    Camera();
    Camera(const Vector2& vs, const Vector2& op, float _scale = 1.0f);

    ~Camera();

    float GetNormalXOffset();
    float GetNormalYOffset();

    void SetCamera(const Vector2& vs, const Vector2& op);
    void SetCamera(const Vector2& vs, const Vector2& op, float _scale);

};

#endif // CAMERA_H
