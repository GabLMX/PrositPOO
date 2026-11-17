#include <iostream>

#include "Polygone.hpp"

Polygone::Polygone() : sommetx(0), sommety(0){}

void Polygone::set_sommetx(int x){
    sommetx = x;
}

void Polygone::set_sommety(int y){
    sommety = y;
}