#ifndef LISTE_H_INCLUDED
#define LISTE_H_INCLUDED

#include"Base.h"

class Liste{
private:
    int n_max;
    int taille;
    Base **TabBase;
public:
    Liste(int m);
    void ajouter(Base*);
    void afficher();
};

#endif // LISTE_H_INCLUDED
