#include"ArticleImprter.h"

ArticleImporter::ArticleImporter(int n,string d,double p,double t):Article(n,d,p){
    cout << "Appel de construteur" << this << endl;
    Tax = t;
    prix = prix + (40*Tax)/100;
}
ArticleImporter::~ArticleImporter(){
    cout << "Appel des destruteur " << this << endl;

}
void ArticleImporter::afficher(){
  Article::afficher();
  cout << "    Tax : " << Tax << endl;
 }
