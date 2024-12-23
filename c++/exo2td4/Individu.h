#ifndef INDIVIDU_H_INCLUDED
#define INDIVIDU_H_INCLUDED

#include"Base.h"

class Individu : public Base{
private:
    int iden;
    string nom;
    string prenom;
public:
    Individu(int,string,string);
    ~Individu();
    virtual void afficher();
    virtual int clef();
};


#endif // INDIVIDU_H_INCLUDED
