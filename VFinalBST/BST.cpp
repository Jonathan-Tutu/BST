#include <math.h>
#include "BST.h"

Node* index(database* db, int NbLigne)
{
    //On crée la racine de l'arbre
    Node* root = nullptr;

    //On insère dans l'arbre les données extraite de la base de données
    for (int i = 0; i < NbLigne; i++) {

        if(insert(&root, db->table[i].nom.c_str(), i))
        {

            cout << "L'index " << db->table[i].nom << " a bien ete insere " << endl;

        }
        else
        {
            cout << "L'index " << db->table[i].nom << " n'a pas pu etre insere " << endl;
        }
    }

    return root;
}

Node* createDatabase(string chemin, database& Db, FictionalCharacter* FicChar)
{
    Db.size = LineCompteur(chemin);

    FicChar = load(chemin, Db.size); //Adresse première case tab
    Db.table = FicChar; //On remplis la structure database avec ce qu'il y a dans le fichier (stocké dans la structure)
    Node* root = index(&Db, Db.size); //On insère dans le binary search tree les données contenue dans la base de données (Db)

    return root; //On retourne l'adresse du noeud root
}

bool insert(Node** current, const char* key, int value) {

    if (*current == nullptr) //Si on est dans le noeud racine
    {

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
    if((node->left != nullptr && (strcmp(node->right->nom, node->nom)) < 0) || (node->left != nullptr && (strcmp(node->left->nom, node->nom)) > 0))
    {
      return false;
    }

    //On parcourt récursivement le BST tant que c'est un bst et qu'on ne retourne pas false, on ne rentre pas dans la boucle if et par conséquence ne retourne donc pas false
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
        //On parcourt de manière récurvise l'arbre.
        int ProfondeurGauche = get_profondeur(node->left);
        int ProfondeurDroite = get_profondeur(node->right);

        if(ProfondeurGauche >= ProfondeurDroite)
        {
            return ProfondeurGauche + 1;
        }
        else
        {
            return ProfondeurDroite +1;
        }
    }
}

void Search(Node* node, const char* key)
{
    while (node != NULL) { //Tant qu'un noeud n'est pas nul
        if (strcmp(key, node->nom) > 0) //Si le nom que l'on cherche est supérieur au nom du noeud actuel
        {
            node = node->right; //On part sur le noeud de droite
        }
        else if (strcmp(key, node->nom) < 0) //Si le nom que l'on cherche est inférieur au nom du noeud actuel
        {
            node = node->left; //On part sur le noeud de gauche
        }
        else if (strcmp(key, node->nom) == 0)
        {
            cout << key << " a ete trouve\n";//Si on trouve le bon nom on l'affiche
            return; //Si on trouve le bon nom on fait un return
        }
    }
    cout << key << " n'a ete trouve\n"; //Si on ne trouve pas le bon nom on l'affiche quand même
}


/*On parcourt tout le BST en PreOrder : On visite le parent, l'enfant gauche puis l'enfant droit*/
void SearchInRange(Node* node, const char* key1, const char* key2)
{
        if(node == nullptr)
        {
            return;
        }

        if(strcmp(node->nom, key1) > 0 && strcmp(node->nom, key2) < 0)
        {
              cout << node->nom << " ";
        }

        SearchInRange(node->right, key1, key2);

        SearchInRange(node->left, key1, key2);
}

void SearchInRangeAge(Node* node, const char* key1, const char* key2, vector<int> &age, database Db) //Le vector age est un paramètre d'entrée sortie afin de pouvoir réutiliser son contenue dans le main afin de pouvoir calculer la moyenne d'age
{
    if(node == nullptr)
    {
        return ;
    }

    if(strcmp(node->nom, key1) > 0 && strcmp(node->nom, key2) < 0)
    {
        for(int i = 0; i < Db.size; i++)
        {
            if(Db.table[i].nom == node->nom) //Si le nom du personnage que l'on cherche est égal au nom du noeud
            {
                age.push_back(Db.table[i].age); //On le rajoute dans un vector qui servira pour la moyenne
            }
        }
    }

    SearchInRangeAge(node->right, key1, key2, *(&age), Db);

    SearchInRangeAge(node->left, key1, key2, *(&age), Db);
}






