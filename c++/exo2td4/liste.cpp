#include"liste.h"

Liste::Liste(int m){
    cout << "Appel de construteur " << this << endl;
    n_max = m;
    taille = 0;
    TabBase = new Base*[n_max];
}
void Liste::ajouter(Base* b){
    if(taille < n_max) TabBase[taille++] = b;
}
void Liste::afficher(){
    for(int i = 0; i < taille; i++){
        cout << " -> " << "Employer N0" << i <<endl ;TabBase[i]->afficher();
    }
}
