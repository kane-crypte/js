#ifndef ENTRPRISE_H_INCLUDED
#define ENTRPRISE_H_INCLUDED


#include"Individu.h"

class Entreprise : public Base{
private:
    int iden;
    string nom;
    Individu *directeur;
    int nbr_salaire;
public:
    Entreprise(int,string,Individu*,int);
    ~Entreprise();
    virtual void afficher();
    virtual int clef();
};


#endif // ENTRPRISE_H_INCLUDED
