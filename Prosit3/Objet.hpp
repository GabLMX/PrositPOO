#include <iostream>
#pragma once

class Objet{
public:
    virtual double aire() = 0;
    virtual double perimetre() = 0;
    virtual void afficherInfo() = 0;
    //Le " = 0" est nécessaire pour un virtuel pur.
    //Je peux également ajouter un destructeur commun qui affectera toutes les autres classes filles.
};