#ifndef MATCHDEFOOTBALL_H_INCLUDED
#define MATCHDEFOOTBALL_H_INCLUDED

#include"Evenement.h"

class MatchDefootball:public Evenement{
private:
    int nTik;
    double prixTik;
public:
    MatchDefootball(Date d,string s ,double p,int n ,double as):Evenement(d,s,p),nTik(n),prixTik(as){}
    void affiche(){
        Evenement::affiche();
        cout << "Nombre de Ticket : " << nTik << "  Prix du ticket :" << prixTik <<endl;
        cout << "Cout de l'evenement :" << calculeCout() << endl;
    }
    double calculeCout(){
      return coux + (nTik * prixTik * 1.2);
    }
};

#endif // MATCHDEFOOTBALL_H_INCLUDED
