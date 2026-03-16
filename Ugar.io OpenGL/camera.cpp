#include "camera.h"

Camera::Camera() = default;

Camera::Camera(const Vector2& vs, const Vector2& op, float _scale)
{
    viewportSize = vs;
    observedPosition = op;
    scale = _scale;
}

Camera::~Camera() = default;

float Camera::GetNormalXOffset()
{
    return observedPosition.x * scale - (viewportSize.x / 2.0f);
}

float Camera::GetNormalYOffset()
{
    return observedPosition.y * scale - (viewportSize.y / 2.0f);
}

void Camera::SetCamera(const Vector2& vs, const Vector2& op)
{
    viewportSize = vs;
    observedPosition = op;
}

void Camera::SetCamera(const Vector2& vs, const Vector2& op, float _scale)
{
    viewportSize = vs;
    observedPosition = op;
    scale = _scale;
}
