#ifndef TEST2_H
#define TEST2_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

struct Perso
{
    string prenom;
    string nom;
    string roman;
    int age;

};

struct Database
{
    string actualString;
    int valeur;
    Perso* left;
    Perso* right;
};

int LineCompteur(string chemin);
Perso* load(string chemin);
Perso* init(Perso*);

#endif // TEST2_H
