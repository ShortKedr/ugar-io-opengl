#ifndef UGARPLAYER_H
#define UGARPLAYER_H
#include <GL/freeglut.h>
#include "ugar.h"

class UgarPlayer : public Ugar {

public:

    static const int UP_KEY = 'W';
    static const int DOWN_KEY = 'S';
    static const int LEFT_KEY = 'A';
    static const int RIGHT_KEY = 'D';


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
