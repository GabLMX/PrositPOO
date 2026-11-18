#include <iostream>
#pragma once

#include "Personnage.hpp"

class Creatures : public Personnage{
private:
    double hp;
    double power;
    int level;
    std::string attribut;
public:
    Creatures(double hp, double power, int level, std::string attribut);
    void affiche() override;
    double attaque() override;
    double subitDegat(double degat) override;
    bool estVivant() override;
};