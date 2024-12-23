#include "point.h"

Point::Point(int a,int o) {
    cout << "Appel de construteur" <<endl;
    x = a;
    y = o;
}
Point::~Point() {
    cout << "Appel de destruteur" <<endl;
}
int Point::getAb(){return x;}
int Point::getOr(){return y;}
Point::Point(const Point& autre){
    x = autre.x;
    y = autre.y;
}
void Point::affiche(){
    cout << "Point est : " << "(" << x << "," << y <<")";
}
