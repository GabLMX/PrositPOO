#include <iostream>
#include <cmath>
#pragma once

#include "Polygone.hpp"

class Triangle : public Polygone{
private:
    double ab;
    int angle_ac;
    int angle_bc;
    //Les attributs privés ci-dessous sont calculés dans le constructeur.
    double ac;
    double bc;
    int angle_ab;
public:
    Triangle(double longueurAB, int angleA, int angleB); //Sachant que longueurAB sera "ab", A sera "ac" et "B" bc.
    //Note qu'il n'y a pas de setter, sinon le fichier.cpp sera beaucoup plus "volumineux".
    double aire() override;
    double perimetre() override;
    void afficherInfo() override;
};