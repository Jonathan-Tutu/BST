#ifndef BST_H
#define BST_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "LectureFichier.h"
typedef struct Node {

    const char* nom;

    int index;

    Node* left;

    Node* right;

} Node;

Node* index(FictionalCharacter* db, int NbLigne);
bool insert(Node** current, const char* key, int value);
int get_profondeur(Node* );
bool ControleBST(Node *);
bool Search(Node* root, char* key);
bool SearchInRange(Node *root, char *key1, char* key2);
bool SearchInRangeAge(Node* node, char* key1, char* key2, vector<int> age, FictionalCharacter *car);

#endif // BST_H
