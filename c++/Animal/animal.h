#ifndef ANIMAL_H_INCLUDED
#define ANIMAL_H_INCLUDED

#include <iostream>
#include <cstring>
using namespace std;

class Animal{
private:
    char * nom;

public:
    Animal(char *);
    ~Animal();
    void exprimer();
};

#endif // ANIMAL_H_INCLUDED
