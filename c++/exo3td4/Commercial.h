#ifndef COMMERCIAL_H_INCLUDED
#define COMMERCIAL_H_INCLUDED

#include"Employer.h"

class Commercial :public Employer {
private:
    double chiffre_affaire;
public:
    Commercial(char*,char*,int,double);
    ~Commercial();
    virtual void afficher();
    virtual double calcule_salaire();
};


#endif // COMMERCIAL_H_INCLUDED
