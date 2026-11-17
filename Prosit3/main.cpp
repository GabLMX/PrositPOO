#include <iostream>

#include "Objet.hpp"
#include "Polygone.hpp"
#include "Cercle.hpp"
#include "Triangle.hpp"
#include "Rectangle.hpp"
#include "Carre.hpp"

//Alright, test time.
//Pour compiler; "cd prosit3", "g++ main.cpp Cercle.cpp Polygone.cpp Triangle.cpp Rectangle.cpp Carre.cpp -o prog"
//Puis "./prog"

int main(void){
    Cercle c(5);
    Triangle t(10, 52, 36);
    Rectangle r(5.5, 10.5);
    Carre ca(7.5);

    std::cout << "Premier prints; \n";
    c.afficherInfo();
    t.afficherInfo();
    r.afficherInfo();
    ca.afficherInfo();
    std::cout << "\n";

    c.setRayon(9); //Sachant que Cercle ne prend que des integer.
    r.setLargeur(2.3);
    r.setLongueur(8.5);
    ca.setCote(9.99);

    std::cout << "Deuxième prints (on ne touche pas au triangle); \n";
    c.afficherInfo();
    r.afficherInfo();
    ca.afficherInfo();

    return 0;
    //A faire: créer un while(1);
}