#include "Test2.h"
#include "BST.h"

int main()
{
    Perso *test;


    int NbLigne = LineCompteur("C:\\Users\\jonat\\OneDrive\\Bureau\\Test.csv");
    cout << NbLigne << endl;
    test = load("C:\\Users\\jonat\\OneDrive\\Bureau\\Test.csv"); //Adresse première case tab

    printf("Creation de l'index");
    Node* root = index(test);
    printf("Fin de la creation de l'index");

    //lala = init(*test);
}
