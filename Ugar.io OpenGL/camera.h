#ifndef CAMERA_H
#define CAMERA_H
#include "Vector2.h"

class Camera {

public:

    Vector2 *viewportSize = nullptr;
	Vector2 *observedPosition = nullptr;
    float scale = 1.0f;


    Camera();
    Camera(Vector2 *vs, Vector2 *op, float _scale = 1.0f);

    ~Camera();

    float GetNormalXOffset();
    float GetNormalYOffset();

    void SetCamera(Vector2 *vs, Vector2 *op);
    void SetCamera(Vector2 *vs, Vector2 *op, float _scale);

};

#endif // CAMERA_H
