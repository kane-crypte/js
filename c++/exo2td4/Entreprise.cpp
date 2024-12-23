#include"Entrprise.h"

Entreprise::Entreprise(int i,string n,Individu* I ,int nb){
    cout << "Appel de construsteur " << this << endl;
    iden = i;
    nom = n;
    directeur = I;
    nbr_salaire = nb;
}
Entreprise::~Entreprise(){
    cout << "Appel de destruteur "<< this <<endl;

}
void Entreprise::afficher(){
    cout << "Identifient : " << iden << endl;
    cout << "Nom :" << nom <<endl;
    cout << "Le directeur est :" <<endl;
    directeur->afficher();
}
int Entreprise::clef(){
    return iden;
}
