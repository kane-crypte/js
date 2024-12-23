#ifndef BASE_H_INCLUDED
#define BASE_H_INCLUDED

#include<iostream>
using namespace std;

class Base {
public:
    virtual void afficher() = 0;
    virtual int clef() = 0;
};

#endif // BASE_H_INCLUDED
