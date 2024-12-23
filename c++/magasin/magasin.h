#ifndef MAGASIN_H_INCLUDED
#define MAGASIN_H_INCLUDED

#include"Article.h"


class Magasin{
private:
    int nmax;
    int taille;
    Article **Tab;
public:
    Magasin(int);
    ~Magasin();
    void ajouter(Article*);
    void affiche();
    double prixtotal();
};


#endif // MAGASIN_H_INCLUDED
