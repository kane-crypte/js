#include "Employer.h"

Employer::Employer(char *n,char *p,int  a){
    cout << "Appel de construeur " << this <<endl;
    nom = new char[strlen(n)+1];
    strcpy(nom,n);
    prenom = new char[strlen(p)+1];
    strcpy(prenom,p);
    age = a;
}

Employer::~Employer(){
    cout << "Apple de destrueur " << this <<endl;
    delete nom;
    delete prenom;
}

void Employer::afficher(){
    cout << "Employer : "<<endl;
    cout << "Nom :" << nom <<endl;
    cout << "Prenom :" << prenom <<endl;
    cout << "Age :" <<age<<endl;
}
