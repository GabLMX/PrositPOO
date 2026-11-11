#include <iostream>
#include <string>
#include <fstream>

#include "Chiffrement.hpp"
using namespace std;

Chiffrement::Chiffrement(string nomFichier){
    this-> nomFichier = nomFichier;
}

void Chiffrement::readFile(){
    ifstream fichier(nomFichier, ios::in);
    if(fichier){
        string contenu;
        while(getline(fichier, contenu)){
            cout << contenu << endl;
        }
        fichier.close();
    }
    else{
        //cerr pour "erreur."
        cerr << "Impossible d'ouvrir le fichier. Re-essayez avec le .txt?" << "\n";
    }
}

//César
string Chiffrement::niveauUn(){
    string cle;
    cout << "Vous avez choisi la méthode César. Veillez indiquer votre clé numérique (ex: 1; 155): " << "\n";
    cin >> cle;

    string fichierFinal; //A remplir au fur est à mesure du programme.

    ifstream fichier(nomFichier, ios::in);
    if(fichier){
        char caractere;
        int i = 0;

        //L'étape ci-dessous associe déjà le caractère "actuel" du fichier à la variable.
        while(fichier.get(caractere)){
            int ascii = static_cast<int>(caractere); //Transforme un caractère en sont format Ascii numérique.

            if(ascii >= 97 && ascii <= 122){
                int decalage = cle[i] - '0';
                ascii += decalage;

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
                ascii += decalage;

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
    cout << "Veillez donner le nom de votre nouveau fichier (inclure le .txt): " << "\n";
    cin >> nomFichier;

    ofstream fichierSortie(nomFichier);
    if(fichierSortie){
        fichierSortie << fichierFinal;
        fichierSortie.close();
        cout << "Nom du nouveau fichier: " << nomFichier << "\n";
    }
    else{
        cerr << "Erreur lors de la création du fichier. Essayez d'ajouter .txt?" << "\n";
        return "Err";
    }

    cout << "N'oubliez pas votre clé! " << "(" << cle << ")" << "\n";
    return cle;
}

//XOR
string Chiffrement::niveauDeux(){
    string cle;
    cout << "Vous avez choisi la méthode XOR. Veillez indiquer votre clé (ex: abc, 12): " << "\n";
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
    cout << "Veillez donner le nom de votre nouveau fichier (inclure le .txt): " << "\n";
    cin >> nomFichier;

    ofstream fichierSortie(nomFichier);
    if(fichierSortie){
        fichierSortie << fichierFinalXOR;
        fichierSortie.close();
        cout << "Nom du nouveau fichier: " << nomFichier << "\n";
    }
    else{
        cerr << "Erreur lors de la création du fichier. Essayez d'ajouter .txt?" << "\n";
        return "Err";
    }

    cout << "N'oubliez pas votre clé! " << "(" << cle << ")" << "\n";
    return cle;
}

//César puis XOR
string Chiffrement::niveauTrois(){
    cout << "Vous avez choisi le niveau trois, et par conséquent les deux autres niveaux." << "\n";
    //Je n'utilise pas les des autres méthodes simplement car elles contiennent des prints répétitifs qui
    //renderaient cette version moins lisible. De plus, comme j'ai utilisé des "grosses" méthodes,
    //faire passer le fichier chiffré César à la méthode XOR directement serait compliqué. Je me contente donc de
    //reprendre le code contenu dans les méthodes et de l'adapter.

    //César:
    string cleCsr;
    cout << "Vous avez choisi la méthode César. Veillez indiquer votre clé numérique César (ex: 1; 155): " << "\n";
    cin >> cleCsr;

    string fichierFinal; //On le reparcourera pour XOR.

    ifstream fichier(nomFichier, ios::in);
    if(fichier){
        char caractere;
        int i = 0;

        while(fichier.get(caractere)){
            int ascii = static_cast<int>(caractere);

            if(ascii >= 97 && ascii <= 122){
                int decalage = cleCsr[i] - '0';
                ascii += decalage;

                if(ascii < 97){
                    ascii += 26;
                }
                if(ascii > 122){
                    ascii -= 26;
                }
                i = (i + 1) % cleCsr.length();
                caractere = static_cast<char>(ascii);
            }

            if(ascii >= 65 && ascii <= 90){
                int decalage = cleCsr[i] - '0';
                ascii += decalage;

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


    //XOR appliqué à tous les caractères de fichierFinal:
    string cleXOR;
    cout << "Vous avez choisi la méthode XOR. Veillez indiquer votre clé XOR (ex: abc, 12): " << "\n";
    cin >> cleXOR;

    int j = 0;

    for(int i = 0; i < fichierFinal.length(); i++){ //ou size_t pour le type de i.
        fichierFinal[i] = fichierFinal[i] ^ cleXOR[j];
        j = (j + 1) % cleXOR.length();
    }


    //Après César et XOR
    string nomFichier;
    cout << "Veillez donner le nom de votre nouveau fichier (inclure le .txt): " << "\n";
    cin >> nomFichier;

    ofstream fichierSortie(nomFichier);
    if(fichierSortie){
        fichierSortie << fichierFinal;
        fichierSortie.close();
        cout << "Nom du nouveau fichier: " << nomFichier << "\n";
    }
    else{
        cerr << "Erreur lors de la création du fichier. Essayez d'ajouter .txt?" << "\n";
        return "Err";
    }

    cout << "Votre clé César: " << "(" << cleCsr << ")" << "\n";
    cout << "Votre clé XOR: " << "(" << cleXOR << ")" << "\n";
    return (cleCsr + ", " + cleXOR);
}
