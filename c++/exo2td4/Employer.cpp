#include"Employe.h"

Employe::Employe(int i,string n,string p,string c):Individu(i,n,p){
    cout << "Appel de construteur " << this << endl;
    competence = c;
}
Employe::~Employe(){
    cout << "Appel des desteuteur " << this <<endl;
}

void Employe::afficher(){
    Individu::afficher();
    cout << "Competence :" << competence << endl;
}
int Employe::clef(){
    Individu::clef();
}
