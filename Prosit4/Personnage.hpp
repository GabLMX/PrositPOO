//Classe virtuelle pure.
#include <iostream>
#pragma once

class Personnage{
public: //Pas de constructeur, mais il peut y en avoir un de défaut.
    virtual void affiche() = 0;
    virtual double attaque() = 0;
    virtual double subitDegat(double degat) = 0;
    virtual bool estVivant() = 0;
};