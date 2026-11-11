#include <iostream>
#include <cmath>
#pragma once

#include "Vector2.hpp"
#include "Point2.hpp"

class Segment2{
private:
    Point2 origin;
    Vector2 direction;

public:
    Segment2(Point2 origin, Vector2 direction);
    Point2 getOriginSegment2();
    Vector2 getDirectionSegment2();
    float lengthSegment2();
    std::string intersectSegment2(Segment2 s, Segment2 r, Point2 &p);
};