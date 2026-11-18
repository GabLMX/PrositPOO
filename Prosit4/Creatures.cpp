#include <iostream>

#include "Creatures.hpp"

Creatures::Creatures(double hp, double power, int level, std::string attribut)
: hp(hp), power(power), level(level), attribut(attribut)
{}

void Creatures::affiche(){
    std::cout << "Il s'agit d'une créature avec " << hp << " points de vie et une puissance de "
    << power << " au niveau " << level << ". Ces attaques sont de type " << attribut << ".\n";
}

double Creatures::attaque(){
    double formula = ((power*0.5)*(level*0.75) + 1);
    std::cout << "La créature attaque avec son attribut " << attribut << " pour " << formula << " dégâts!\n";
    return formula;
}

double Creatures::subitDegat(double degat){
    hp -= degat;
    return hp;
}

bool Creatures::estVivant(){
    if(hp > 0){
        hp = -1;
    }
    return (hp > 0);
}