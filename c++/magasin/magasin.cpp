#include"magasin.h"

Magasin::Magasin(int m){
 cout << "Appel au construteur " << this << endl;
 nmax = m;
 taille = 0;
 Tab = new Article*[nmax];
}

Magasin::~Magasin(){
 cout << "Appel au destruteur" << this << endl;
 delete Tab;
}
void Magasin::ajouter(Article* A){
 if(taille < nmax) Tab[taille++] = A;
}
void Magasin::affiche(){
    cout << "Magasin : " << endl;
    for(int i = 0; i < taille ; i++){
        Tab[i]->afficher();
    }
}
double Magasin::prixtotal(){
    double prixtotal;
    for(int i = 0; i < taille ; i++){
        //prixtotal+= Tab[i]->prix;
    }
    return prixtotal;
}
