#ifndef UGARPLAYER_H
#define UGARPLAYER_H
#include <GLFW/glfw3.h>
#include "ugar_io_opengl/ugar.h"

class UgarPlayer : public Ugar {

public:

    static const int UP_KEY = GLFW_KEY_W;
    static const int DOWN_KEY = GLFW_KEY_S;
    static const int LEFT_KEY = GLFW_KEY_A;
    static const int RIGHT_KEY = GLFW_KEY_D;


    UgarPlayer();
    UgarPlayer(const Vector2& _position, float _radius);

    ~UgarPlayer();

    void Update() override;

	void KeyboardEvent();

private:
   bool upKey = false;
   bool downKey = false;
   bool leftKey = false;
   bool rightKey = false;

};

#endif // UGARPLAYER_H

