#include <iostream>
#pragma once

#include "Polygone.hpp"

class Carre : public Polygone{
private:
    double cote;
public:
    Carre(double c);
    void setCote(double c);
    double getCote();
    double aire() override;
    double perimetre() override;
    void afficherInfo() override;
};