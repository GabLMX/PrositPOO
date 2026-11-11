#include <iostream>
#include <string>
#include <fstream>
#pragma once
using namespace std;

class Chiffrement{
private:
    string nomFichier;

public:
    Chiffrement(string nomFichier);
    void readFile();
    string niveauUn();
    string niveauDeux();
    string niveauTrois();
};