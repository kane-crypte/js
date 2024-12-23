#ifndef COMBATDELUTTE_H_INCLUDED
#define COMBATDELUTTE_H_INCLUDED

#include"Evenement.h"

class CombatDelutte:public Evenement{
private:
    double fs;
    double fa;
public:
    CombatDelutte(Date d,string s ,double p,double se ,double as):Evenement(d,s,p),fs(se),fa(as){}
    void affiche(){
        Evenement::affiche();
        cout << "Frais de secruiter : " << fs << "  Frais d'assurence :" << fa <<endl;
        cout << "Cout de l'evenement :" << calculeCout() << endl;
    }
    double calculeCout(){
      return coux + fs + fa;
    }
};

#endif // COMBATDELUTTE_H_INCLUDED
