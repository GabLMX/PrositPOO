#include <iostream>
#include <cmath>
#pragma once

class Vector2{
private:
    float x;
    float y;

public:
    Vector2(float x, float y);
    float getxVector2();
    float getyVector2();
    float normVector2();
    float dotVector2(Vector2 r);
    Vector2 dotscalarVector2(float u);
    float crossVector2(Vector2 r);
    Vector2 negateVector2();
};