#include <iostream>

#include "Heroes.hpp"

Heroes::Heroes(std::string name, double hp, double power, int level, std::string attribut)
: name(name), hp(hp), power(power), level(level), attribut(attribut)
{}

void Heroes::affiche(){
    std::cout << "Il s'agit de " << name << " avec " << hp << " points de vie et une puissance de "
    << power << " au niveau " << level << ". Ces attaques sont de type " << attribut << ".\n";
}

double Heroes::attaque(){
    double formula = ((power*0.5)*(level*0.75) + 1);
    std::cout << name << " attaque avec son attribut " << attribut << " pour " << formula << " dégâts!\n";
    return formula;
} //Sinon il faut créer un string; le premier char est l'attribut et donne un multiplieur, le reste sont les dégâts.

//Ici degat est trouvé en appelant attaque().
double Heroes::subitDegat(double degat){
    hp -= degat;
    return hp;
}

bool Heroes::estVivant(){
    if(hp > 0){
        hp = -1;
    }
    return (hp > 0);
}