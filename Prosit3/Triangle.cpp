#include <iostream>
#include <cmath> //Pour utiliser sinus.

#include "Triangle.hpp"

//Demande 1 longueur et 2 angles pour calculer le dernier angle et les deux longueurs manquantes; ac et bc.
//On a donc: ab, ac, bc, angle ab, angle ac, angle bc.
Triangle::Triangle(double longueurAB, int angleA, int angleB) : ab(longueurAB), angle_ac(angleA), angle_bc(angleB){
    angle_ab = 180 - (angle_ac + angle_bc);

    if(angle_ab > 0 && angle_ac > 0 && angle_bc > 0 && ab > 0){
        double sinC = sin(angle_ab*M_PI / 180.0); //Où M_PI = 3.1415...
        ac = ab*(sin(angle_bc*M_PI / 180.0) / sinC);
        bc = ab*(sin(angle_ac*M_PI / 180.0) / sinC);
        //Sachant que "ab," "ac" et "bc" sont des valeurs privés dans Triangle.hpp.
    }
    else{
        //Dans ce cas, le triangle n'est pas valide et sera "corrompu".
        ac = 0.0;
        bc = 0.0;
    }
}

double Triangle::aire(){
    //J'utilise la formule de Héron pour pouvoir calculer, car je ne sais pas la hauteur.
    double p = (ab + bc + ac)/2; //Ou 2.0.
    return (sqrt(p*(p-ab) * (p-ac) * (p-bc)));
}

double Triangle::perimetre(){
    return (ab + ac + bc);
}

void Triangle::afficherInfo(){
    std::cout << "Votre triangle a les longueurs (ab, ac, bc): " << ab << ", " << ac << " et " << bc
    << ". Son aire est de " << aire() << " avec un périmètre de " << perimetre() << ".\n";
}