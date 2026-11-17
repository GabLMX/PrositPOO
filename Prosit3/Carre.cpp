#include <iostream>

#include "Carre.hpp"

Carre::Carre(double c) : cote(c){}

void Carre::setCote(double c){
    cote = c;
}

double Carre::getCote(){
    return cote;
}

double Carre::aire(){
    return (cote*cote);
}

double Carre::perimetre(){
    return (cote*4);
}

void Carre::afficherInfo(){
    std::cout << "Votre carré a un côté de " << cote << ", une aire de " << aire()
    << " et un périmètre de " << perimetre() << ".\n";
}
