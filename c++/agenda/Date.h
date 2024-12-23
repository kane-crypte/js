#ifndef DATE_H_INCLUDED
#define DATE_H_INCLUDED

#include<iostream>
#include<cstring>

using namespace std;

class Date{
private:
    int jour;
    int mois;
    int annee;
public:
    Date(int,int,int);
    ~Date();
    void affiche();
};

#endif // DATE_H_INCLUDED
