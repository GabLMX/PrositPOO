#include <iostream>
#include <string>
#include <fstream>

#include "Dechiffrement.hpp"
using namespace std;

Dechiffrement::Dechiffrement(string nomFichier){
    this->nomFichier = nomFichier;
}

//César
string Dechiffrement::niveauUn(){
    string cle;
    cout << "Vous avez choisi un déchiffrement César. Veillez entrer votre clé: " << "\n";
    cin >> cle;

    string fichierFinal;

    ifstream fichier(nomFichier, ios::in);
    if(fichier){
        char caractere;
        int i = 0;

        while(fichier.get(caractere)){
            int ascii = static_cast<int>(caractere);

            if(ascii >= 97 && ascii <= 122){
                int decalage = cle[i] - '0';
                ascii -= decalage;

                if(ascii < 97){
                    ascii += 26;
                }
                if(ascii > 122){
                    ascii -= 26;
                }
                i = (i + 1) % cle.length(); //i incrémente de 1 mais modulo la taille de la clé.
                caractere = static_cast<char>(ascii);
            }

            if(ascii >= 65 && ascii <= 90){
                int decalage = cle[i] - '0';
                ascii -= decalage;

                if(ascii < 65){
                    ascii += 26;
                }
                if(ascii > 90){
                    ascii -= 26;
                }
                i = (i + 1) % cle.length();
                caractere = static_cast<char>(ascii);
            }
            
            fichierFinal += caractere;
            
        }
        fichier.close();
    }
    else{
        cerr << "Impossible d'ouvrir le fichier. Re-essayez avec un autre nom.txt?" << "\n";
        return "Err";
    }

    string nomFichier;
    cout << "Veillez donner le nom de votre fichier déchiffré (inclure le .txt): " << "\n";
    cin >> nomFichier;

    ofstream fichierSortie(nomFichier);
    if(fichierSortie){
        fichierSortie << fichierFinal;
        fichierSortie.close();
        cout << "Nom du nouveau fichier déchiffré: " << nomFichier << "\n";
    }
    else{
        cerr << "Erreur lors de la création du fichier. Essayez d'ajouter .txt?" << "\n";
        return "Err";
    }

    return "Succès";
}

//XOR
string Dechiffrement::niveauDeux(){
    string cle;
    cout << "Vous avez choisi un déchiffrement XOR. Veillez entrer votre clé: " << "\n";
    cin >> cle;

    string fichierFinalXOR;

    ifstream fichier(nomFichier, ios::in);
    if(fichier){
        char caractere;
        int i = 0;

        //L'étape ci-dessous associe déjà le caractère "actuel" du fichier à la variable.
        while(fichier.get(caractere)){
            caractere = caractere ^ cle[i];
            i = (i + 1) % cle.length();
            fichierFinalXOR += caractere;
            
        }
        fichier.close();
    }
    else{
        cerr << "Impossible d'ouvrir le fichier. Re-essayez avec un autre nom.txt?" << "\n";
        return "Err";
    }

    string nomFichier;
    cout << "Veillez donner le nom de votre fichier déchiffré (inclure le .txt): " << "\n";
    cin >> nomFichier;

    ofstream fichierSortie(nomFichier);
    if(fichierSortie){
        fichierSortie << fichierFinalXOR;
        fichierSortie.close();
        cout << "Nom du fichier déchiffré: " << nomFichier << "\n";
    }
    else{
        cerr << "Erreur lors de la création du fichier. Essayez d'ajouter .txt?" << "\n";
        return "Err";
    }

    return "Succès";
}

