#ifndef EMPLOYE_H_INCLUDED
#define EMPLOYE_H_INCLUDED

#include"Individu.h"

class Employe : public Individu{
private:
    string competence;
public:
    Employe(int,string,string,string);
    ~Employe();
    void afficher();
    int clef();
    string Getcompetence();
};

#endif // EMPLOYE_H_INCLUDED
