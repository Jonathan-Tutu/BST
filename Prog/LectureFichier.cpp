#include "LectureFichier.h"
#include <sstream>
#include <iterator>

int LineCompteur(string chemin)
{
    ifstream file (chemin);

    int cpt = 0;
    string line;
    while(getline(file, line))
    {
      cpt++;
    }

    return cpt;
}

FictionalCharacter* load(string chemin, int NbLigne)
{
    FictionalCharacter* lala = new FictionalCharacter[NbLigne];
    int i = 0;
    int n;

    string line;
    ifstream file (chemin);

    while(getline(file, line))
    {
           //On crée à chaque fois un nouveau vector du même nom donc ça erase le vector précédent
           vector <string> tokens;

           stringstream check1(line);

           string intermediate;

           while(getline(check1, intermediate, ';'))
           {
               tokens.push_back(intermediate);
               if(tokens.size() == 4)
               {
                   lala[i].nom = tokens.at(0);
                   lala[i].prenom = tokens.at(1);
                   lala[i].roman = tokens.at(2);
                   /*Conversion en int */
                   n = stoi(tokens.at(3));
                   lala[i].age = n;
                   //cout << "nom : " << lala[i].nom << "prenom : " << lala[i].prenom << "roman : " << lala[i].roman << "age : " << lala[i].age << endl;
                   i++;
               }
           }

    }
    cout << lala <<endl;
    return lala;
}



