#include "LectureFichier.h"
#include <sstream>
#include <iterator>
#include <string.h>

int LineCompteur(string chemin)
{
    ifstream file (chemin);

    int cpt = 0;

    if(file.is_open()) //On vérifie si l'on peut ouvrir le fichier, si l'on ne peut pas pour une quelconque raison, on ferme l'application
    {
    string line;
    while(getline(file, line)) //Tant qu'on arrive à lire une ligne dans le fichier
    {
      cpt++; //On incrémente le compteur
    }
    }
    else
    {
        cout << "Impossible d'ouvrir le fichier " << endl;
        exit(1);
    }

    return cpt; //On retourne le nombre de ligne
}

FictionalCharacter* load(string chemin, int NbLigne)
{
    FictionalCharacter* FicChar = new FictionalCharacter[NbLigne];
    int i = 0;

    string line;
    ifstream file (chemin);

    while(getline(file, line))  //Tant qu'on arrive à lire une ligne dans le fichier
    {
           //On crée à chaque fois un nouveau vector du même nom donc ça erase le vector précédent
           vector <string> tokens;

           stringstream check1(line); //On crée un stringstream afin de pouvoir le réutiliser dans la fonction getline suivante car elle n'accepte pas de string

           string intermediate;

           while(getline(check1, intermediate, ';')) //On stock toutes les valeurs séparé par des ";" dans intermediate qu'on injecte ensuite dans un vector (tableau dynamique)
           {
               tokens.push_back(intermediate);
               if(tokens.size() == 4) //Des qu'on à les quatres élements de la ligne, on les insère dans la structure
               {
                   FicChar[i].nom = tokens.at(0);
                   FicChar[i].prenom = tokens.at(1);
                   FicChar[i].roman = tokens.at(2);
                   /*Conversion en int */
                   int n;
                   n = stoi(tokens.at(3));
                   /********************/
                   FicChar[i].age = n;
                   i++;
               }
           }

    }
    return FicChar; //On retourne le FictionnalCharacter
}
