#include <iostream>

#include "Personnage.hpp"
#include "Heroes.hpp"
#include "Creatures.hpp"

//Compiler avec "g++ main.cpp Creatures.cpp Heroes.cpp -o main" dans le bon directory.

//Adapter le main() après Creatures.cpp.
int main(){

    //On change les "classes" vers celles qui existent vraiment, et l'ordre des attributs. On ajoute l'attribut des dégâts.
    Heroes guerrier{"Arthur", 14, 8, 4, "tranchant"};
    Heroes archer{"Legolas", 10, 12, 4, "perçant"};
    Heroes mage{"Merlin", 10, 14, 5, "magique"};

    Creatures dragon{30, 16, 11, "flammes"};
    Creatures gobelin{5, 5, 2, "tranchant"};
    Creatures troll{12, 10, 5, "contondant"};

    int nbr_perso = 6;
    Personnage* combattants[nbr_perso] = {&guerrier, &archer, &mage, &dragon, &gobelin, &troll};
    //Ce tableau est une utilisation du polymorphisme. On utilise la classe parente commune Personnage.

    std::cout << "Etat initial :" << std::endl;

    for (int i = 0; i < 6; i++){
        combattants[i]->affiche();
        //On parcoure les objets et appèle leurs version de la méthode affiche();
        //ça fonctionne presque comme un this->.
    }

    std::cout << "Le combat commence !" << std::endl;

    double degats;

    degats = combattants[0]->attaque();
    combattants[3]->subitDegat(degats);

    degats = combattants[3]->attaque();
    combattants[0]->subitDegat(degats);

    degats = combattants[1]->attaque();
    combattants[4]->subitDegat(degats);

    degats = combattants[4]->attaque();
    combattants[1]->subitDegat(degats);

    degats = combattants[2]->attaque();
    combattants[5]->subitDegat(degats);

    degats = combattants[5]->attaque();
    combattants[2]->subitDegat(degats);

    //Une version qui utilise des if() dans une boucle for() aurait marché aussi.

    std::cout << "Etat final :" << std::endl;

    for(int i = 0; i < 6; i++){
        combattants[i]->affiche();
    }

    return 0;
}