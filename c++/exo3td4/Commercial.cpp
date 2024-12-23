#include"Commercial.h"

Commercial::Commercial(char* n,char* p,int a,double c):Employer(n,p,a){
   chiffre_affaire = c;
}
Commercial::~Commercial(){

}

void Commercial::afficher(){
    Employer::afficher();
    cout << "chiffre d'affaire :" << chiffre_affaire <<endl;
    cout << "Salaire :" << calcule_salaire() <<endl;
}

double Commercial::calcule_salaire(){
    return (((0.2)*chiffre_affaire) + 400);
}
