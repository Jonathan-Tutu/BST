#include "BST.h"

int main()
{
    FictionalCharacter* FicChar = 0;
    database Db;
    Node* root = createDatabase("C:\\Users\\Jonathan\\Desktop\\Test.csv", Db, FicChar); //A changer en fonction du chemin où se trouvent le fichier .CSV

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
}
