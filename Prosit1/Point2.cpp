#include "Point2.hpp"
#include "Vector2.hpp"
#include <iostream>
#include <cmath>

Point2::Point2(float x, float y){
    this->x = x;
    this->y = y;
}

float Point2::getxPoint2(){
    return x;
}

float Point2::getyPoint2(){
    return y;
}

void Point2::setxPoint2(float x){
    this->x = x;
}

void Point2::setyPoint2(float y){
    this->y = y;
}

void Point2::printPoint2(){
    std::cout << "Le point a pour coordonnées: " << "(" << x << "," << y << ")" << "\n";
}

Point2 Point2::addPoint2(Vector2 r){
    Point2 resultat(getxPoint2() + r.getxVector2(), getyPoint2() + r.getyVector2()); //Utilise des getters
    return resultat;
}

Vector2 Point2::subPoint2(Point2 r){ //Utilise deux points.
    Vector2 resultat(getxPoint2() - r.getxPoint2(), getyPoint2() - r.getyPoint2());
    return resultat;
}