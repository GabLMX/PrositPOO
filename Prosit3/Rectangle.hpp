#include <iostream>
#pragma once

#include "Polygone.hpp"

class Rectangle : public Polygone{
private:
    double largeur;
    double longueur;
public:
    Rectangle(double la, double lo);
    void setLargeur(double la);
    double getLargeur();
    void setLongueur(double lo);
    double getLongueur();
    double aire() override;
    double perimetre() override;
    void afficherInfo() override;
};