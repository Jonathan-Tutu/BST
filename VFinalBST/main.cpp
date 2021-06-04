#include "BST.h"

int main()
{
    FictionalCharacter* FicChar = 0;
    database Db;
    Node* root = createDatabase("C:\\Users\\jonat\\OneDrive\\Bureau\\Test.csv", Db, FicChar); //A changer en fonction du chemin où se trouvent le fichier .CSV

    if (ControleBST(root))
    {
        cout << "C'est un BST" << endl;
    }
    else
    {
        cout << "Ce n'est pas un BST" << endl;
    }

    int taille = get_profondeur(root);
    cout << "taille : " << taille << endl;

    Search(root, "Flyte");
    SearchInRange(root, "Bo", "Bsu");

    vector<int> age; //Permet de stocker les ages
    SearchInRangeAge(root, "Ja", "Pi", age, Db);

    //Calcul de la moyenne : On a accès aux données du vector age car il est passé par référence et donc on ne passe pas une copie de celui-ci
    int moyage = 0;
    for(unsigned int i = 0; i < age.size(); i++)
    {
        moyage += age.at(i);
    }
    moyage /= age.size();

    cout << "\rLa moyenne d'age est de : " << moyage << endl;

}
