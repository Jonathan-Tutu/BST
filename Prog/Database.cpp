#include <Database.h>

Node* createDatabase(string chemin)
{
    FictionalCharacter *test;
    int NbLigne = LineCompteur(chemin);

    test = load(chemin, NbLigne); //Adresse première case tab}
    Node* root = index(test, NbLigne);

    return  root;
}

