#include <iostream>
#pragma once

#include "Objet.hpp" //Appel de la classe parente.

//On inclut donc les méthodes virtuelles pures d'Objet.hpp.
class Polygone : public Objet{
private:
    int sommetx;
    int sommety;
public:
    Polygone();
    void set_sommetx(int x);
    void set_sommety(int y);
};