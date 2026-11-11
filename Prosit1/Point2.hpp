#include <iostream>
#include <cmath>
#pragma once

#include "Vector2.hpp"

class Point2{
private:
    float x;
    float y;

public:
    Point2(float x, float y);
    float getxPoint2();
    float getyPoint2();
    void setxPoint2(float x);
    void setyPoint2(float y);
    void printPoint2();
    Point2 addPoint2(Vector2 r);
    Vector2 subPoint2(Point2 r);
};