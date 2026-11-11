#include <iostream>
#include <string>

#include "modder.hpp"

//ifstream (Input File stream ;) ) pour la lecture et ofstream (Output File stream) pour l'écriture. On met donc:
#include <fstream>

// //wsl.localhost/Ubuntu/home/lemau/cpp/CorbeilleServices/Notes Corbeille.txt Le path complet.
//Ou: R"\\wsl.localhost\Ubuntu\home\lemau\cpp\CorbeilleServices\Notes Corbeille.txt"

Modder::Modder(){}

std::string Modder::lectureFichier(const std::string &path){
    this->contenu.clear();
    std::string ligne;

    f_in.open(path);
    while(std::getline(f_in, ligne)){
        this->contenu.append(ligne);
        this->contenu.append("\n");
    }  
    f_in.close();

    return this->contenu;
}

void Modder::ecritureFichier(std::string changement, const std::string &path){
    f_out.open(path, std::ofstream::out);
    f_out << changement;
    f_out.close();
}