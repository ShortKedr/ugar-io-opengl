#ifndef UGARAI_H
#define UGARAI_H
#include "ugar.h"

class UgarAI : public Ugar
{
public:
    bool isAgressive = false;

    UgarAI();
    UgarAI(const Vector2& _position, float _radius);

    ~UgarAI();

    void Update() override;
    void AssignAIData(Food **_foods, int _foods_count, Ugar **_ugars, int _ugars_count);

private:
    static const int AGRESSIVE_UPDATE_PERIOD = 15000;
    int agressiveTimer = 0;

    Food **foods = nullptr;
    int foods_count = 0;

    Ugar **ugars = nullptr;
    int ugars_count = 0;


    float pointDist(const Vector2& first, const Vector2& second);
};

#endif // UGARAI_H
