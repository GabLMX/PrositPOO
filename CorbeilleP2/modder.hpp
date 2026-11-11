#include <iostream>
#include <string>
#include <fstream>
#pragma once

//Il faut fournir le chemin d'accès (path) au fichier.

class Modder{
private:
    std::string contenu;
    std::ifstream f_in;
    std::ofstream f_out;

public:
    Modder();
    std::string lectureFichier(const std::string &path);
    void ecritureFichier(std::string changement, const std::string &path);
};