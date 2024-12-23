#ifndef MANUTENTIONNAIRE_H_INCLUDED
#define MANUTENTIONNAIRE_H_INCLUDED

#include"Employer.h"

class Manutentionnaire :public Employer {
private:
    int nbr_heure;

public:
    Manutentionnaire(char*,char*,int,int);
    ~Manutentionnaire();
    virtual void afficher();
    virtual double calcule_salaire();

};

#endif // MANUTENTIONNAIRE_H_INCLUDED
