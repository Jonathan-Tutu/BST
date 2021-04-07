#include "BST.h"

Node* index(Perso* db)
{
    // create a root node
    Node* root = nullptr;
    // iterate over all reccord in the database table

    for (int i = 0; i < 44; i++) {

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
    else if (strcmp(key, (*current)->key) < 0) { // key is lower, go to left subtree
        {
            int a = 0;
            Node * nouvelle = (*current);
            while(a == 0)
            {
                if(nouvelle->key < key) //strcmp(nouvelle->key, key) <
                {
                    if(nouvelle->right == nullptr)
                    {
                        nouvelle->right = new Node;
                        nouvelle = nouvelle->right;
                        nouvelle->right = nullptr;
                        nouvelle->left = nullptr;
                        a = 1;
                    }
                    else
                    {
                        nouvelle = nouvelle->right;
                    }
                }
                else
                {
                    if(nouvelle->left == nullptr)
                    {
                        nouvelle->left = new Node;
                        nouvelle = nouvelle->left;
                        nouvelle->right = nullptr;
                        nouvelle->left = nullptr;
                        a = 1;
                    }
                    else
                    {
                        nouvelle = nouvelle->left;
                    }
                }
            }
            nouvelle->key = key;
        }
        //return insert(&(*current)->left, key, value);
    }
    else if (strcmp((*current)->key, key) > 0) { // key is higher, go to right subtree
        {
            int a = 0;
            Node * nouvelle = (*current);
            while(a == 0)
            {
                if(nouvelle->key < key) //strcmp(key, nouvelle->key) <
                {
                    if(nouvelle->right == nullptr)
                    {
                        nouvelle->right = new Node;
                        nouvelle = nouvelle->right;
                        nouvelle->right = nullptr;
                        nouvelle->left = nullptr;
                        a = 1;
                    }
                    else
                    {
                        nouvelle = nouvelle->right;
                    }
                }
                else
                {
                    if(nouvelle->left == nullptr)
                    {
                        nouvelle->left = new Node;
                        nouvelle = nouvelle->left;
                        nouvelle->right = nullptr;
                        nouvelle->left = nullptr;
                        a = 1;
                    }
                    else
                    {
                        nouvelle = nouvelle->left;
                    }
                }
            }
            nouvelle->key = key;
        }
        //return insert(&(*current)->right, key, value);

    }
    else if(key == (*current)->key)
    {
        printf("%s is a duplicate (index already contains %s). It won't be inserted.\n", key, (*current)->key); // k == v.key() : duplicated key !
    }

    return current;
}
