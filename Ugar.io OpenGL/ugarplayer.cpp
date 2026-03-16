#include "ugarplayer.h"
#include "ugar.h"
#include "Vector2.h"
#include <windows.h>
#include <winuser.h>

UgarPlayer::UgarPlayer()
	: Ugar(){

}

UgarPlayer::UgarPlayer(const Vector2& _position, float _radius)
    : Ugar (_position, _radius) {

}

UgarPlayer::~UgarPlayer() {
}

void UgarPlayer::Update()
{
    Ugar::Update();
	KeyboardEvent();
    if (upKey) {
        if (leftKey) MoveDirection(135.0f);
        else if (rightKey) MoveDirection(45.0f);
        else MoveDirection(90.0f);
    } else if (downKey) {
        if (leftKey) MoveDirection(225.0f);
        else if (rightKey) MoveDirection(315.0f);
        else MoveDirection(270.0f);
    } else if (leftKey) {
        if (upKey) MoveDirection(135.0f);
        else if (downKey) MoveDirection(225.0f);
        else MoveDirection(180.0f);
    } else if (rightKey) {
        if (upKey) MoveDirection(45.0f);
        else if (downKey) MoveDirection(315.0f);
        else MoveDirection(0.0f);
    }
}

void UgarPlayer::KeyboardEvent()
{
	if (GetAsyncKeyState(UP_KEY) < 0) upKey = true;
	else upKey = false;

	if (GetAsyncKeyState(DOWN_KEY) < 0) downKey = true;
	else downKey = false;

	if (GetAsyncKeyState(LEFT_KEY) < 0) leftKey = true;
	else leftKey = false;

	if (GetAsyncKeyState(RIGHT_KEY) < 0) rightKey = true;
	else rightKey = false;
}
