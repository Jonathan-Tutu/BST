#include "BST.h"

Node* index(Perso* db)
{

    // create a root node

    Node* root = nullptr;


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

        *current = (Node*)malloc(sizeof(Node));

        (*current)->key = key;

        (*current)->table_rank = value;

        (*current)->left = nullptr;

        (*current)->right = nullptr;

        return true;

    }



    // otherwise, let's move left or right

    if (strcmp(key, (*current)->key) < 0) { // key is lower, go to left subtree

        return insert(&(*current)->left, key, value);

    }



    if (strcmp(key, (*current)->key) > 0) { // key is higher, go to right subtree

        return insert(&(*current)->right, key, value);

    }



    // k == v.key() : duplicated key !

    printf("%s is a duplicate (index already contains %s). It won't be inserted.\n", key, (*current)->key);

    return current;
}
