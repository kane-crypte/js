#include"Article.h"

Article::Article(int n,string d,double p){
  cout << "Appel de construteur" << this << endl;
  num = n;
  des = d;
  prix = p;
}
Article::~Article(){
 cout << "Appele de destruteur" << this << endl;
}

void Article::afficher(){
 cout << "Article : " << endl;
 cout << "    Numero reference : "<< num << endl;
 cout << "    Description : " << des << endl;
 cout << "    Prix : " << prix << endl;
}
