#include <iostream>
#include <string>
#include <fstream>

#include "Chiffrement.hpp"
#include "Dechiffrement.hpp"

using namespace std;

int main(void){
    cout << "Vos fichiers seront à: //wsl.localhost/Ubuntu/home/lemau/cpp/Prosit2" << "\n";

    //Tests à réaliser, qui utilisent tous les niveaux et test.txt:
    
    /*
    Chiffrement tentative1("test.txt");
    tentative1.readFile();
    tentative1.niveauUn();
    */
    /*
    Dechiffrement tentative1b("tested.txt");
    tentative1b.niveauUn();
    //Vérifiez soit avec .readFile() ou dans le répertoire que ça marche. Cette instruction est pour tous les niveaux.
    */


    /*
    Chiffrement tentative2("test.txt");
    tentative1.readFile();
    tentative1.niveauDeux();
    */
    /*
    Dechiffrement tentative2b("tested.txt");
    tentative1b.niveauDeux();
    */


    /*
    Chiffrement tentative3("test.txt");
    tentative1.readFile();
    tentative1.niveauTrois();
    */
    /*
    Dechiffrement tentative3b("tested.txt");
    tentative1b.niveauTrois();
    */

    //Une boucle while(1) peut être ajoutée dans une version "future".
    return 0;
}

//Si la compilation ne marche pas, essayez d'abord d'aller dans le bon directory ("cd Prosit2" ou jusqu'à avoir Prosit2)
//puis faire "g++ main.cpp Chiffrement.cpp Dechiffrement.cpp -o program" et "./program"