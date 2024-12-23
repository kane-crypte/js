#include"Manutentionnaire.h"

Manutentionnaire::Manutentionnaire(char *n,char *p,int a,int nb):Employer(n,p,a){
    nbr_heure = nb;
}
Manutentionnaire::~Manutentionnaire(){
}
void Manutentionnaire::afficher(){
    Employer::afficher();
    cout << "Nombre d'heure :" << nbr_heure <<endl;
    cout << "Salaire :" << calcule_salaire() <<endl;
}

double Manutentionnaire::calcule_salaire(){
    return (65*nbr_heure);
}
