#ifndef ARTICLE_H_INCLUDED
#define ARTICLE_H_INCLUDED

#include<iostream>
#include<cstring>
using namespace std;

class Article{
protected:
    int num;
    string des;
    double prix;
public:
    Article(int,string,double);
    ~Article();
    virtual void afficher();

};
#endif
