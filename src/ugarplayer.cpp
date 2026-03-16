#include "ugar_io_opengl/ugarplayer.h"
#include "ugar_io_opengl/GameWindow.h"
#include "ugar_io_opengl/ugar.h"
#include "ugar_io_opengl/Vector2.h"

UgarPlayer::UgarPlayer()
    : Ugar() {
}

UgarPlayer::UgarPlayer(const Vector2& _position, float _radius)
    : Ugar(_position, _radius) {
}

UgarPlayer::~UgarPlayer() {
}

void UgarPlayer::Update() {
    Ugar::Update();
    KeyboardEvent();
    if (upKey) {
        if (leftKey) MoveDirection(135.0f);
        else if (rightKey) MoveDirection(45.0f);
        else MoveDirection(90.0f);
    }
    else if (downKey) {
        if (leftKey) MoveDirection(225.0f);
        else if (rightKey) MoveDirection(315.0f);
        else MoveDirection(270.0f);
    }
    else if (leftKey) {
        if (upKey) MoveDirection(135.0f);
        else if (downKey) MoveDirection(225.0f);
        else MoveDirection(180.0f);
    }
    else if (rightKey) {
        if (upKey) MoveDirection(45.0f);
        else if (downKey) MoveDirection(315.0f);
        else MoveDirection(0.0f);
    }
}

void UgarPlayer::KeyboardEvent() {
    upKey = GameWindow::IsKeyPressed(UP_KEY);
    downKey = GameWindow::IsKeyPressed(DOWN_KEY);
    leftKey = GameWindow::IsKeyPressed(LEFT_KEY);
    rightKey = GameWindow::IsKeyPressed(RIGHT_KEY);
}
