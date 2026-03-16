#include "game.h"
#include <ctime>
#include <cstdlib>
#include "Color.h"
#include "ugar.h"
#include "ugarai.h"
#include "ugarplayer.h"
#include <GL/freeglut.h>
#include "GLBasics.h"
#include <iostream>

const char* Game::START_GAME_LABEL = "Press any key to PLAY";
const float Game::FONT_SIZE= 20;
const float Game::GAME_FIELD_WIDTH = 4000;
const float Game::GAME_FIELD_HEIGHT = 4000;
const float Game::CAMERA_LERP= 0.05f;
const float Game::SCALE_LERP= 0.05f;
const float Game::NORMAL_SCALE_RESOLUTION= 768.0f;
const float Game::NORMAL_SCALE_RADIUS= 60.0f;

Game::Game()
{
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    isStarted = false;
	objectControlTimer = 0;

    cam = new Camera(new Vector2(640, 480), new Vector2(320, 240), 1.0f);

    for (int i = 0; i < VERT_LINE_AMOUNT; i++) {
        Color *color = (i == 0 || i == VERT_LINE_AMOUNT - 1) ? new Color(0, 0, 0) : new Color(240, 240, 240);
        vertLines[i] = new Line(new Vector2((i*200), 0), new Vector2((i*200), 4000.0), color);
    }

    for (int i = 0; i < HORZ_LINE_AMOUNT; i++) {
        Color *color = (i == 0 || i == HORZ_LINE_AMOUNT - 1) ? new Color(0, 0, 0) : new Color(240, 240, 240);
        horzLines[i] = new Line(new Vector2(0, (i*200)), new Vector2(4000.0, (i*200)), color);
    }

    if (isStarted) ugars[0] = new UgarPlayer(new Vector2(std::rand() % (int)(GAME_FIELD_WIDTH/2.0f) + GAME_FIELD_WIDTH/2.0f, std::rand() % (int)(GAME_FIELD_HEIGHT/2.0f) + GAME_FIELD_HEIGHT/2.0f), 5.0f);
	else ugars[0] = nullptr;
	for (int i = 1; i < UGAR_AMOUNT; i++){
        ugars[i] = new UgarAI(new Vector2(std::rand() % (int)(GAME_FIELD_WIDTH/2.0f) + GAME_FIELD_WIDTH/2.0f, std::rand() % (int)(GAME_FIELD_HEIGHT/2.0f) + GAME_FIELD_HEIGHT/2.0f), 5.0f);
        static_cast<UgarAI*>(ugars[i])->AssignAIData(foods, FOOD_AMOUNT, ugars, UGAR_AMOUNT);
    }
    for (int i = 0; i < FOOD_AMOUNT; i++){
        foods[i] = new Food(2.0f, new Vector2(std::rand() % (int)(GAME_FIELD_WIDTH), std::rand() % (int)(GAME_FIELD_HEIGHT)));
    }
}

Game::~Game()
{
    delete cam;
    for (int i = 0; i < UGAR_AMOUNT; i++)
        delete ugars[i];
    for (int i = 0; i < FOOD_AMOUNT; i++)
        delete foods[i];
    for (int i = 0; i < VERT_LINE_AMOUNT; i++)
        delete vertLines[i];
    for (int i = 0; i < HORZ_LINE_AMOUNT; i++)
        delete horzLines[i];
}

