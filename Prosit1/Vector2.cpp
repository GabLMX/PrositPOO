#include "Vector2.hpp"
#include <iostream>
#include <cmath> //Nécessaire de l'avoir pour .hpp et .cpp pour éviter les problèmes.

Vector2::Vector2(float x, float y){
    this->x = x;
    this->y = y;
}

float Vector2::getxVector2(){
    return x;
}

float Vector2::getyVector2(){
    return y;
}

float Vector2::normVector2(){
    return sqrt(x*x + y*y);
}

float Vector2::dotVector2(Vector2 r){
    return (x * r.x + y * r.y); //Ici, r est un second vecteur.
}

Vector2 Vector2::dotscalarVector2(float u){
    Vector2 resultat(u * x, u * y); //resultat est le nom du vecteur qu'on créer.
    return resultat;
}

float Vector2::crossVector2(Vector2 r){
    return (x * r.y - y * r.x);
}

Vector2 Vector2::negateVector2(){
    Vector2 resultat(x * -1, y * -1);
    return resultat;
}