#ifndef BST_H
#define BST_H

#include "LectureFichier.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node {

    const char* nom;

    int index;

    Node* left;

    Node* right;

} Node;

typedef struct database {

    FictionalCharacter* table;

    int size;

} database;

Node* createDatabase(string chemin, database& Db, FictionalCharacter* FicChar);
Node* index(database* db, int NbLigne);
bool insert(Node** current, const char* key, int value);
int get_profondeur(Node* );
bool ControleBST(Node *);
void Search(Node* root, const char* key);
void SearchInRange(Node *root, const char *key1, const char* key2);
void SearchInRangeAge(Node* node, const char* key1, const char* key2, vector<int> &age, database Db);

#endif // BST_H
