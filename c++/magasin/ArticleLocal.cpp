#include"ArticleLocal.h"

ArticleLocal::ArticleLocal(int n,string d,double p,double c):Article(n,d,p){
    cout << "Appel de construteur" << this << endl;
    coux = c;
    prix = prix + coux;
}
ArticleLocal::~ArticleLocal(){
    cout << "Appel des destruteur " << this << endl;

}
void ArticleLocal::afficher(){
  Article::afficher();
  cout << "    coux : " << coux << endl;
 }
