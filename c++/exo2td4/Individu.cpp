#include"Individu.h"
Individu::Individu(int i,string n,string p){
    cout << "Appel de construteur " << this <<endl;
    iden = i;
    nom = n;
    prenom = p;
}
Individu::~Individu(){
    cout << "Appel de destruteur "<< this <<endl;
}
void Individu::afficher(){
  cout << "Identifient : " << iden << endl;
  cout << "Nom :" << nom <<endl;
  cout << "Prenom : " << prenom << endl;
}
int Individu::clef(){
    return iden;
}
