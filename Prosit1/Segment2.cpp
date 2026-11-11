#include "Segment2.hpp"

#include <iostream>
#include <cmath>

Segment2::Segment2(Point2 origin, Vector2 direction)
    : origin(origin), direction(direction)
{
    //Supposément il faut initialiser le point d'origine et le vecteur de direction comme des "membres".
}

Point2 Segment2::getOriginSegment2(){
    return origin;
}

Vector2 Segment2::getDirectionSegment2(){
    return direction;
}

float Segment2::lengthSegment2(){
    return direction.Vector2::normVector2();
}

std::string Segment2::intersectSegment2(Segment2 s, Segment2 r, Point2 &p){
    Point2 oa = s.getOriginSegment2(), ob = r.getOriginSegment2();
    Vector2 da = s.getDirectionSegment2(), db = r.getDirectionSegment2();
    Vector2 dc = ob.subPoint2(oa);

    std::string state;

    float det = da.crossVector2(db);
    if (det != 0){
        float u, v;

        u = dc.crossVector2(db) / det;
        v = dc.crossVector2(da) / det;
        if ((u >= 0.0 and u <= 1.0) and (v >= 0.0 and v <= 1.0)){
            Vector2 temp = da.dotscalarVector2(u);
            p = oa.addPoint2(temp);
            state = "Point";
        }
        else{
            state = "NonIntersecting";
        }
    }

    else{

        float st = dc.crossVector2(da);
        
        if (st == 0.0) {
            float pj, d1, d2;

            pj = da.dotVector2(da);
            d1 = dc.dotVector2(da) / pj;
            d2 = d1 + db.dotVector2(da) / pj;

            if (d1 >= 0.0 && d1 <= 1.0) {
                p = ob;
                state = "ColinearIntersecting";
            } else if (d2 >= 0.0 && d2 <= 1.0) {
                Point2 temp_ob_db = ob.addPoint2(db);
                p = temp_ob_db;
                state = "ColinearIntersecting";
            } else {
                state = "ColinearNonIntersecting";
            }
        }

        else{
            state = "ParallelNonIntersecting";
        }

    }

    return state;
}