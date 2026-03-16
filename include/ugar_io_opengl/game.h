#ifndef GAME_H
#define GAME_H
#include <array>
#include <memory>
#include "ugar_io_opengl/camera.h"
#include "ugar_io_opengl/ugar.h"
#include "ugar_io_opengl/food.h"
#include "ugar_io_opengl/line.h"

class Game {
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
    std::unique_ptr<Camera> cam;
    std::array<std::unique_ptr<Ugar>, UGAR_AMOUNT> ugars;
    std::array<std::unique_ptr<Food>, FOOD_AMOUNT> foods;

    std::array<std::unique_ptr<Line>, VERT_LINE_AMOUNT> vertLines;
    std::array<std::unique_ptr<Line>, HORZ_LINE_AMOUNT> horzLines;

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
    std::array<Ugar*, UGAR_AMOUNT> ugarRefs{};
    std::array<Food*, FOOD_AMOUNT> foodRefs{};

    void SyncUgarRef(int index);
    void SyncFoodRef(int index);
    void SyncAllRefs();
};

#endif // GAME_H