void Game::Update()
{

    if (ugars[0] != nullptr && isStarted){
        cam->observedPosition->x = cam->observedPosition->x + (ugars[0]->position->x - cam->observedPosition->x) * CAMERA_LERP;
        cam->observedPosition->y = cam->observedPosition->y + (ugars[0]->position->y - cam->observedPosition->y) * CAMERA_LERP;

        float requiredScale = 0.0f;
        if (ugars[0]->radius < 60.0f) requiredScale = (cam->viewportSize->y / NORMAL_SCALE_RESOLUTION);
        else requiredScale = (cam->viewportSize->y / NORMAL_SCALE_RESOLUTION) * (NORMAL_SCALE_RADIUS / (int)(ugars[0]->radius));
        cam->scale += (requiredScale - cam->scale) * SCALE_LERP;
    } else if (ugars[1] != nullptr) {
        cam->observedPosition->x = cam->observedPosition->x + (ugars[1]->position->x - cam->observedPosition->x) * CAMERA_LERP;
        cam->observedPosition->y = cam->observedPosition->y + (ugars[1]->position->y - cam->observedPosition->y) * CAMERA_LERP;

        float requiredScale = 0.0f;
        if (ugars[1]->radius < 60.0f) requiredScale = (cam->viewportSize->y / NORMAL_SCALE_RESOLUTION);
        else requiredScale = (cam->viewportSize->y / NORMAL_SCALE_RESOLUTION) * (NORMAL_SCALE_RADIUS / (int)(ugars[1]->radius));
        cam->scale += (requiredScale - cam->scale) * SCALE_LERP;
    }

    for (int i = 0; i < UGAR_AMOUNT; i++){
        if (ugars[i] == nullptr) continue;
        ugars[i]->Update();
        if (ugars[i]->position->x - ugars[i]->radius < 0) ugars[i]->position->x = ugars[i]->radius;
        if (ugars[i]->position->x + ugars[i]->radius > GAME_FIELD_WIDTH) ugars[i]->position->x = GAME_FIELD_WIDTH - ugars[i]->radius;
        if (ugars[i]->position->y - ugars[i]->radius < 0) ugars[i]->position->y = ugars[i]->radius;
        if (ugars[i]->position->y + ugars[i]->radius > GAME_FIELD_HEIGHT) ugars[i]->position->y = GAME_FIELD_HEIGHT - ugars[i]->radius;

        for (int j = 0; j < UGAR_AMOUNT; j++){
            if (ugars[j] == nullptr || ugars[i] == nullptr || ugars[j] == ugars[i]) continue;
            bool isLesser = false;
            if (ugars[i]->CheckCollision(ugars[j], &isLesser)){
                if (isLesser){
                    ugars[j]->SetSquare(ugars[j]->GetSquare() + ugars[i]->GetSquare());
					if (i==0) isStarted = false;
                    if (ugars[i]) delete ugars[i];
                    ugars[i] = nullptr;
                } else {
                    ugars[i]->SetSquare(ugars[j]->GetSquare() + ugars[i]->GetSquare());
					if (j==0) isStarted = false;
                    if (ugars[j]) delete ugars[j];
                    ugars[j] = nullptr;
                }
            }
        }
        for (int j = 0; j < FOOD_AMOUNT; j++){
            if (foods[j] == nullptr) continue;
            if (ugars[i] != nullptr && ugars[i]->CheckFoodCollision(foods[j])) {
                ugars[i]->SetSquare(ugars[i]->GetSquare() + foods[j]->GetSquare());
                if (foods[j]) delete foods[j];
                foods[j] = nullptr;
            }
        }
    }

    if (objectControlTimer > OBJ_CONTROL_UPDATE_TIME){
        ObjectControlUpdate();
        objectControlTimer = 0;
    } else objectControlTimer++;

	for (int i = 0; i < VERT_LINE_AMOUNT; i++) {
		if (vertLines[i] == nullptr) continue;
		vertLines[i]->UpdateDrawableLine(cam->GetNormalXOffset(), cam->GetNormalYOffset(), cam->scale);
	}

	for (int i = 0; i < HORZ_LINE_AMOUNT; i++) {
		if (horzLines[i] == nullptr) continue;
		horzLines[i]->UpdateDrawableLine(cam->GetNormalXOffset(), cam->GetNormalYOffset(), cam->scale);
	}

	for (int i = 0; i < UGAR_AMOUNT; i++) {
		if (ugars[i] == nullptr) continue;
		ugars[i]->UpdateDrawingRect(cam->GetNormalXOffset(), cam->GetNormalYOffset(), cam->scale);
	}

	for (int i = 0; i < FOOD_AMOUNT; i++) {
		if (foods[i] == nullptr) continue;
		foods[i]->UpdateDrawingRect(cam->GetNormalXOffset(), cam->GetNormalYOffset(), cam->scale);
	}

}

void Game::ObjectControlUpdate()
{
    int count = 0;
    for (int i = 0; i < FOOD_AMOUNT; i++) {
        if (foods[i] == nullptr && count < 50) {
            foods[i] = new Food(2.0f, new Vector2(std::rand() % (int)(GAME_FIELD_WIDTH), std::rand() % (int)(GAME_FIELD_HEIGHT)));
            count++;
        }
    }

    count = 0;
    if (ugars[0] == nullptr && isStarted) ugars[0] = new UgarPlayer(new Vector2(std::rand() % (int)(GAME_FIELD_WIDTH/2.0f) + GAME_FIELD_WIDTH/2.0f, std::rand() % (int)(GAME_FIELD_HEIGHT/2.0f) + GAME_FIELD_HEIGHT/2.0f), 5.0f);
    for (int i = 1; i < UGAR_AMOUNT; i++) {
        if (ugars[i] == nullptr && count < 2) {
            ugars[i] = new UgarAI(new Vector2(std::rand() % (int)(GAME_FIELD_WIDTH/2.0f) + GAME_FIELD_WIDTH/2.0f, std::rand() % (int)(GAME_FIELD_HEIGHT/2.0f) + GAME_FIELD_HEIGHT/2.0f), 5.0f);
            static_cast<UgarAI*>(ugars[i])->AssignAIData(foods, FOOD_AMOUNT, ugars, UGAR_AMOUNT);
            count++;
        }
    }
}

bool Game::IsStarted()
{
    return isStarted;
}

void Game::Start()
{
	if (isStarted) return;
    isStarted = true;
	ObjectControlUpdate();
}

void Game::Draw()
{

    for (int i = 0; i < VERT_LINE_AMOUNT; i++){
        if (vertLines[i] == nullptr) continue;
        vertLines[i]->Draw();
    }

    for (int i = 0; i < HORZ_LINE_AMOUNT; i++){
        if (horzLines[i] == nullptr) continue;
        horzLines[i]->Draw();
    }

    for (int i = 0; i < UGAR_AMOUNT; i++){
        if (ugars[i] == nullptr) continue;
		ugars[i]->Draw();
    }

    for (int i = 0; i < FOOD_AMOUNT; i++){
        if (foods[i] == nullptr) continue;
        foods[i]->Draw();
    }

    if (!isStarted){
		Color* textColor = new Color(0, 0, 0);
		GLBasics::DrawStartText(glutGet(GLUT_WINDOW_WIDTH) / 2, 100, textColor);
		GLBasics::DrawStartText(glutGet(GLUT_WINDOW_WIDTH) / 2, 100+2, textColor, 0.25f, 1.015f);
		delete textColor;
    }
}
