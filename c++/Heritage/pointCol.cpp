#include "pointCol.h"

PointCol::PointCol(int a,int o,string c):Point(a,o){
    cout << "Appel de construteur de pontCol" <<endl;
    couleur = c;
}
PointCol::~PointCol(){
  cout << "Appel de destruteur PointCol"<<endl;
}
string PointCol::getCouleur(){return couleur;}
void PointCol::affiche(){
   Point::affiche();
   cout << " de couleur " << couleur << endl;

}
