#ifndef AGENDA_H_INCLUDED
#define AGENDA_H_INCLUDED

#include"Evenement.h"

class Agenda{
private:
    int taille;int nmax;
    Evenement **TEvenement;
public:
    Agenda(int m):nmax(m),taille(0){
        TEvenement = new Evenement*[nmax];
    }
    void ajouter(Evenement* E){
      if(taille<nmax) TEvenement[taille++] = E;
    }
    void affiche(){
       cout << "Agenda : " << endl;
       cout << "" << endl;
       for(int i = 0 ; i< taille ; i++){
            TEvenement[i]->affiche();
            cout << "" << endl;
       }
    }
    double coutTotalAgenda(){
     double coutTotale;
     for(int i = 0 ; i< taille ; i++){
            coutTotale+=TEvenement[i]->calculeCout();
       }
       return coutTotale;
    }
};

#endif // AGENDA_H_INCLUDED
