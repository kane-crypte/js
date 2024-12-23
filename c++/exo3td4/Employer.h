#ifndef EMPLOYER_H_INCLUDED
#define EMPLOYER_H_INCLUDED

#include<iostream>
#include<cstring>
using namespace std;

class Employer {
private:
    char *nom;
    char *prenom;
    int age;
public:
    Employer(char*,char*,int);
    ~Employer();
    virtual void afficher() = 0;
    virtual double calcule_salaire() = 0;
};

#endif // EMPLOYER_H_INCLUDED
