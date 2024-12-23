#ifndef EVENEMENT_H_INCLUDED
#define EVENEMENT_H_INCLUDED

#include"Date.h"

struct Datee{
    int jour;
    int mois;
    int annee;
};

class Evenement{
protected:
    Date date;
    string des;
    double  coux;
public:
    Evenement(Date,string,double);
    ~Evenement();
    virtual void affiche();
    virtual double calculeCout() = 0;

};
#endif // EVENEMENT_H_INCLUDED