//César puis XOR
string Dechiffrement::niveauTrois(){
    //On doit appliquer XOR puis César.
    //Partie XOR:
    string cleXOR;
    cout << "Partie XOR du niveau 3. Veillez entrer votre clé XOR: " << "\n";
    cin >> cleXOR;

    string fichierFinal;

    ifstream fichier(nomFichier, ios::in);
    if(fichier){
        char caractere;
        int i = 0;

        //L'étape ci-dessous associe déjà le caractère "actuel" du fichier à la variable.
        while(fichier.get(caractere)){
            caractere = caractere ^ cleXOR[i];
            i = (i + 1) % cleXOR.length();
            fichierFinal += caractere;
            
        }
        fichier.close();
    }
    else{
        cerr << "Impossible d'ouvrir le fichier. Re-essayez avec un autre nom.txt?" << "\n";
        return "Err";
    }


    //Partie César après XOR. On parcoure la variable créée.
    string cleCsr;
    cout << "Partie César du niveau 3. Veillez entrer votre clé César: " << "\n";
    cin >> cleCsr;

    int j = 0;

    for(int i = 0; i < fichierFinal.length(); i++){
        //Remplacer ci dessous par César.
        char caractere = fichierFinal[i]; //On utilise caractere pour ne pas modifier fichierFinal[i] trop tôt.
        int ascii = static_cast<int>(caractere);

        if(ascii >= 97 && ascii <= 122){
                int decalage = cleCsr[j] - '0'; //Encore une fois, le - '0' permet d'avoir "sous" Ascii.
                ascii -= decalage;

                if(ascii < 97){
                    ascii += 26;
                }
                if(ascii > 122){
                    ascii -= 26;
                }
                j = (j + 1) % cleCsr.length();
                caractere = static_cast<char>(ascii);
            }

            if(ascii >= 65 && ascii <= 90){
                int decalage = cleCsr[j] - '0';
                ascii -= decalage;

                if(ascii < 65){
                    ascii += 26;
                }
                if(ascii > 90){
                    ascii -= 26;
                }
                j = (j + 1) % cleCsr.length();
                caractere = static_cast<char>(ascii);
            }

        fichierFinal[i] = caractere;
    }

    //Après César et XOR:
    string nomFichier;
    cout << "Veillez donner le nom de votre fichier déchiffré (inclure le .txt): " << "\n";
    cin >> nomFichier;

    ofstream fichierSortie(nomFichier);
    if(fichierSortie){
        fichierSortie << fichierFinal;
        fichierSortie.close();
        cout << "Nom du fichier déchiffré: " << nomFichier << "\n";
    }
    else{
        cerr << "Erreur lors de la création du fichier. Essayez d'ajouter .txt?" << "\n";
        return "Err";
    }

    return "Succès";
}



//Ancienne version de niveauTroi qui applique César avant XOR et ne fonctionne donc pas:
/*
    //Partie César:
    string cleCsr;
    cout << "Vous êtes au déchiffrement César. Veillez entrer votre clé: " << "\n";
    cin >> cleCsr;

    string fichierFinal;

    ifstream fichier(nomFichier, ios::in);
    if(fichier){
        char caractere;
        int i = 0;

        while(fichier.get(caractere)){
            int ascii = static_cast<int>(caractere);

            if(ascii >= 97 && ascii <= 122){
                int decalage = cleCsr[i] - '0';
                ascii -= decalage;

                if(ascii < 97){
                    ascii += 26;
                }
                if(ascii > 122){
                    ascii -= 26;
                }
                i = (i + 1) % cleCsr.length(); //i incrémente de 1 mais modulo la taille de la clé.
                caractere = static_cast<char>(ascii);
            }

            if(ascii >= 65 && ascii <= 90){
                int decalage = cleCsr[i] - '0';
                ascii -= decalage;

                if(ascii < 65){
                    ascii += 26;
                }
                if(ascii > 90){
                    ascii -= 26;
                }
                i = (i + 1) % cleCsr.length();
                caractere = static_cast<char>(ascii);
            }
            
            fichierFinal += caractere;
            
        }
        fichier.close();
    }
    else{
        cerr << "Impossible d'ouvrir le fichier. Re-essayez avec un autre nom.txt?" << "\n";
        return "Err";
    }


    //Partie XOR après César:
    string cleXOR;
    cout << "Vous avez choisi un déchiffrement XOR. Veillez entrer votre clé: " << "\n";
    cin >> cleXOR;

    int j = 0;

    for(int i = 0; i < fichierFinal.length(); i++){
        fichierFinal[i] = fichierFinal[i] ^ cleXOR[j];
        j = (j + 1) % cleXOR.length();
    }


    //Après César et XOR:
    string nomFichier;
    cout << "Veillez donner le nom de votre fichier déchiffré (inclure le .txt): " << "\n";
    cin >> nomFichier;

    ofstream fichierSortie(nomFichier);
    if(fichierSortie){
        fichierSortie << fichierFinal;
        fichierSortie.close();
        cout << "Nom du fichier déchiffré: " << nomFichier << "\n";
    }
    else{
        cerr << "Erreur lors de la création du fichier. Essayez d'ajouter .txt?" << "\n";
        return "Err";
    }

    return "Succès";
*/