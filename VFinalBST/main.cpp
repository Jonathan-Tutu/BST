#include "BST.h"

int main()
{
    FictionalCharacter* FicChar = 0;
    database Db;
    Node* root = createDatabase("C:\\Users\\Jonathan\\Desktop\\Test.csv", Db, FicChar);

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

    if (Search(root, "Flyte"))
    {
        cout << "a ete trouve" << endl;
    }
    else
    {
        cout << "n'a pas ete trouve " << endl;
    }

    SearchInRange(root, "Bo", "Bsu");

    vector<int> age; //Permet de stocker les ages
    SearchInRangeAge(root, "Ja", "Pi", age, Db);

}
