#include "Test2.h"
#include "BST.h"

int main()
{
    Perso *test;

    test = load("C:\\Users\\jonat\\OneDrive\\Bureau\\Test.csv"); //Adresse première case tab

    for(int i = 0; i < 43; i++)
    {
        cout << test[i].nom << endl;
    }

    printf("Creating index...\n");
    Node* root = index(test);
    printf("Done creating index.\n");

    //lala = init(*test);
}
