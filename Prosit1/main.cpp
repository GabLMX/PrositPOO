#include <iostream>
#include <cmath>

#include "Point2.hpp"
#include "Vector2.hpp"
#include "Segment2.hpp"

// Faire "cd Segment2D_Prosit_Classes" dans le Terminal pour pouvoir ensuite faire "g++ main.cpp Point2.cpp Segment2.cpp Vector2.cpp -o program".

int main(void){
    Point2 p1(0.0, 0.0);
    Point2 p2(2.0, 2.0);

    Vector2 v1(1.0, 1.0);
    Vector2 v2(-1.0, -2.0);

    Segment2 s1(p1, v1);
    Segment2 s2(p2, v2);

    std::cout << p1.getxPoint2() << ", " << p1.getyPoint2() << "\n";
    std::cout << "Exactement la même chose mais plus compliqué (et sur l'autre point): " << s2.getOriginSegment2().getxPoint2() << ", " << s2.getOriginSegment2().getyPoint2() << "\n";
}
