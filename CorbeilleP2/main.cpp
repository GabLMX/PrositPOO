#include <iostream>
#include <string>
#include <fstream>

#include "modder.hpp"

int main(void){
    // //wsl.localhost/Ubuntu/home/lemau/cpp/CorbeilleServices/Notes Corbeille.txt Le path complet.
    //Ou: R"\\wsl.localhost\Ubuntu\home\lemau\cpp\CorbeilleServices\Notes Corbeille.txt"

    Modder file;
    std::string path = "//wsl.localhost/Ubuntu/home/lemau/cpp/CorbeilleServices/Notes Corbeille.txt";
    std::string message = "Est-ce que ça marche? Oui!";

    file.ecritureFichier(message, path);
    message = file.lectureFichier(path);

    std::cout << message << "\n";
    std::cin.get();
}; //Tout ça ne marche pas donc bon..