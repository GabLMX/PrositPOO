#include <iostream>
#include <string>
#include <fstream>
#pragma once
using namespace std;

class Dechiffrement{
private:
    string nomFichier;

public:
    Dechiffrement(string nomFichier);
    string niveauUn();
    string niveauDeux();
    string niveauTrois();
};