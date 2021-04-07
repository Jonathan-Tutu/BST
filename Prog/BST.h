#ifndef BST_H
#define BST_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "Test2.h"
typedef struct Node {

    const char* key;

    int table_rank;

    Node* left;

    Node* right;

} Node;

Node* index(Perso* db);
bool insert(Node** current, const char* key, int value);

#endif // BST_H
