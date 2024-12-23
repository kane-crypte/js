#include"Evenement.h"

Evenement::Evenement(Date d,string de,double c):date(d){
  cout << "Appel de constructeur" << this << endl;
  //date = d;
  des = de;
  coux = c;
}
Evenement::~Evenement(){
 cout << "Appel de destruteur " << this <<endl;
}

void Evenement::affiche(){
 date.affiche();
 cout << "Description : " << des << endl;
 cout << "Cout :" << coux << endl;
}
