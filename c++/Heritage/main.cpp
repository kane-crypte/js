#include "point.h"
#include "pointCol.h"

int main()
{
    Point P(3,4);
    P.affiche();
    Point P1(P);
    P1.affiche();
    PointCol Pc(4,3,"Rouge");
    Pc.affiche();

    return 0;
}
