#include"Date.h"

Date::Date(int j,int m,int a){
 cout << "Appel de constructeur "<< this << endl;
 jour = j;
 mois = m;
 annee = a;
}
Date::~Date(){
 cout << "Appel de destruteur " << this << endl;
}

void Date::affiche(){
 cout << "Date  : " << jour << "/" << mois << "/" << annee << endl;
}
