#ifndef DATABASE_H
#define DATABASE_H
#include <iostream>
#include "LectureFichier.h"
#include "BST.h"

using namespace std;

typedef struct {

    FictionalCharacter* table;

    int size;

} database;


Node* createDatabase(string chemin);



#endif // DATABASE_H

