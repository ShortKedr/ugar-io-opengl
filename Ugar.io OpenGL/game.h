#ifndef GAME_H
#define GAME_H
#include "camera.h"
#include "ugar.h"
#include "food.h"
#include "line.h"

class Game
{
    static const char* START_GAME_LABEL;
    static const float FONT_SIZE;

    static const float GAME_FIELD_WIDTH;
    static const float GAME_FIELD_HEIGHT;

    static const int UGAR_AMOUNT = 75;
    static const int FOOD_AMOUNT = 750;

    static const int VERT_LINE_AMOUNT = 21;
    static const int HORZ_LINE_AMOUNT = 21;

    static const float CAMERA_LERP;
    static const float SCALE_LERP;

    static const float NORMAL_SCALE_RESOLUTION;
    static const float NORMAL_SCALE_RADIUS;

public:

	Camera* cam;
    Ugar* ugars[UGAR_AMOUNT];
    Food* foods[FOOD_AMOUNT];

    Line* vertLines[VERT_LINE_AMOUNT];
    Line* horzLines[HORZ_LINE_AMOUNT];

    Game();
    ~Game();

    void ObjectControlUpdate();
    bool IsStarted();
    void Start();

    void Update();
    void Draw();

private:
    static const int OBJ_CONTROL_UPDATE_TIME = 300;
    int objectControlTimer = 0;
    bool isStarted = false;
};

#endif // GAME_H
