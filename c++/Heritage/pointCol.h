#ifndef POINTCOL_H_INCLUDED
#define POINTCOL_H_INCLUDED
#include "point.h"

class PointCol : public Point {
private:
    string couleur;
public:
    PointCol(int,int,string);
    ~PointCol();
    string getCouleur();
    void affiche();
};
#endif // POINTCOL_H_INCLUDED
