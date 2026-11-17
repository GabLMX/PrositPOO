#include <iostream>
#pragma once

#include "Objet.hpp" //Appel de la classe parente.

class Cercle : public Objet{
private:
    int rayon;
public:
    Cercle(int r);
    int getRayon();
    void setRayon(int n_r);
    double aire() override;
    double perimetre() override;
    void afficherInfo() override;
};