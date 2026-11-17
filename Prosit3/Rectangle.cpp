#include <iostream>

#include "Rectangle.hpp"

Rectangle::Rectangle(double la, double lo) : largeur(la), longueur(lo){}

void Rectangle::setLargeur(double la){
    largeur = la;
}

double Rectangle::getLargeur(){
    return largeur;
}

void Rectangle::setLongueur(double lo){
    longueur = lo;
}

double Rectangle::getLongueur(){
    return longueur;
}

double Rectangle::aire(){
    return (largeur*longueur);
}

double Rectangle::perimetre(){
    return (2*largeur + 2*longueur);
}

void Rectangle::afficherInfo(){
    std::cout << "Votre rectangle a une longueur et largeur de " << longueur << " et " << largeur << " respectivement."
    << " Son aire est de " << aire() << " et le périmètre " << perimetre() << ".\n";
}