#include "BST.h"

Node* index(Perso* db)
{

    // create a root node

    Node* root = nullptr;
    cout << "r " << root << endl;
    cout << "& " << &root << endl;
    // iterate over all reccord in the database table

    for (int i = 0; i < 43; i++) {

        if (insert(&root, db[i].nom.c_str(), i)) {

            printf("Successfully indexed %s\n", db[i].nom.c_str());

        }
        else {

            printf("Cannot index %s\n", db[i].nom.c_str());

        }

    }

    return root;

}


bool insert(Node** current, const char* key, int value) {

    // if current is null pointer, we went down to a leave safe for insertion

    if (*current == nullptr) {

        *current = new Node; //On va stocker dedans l'adresse du premier pointeur

        (*current)->key = key;

        (*current)->table_rank = value;

        (*current)->left = nullptr;

        (*current)->right = nullptr;
    }

    else if (key < (*current)->key) { // key is lower, go to left subtree
        //A faire à la main
        //while()
        return insert(&(*current)->left, key, value);
    }
    else if (key > (*current)->key) { // key is higher, go to right subtree
        //A faire à la main
        //while()
        //S'il est > va à droite tant que != nullptr
        return insert(&(*current)->right, key, value);

    }
    else if(key == (*current)->key)
    {
        printf("%s is a duplicate (index already contains %s). It won't be inserted.\n", key, (*current)->key); // k == v.key() : duplicated key !
    }

    return current;
}
