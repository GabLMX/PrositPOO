#include <iostream>
#include <cmath>

#include "Cercle.hpp"

Cercle::Cercle(int r) : rayon(r){}

int Cercle::getRayon(){
    return rayon;
}

void Cercle::setRayon(int n_r){
    rayon = n_r;
}

double Cercle::aire(){
    return (M_PI*rayon);
}

double Cercle::perimetre(){
    return (M_PI * (2*getRayon()));
}

void Cercle::afficherInfo(){
    std::cout << "Votre cercle a un rayon de: " << rayon << ", une aire de " << aire() << " et un périmètre de " << perimetre()
    << ".\n";
}