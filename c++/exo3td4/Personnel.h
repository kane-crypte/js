#ifndef PERSONNEL_H_INCLUDED
#define PERSONNEL_H_INCLUDED

#include"Employer.h"

class Personnel {
private:
    int n_max;
    int taille;
    Employer **TabEmployer;

public:
    Personnel(int ma);
    ~Personnel();
    void ajoute(Employer*);
    void affiche_salaires();
    double salaire_moyen();
};

#endif // PERSONNEL_H_INCLUDED
