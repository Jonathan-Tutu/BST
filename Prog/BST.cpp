#include "BST.h"
#include <math.h>

Node* index(FictionalCharacter* db, int NbLigne)
{
    // create a root node
    Node* root = nullptr;
    // iterate over all reccord in the database table

    for (int i = 0; i < NbLigne; i++) {

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

    if (*current == nullptr)
    { //Si on est dans le noeud racine

        *current = new Node; //On va stocker dedans l'adresse du premier pointeur

        //On insère les valeurs dans le noeud actuel
        (*current)->nom = key;

        (*current)->index = value;

        (*current)->left = nullptr;

        (*current)->right = nullptr;
    }
    else if(strcmp(key, (*current)->nom) > 0 || strcmp(key, (*current)->nom) < 0)
    {
        bool insert = 0;
        Node * actuel = (*current);
        while(insert == 0)
        {
            if(strcmp(key, actuel->nom) > 0) //Si le Nom qu'on insère est alphabétiquement supérieur au nom du noeud actuel
            {
                if(actuel->right == nullptr) //Si le pointeur pointant vers le noeud droite est nul, cela signifie qu'il n'y a pas encore de noeud donc on le crée et on insère les valeurs
                {
                    actuel->right = new Node;
                    actuel = actuel->right;
                    actuel->right = nullptr;
                    actuel->left = nullptr;
                    actuel->nom = key;
                    insert = 1;
                }
                else
                {
                    actuel = actuel->right; //Si le noeud de droite existe on se déplace dans le noeud suivant
                }
            }

            else if(strcmp(key, actuel->nom) < 0) //Sinon si le Nom qu'on insère est alphabétiquement inférieur au nom du noeud actuel
            {
                if(actuel->left == nullptr) //Si le pointeur pointant vers le noeud gauche est nul, cela signifie qu'il n'y a pas encore de noeud donc on le crée et on insère les valeurs
                {
                    actuel->left = new Node;
                    actuel = actuel->left;
                    actuel->right = nullptr;
                    actuel->left = nullptr;
                    actuel->nom = key;
                    insert = 1;
                }
                else
                {
                    actuel = actuel->left; //Si le noeud de gauche existe on se déplace dans le noeud suivant
                }
            }

            else if(strcmp(actuel->nom, key) == 0) //Si le Nom que l'on veut insérer est déjà présent dans un des noeuds, on retourne faux
            {
                return false;
            }
        }
    }
    else if(strcmp((*current)->nom, key) == 0) //Si le Nom que l'on veut insérer est égal au nom présent dans le root
    {
        cout << "Le nom " << key << "que vous essayer d'entrer existe déjà présent dans l'arbre " << endl;
        return false;
    }

    return true;
}
bool ControleBST(Node* node)
{
    if(node == nullptr) {

        return true;

    }
    if(node->left != nullptr && ((strcmp(node->left->nom, node->nom) > 0)))
    {
        return false;

    }
    if(node->right != nullptr && ((strcmp(node->right->nom, node->nom) <  0)))
    {

        return false;

    }

    if(!ControleBST(node->left) || !ControleBST(node->right))
    {
        return false;
    }

    return true;
}

int get_profondeur(Node* node)
{

    if (node == nullptr)
    {
        return 0;
    }
    else
    {
        //On parcour de manière récurvise l'arbre.
        int lDepth = get_profondeur(node->left);
        int rDepth = get_profondeur(node->right); //On apelle la fonction plusieurs fois, c'est pour cela qu'on passe plusieurs fois dans le return
        if(lDepth >= rDepth)
        {
            return lDepth + 1;
        }
        else
        {
            return rDepth +1;
        }
    }
}

bool Search(Node* node, char* key)
{
    while (node != NULL) {
        if (strcmp(key, node->nom) > 0)
        {
            node = node->right;
        }
        else if (strcmp(key, node->nom) < 0)
        {
            node = node->left;
        }
        else if (strcmp(key, node->nom) == 0)
        {
            cout << key << " ";
            return true; // if the key is found return 1
        }
    }
    cout << key << " ";
    return false;
}

bool SearchInRange(Node* node, char* key1, char* key2)
{
      if(node == nullptr)
      {
          return 0;
      }
      else if((strcmp(node->nom, key1) > 0) && (strcmp(node->nom, key2) < 0))
      {
            cout << node->nom << " ";

            if (strcmp(node->nom, key1) > 0)
            {
                SearchInRange(node->right, key1, key2);
            }
            else if(strcmp(node->nom, key2) < 0)
            {
                SearchInRange(node->left, key1, key2);
            }
      }
      else if(strcmp(key1, node->nom) > 0)
      {
          SearchInRange(node->right, key1, key2);
      }
      else if(strcmp(key2, node->nom) < 0)
      {
          SearchInRange(node->left, key1, key2);
      }
}

bool SearchInRangeAge(Node* node, char* key1, char* key2, vector<int> age, FictionalCharacter *car)
{
    if(node == nullptr)
    {
        return 0;
    }
    else if((strcmp(node->nom, key1) > 0) && (strcmp(node->nom, key2) < 0))
    {
        //On insere le tableau de fictionnal caractere, on le parcours tant que car.nom != node.nom, dès qu'il sont égaux on prend la valeur de age et on la met dans le vector
        for(int i = 0; i < 43; i++)
        {
            if(car[i].nom == node->nom)
            {
                age.push_back(car[i].age);
            }
            cout << car[i].age << endl;
        }
        if (strcmp(node->nom, key1) > 0)
        {
            SearchInRangeAge(node->right, key1, key2, age, car);
        }
        else if(strcmp(node->nom, key2) < 0)
        {
            SearchInRangeAge(node->left, key1, key2, age, car);
        }
    }
    else if(strcmp(key1, node->nom) > 0)
    {
        SearchInRangeAge(node->right, key1, key2, age, car);
    }
    else if(strcmp(key2, node->nom) < 0)
    {
        SearchInRangeAge(node->left, key1, key2, age, car);
    }
}



