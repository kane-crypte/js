#include"Personnel.h"

Personnel::Personnel(int m){
    n_max = m;
    taille = 0;
    TabEmployer = new Employer*[n_max];
}
Personnel::~Personnel(){}
void Personnel::ajoute(Employer * e){
    if(taille < n_max) TabEmployer[taille++] = e;
}

void Personnel::affiche_salaires(){
        for(int i = 0; i < taille ; i++){
             cout << " -> ";TabEmployer[i]->afficher();
        }
}
double Personnel::salaire_moyen(){
  double salaire_totale = 0 ;
  for(int i = 0; i< taille ; i++){
     salaire_totale += TabEmployer[i]->calcule_salaire();
  }
  return (salaire_totale/taille);
}
