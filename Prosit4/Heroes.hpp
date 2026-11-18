#include <iostream>
#pragma once

#include "Personnage.hpp"

class Heroes : public Personnage{
private:
    std::string name;
    double hp;
    double power;
    int level;
    std::string attribut;
public:
    Heroes(std::string name, double hp, double power, int level, std::string attribut);
    void affiche() override;
    double attaque() override;
    double subitDegat(double degat) override;
    bool estVivant() override;
};