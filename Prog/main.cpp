#include "LectureFichier.h"
#include "BST.h"
#include "Database.h"

int main()
{
    Node* root = createDatabase("C:\\Users\\jonat\\OneDrive\\Bureau\\Test.csv");

    if(ControleBST(root))
    {
        cout << "C'est un BST" << endl;
    }
    else
    {
        cout << "Ce n'est pas un BST" << endl;
    }

    int taille = get_profondeur(root);
    cout << "taille : " << taille << endl;

    if(Search(root, "Stephen"))
    {
        cout << "a ete trouve" << endl;
    }
    else
    {
        cout << "n'a pas ete trouve " << endl;
    }

     SearchInRange(root, "Bo", "Bsu");

     database db;
     vector<int> age;
     SearchInRangeAge(root, "ja", "pi", age, db.table);

}
