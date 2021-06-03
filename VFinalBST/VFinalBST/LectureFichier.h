#ifndef LECTUREFICHIER_H
#define LECTUREFICHIER_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

struct FictionalCharacter
{
    string prenom;
    string nom;
    string roman;
    int age;
};

int LineCompteur(string chemin);
FictionalCharacter* load(string chemin, int NbLigne);

#endif // LECTUREFICHIER_H
