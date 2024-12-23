#ifndef POINT_H_INCLUDED
#define POINT_H_INCLUDED

#include <iostream>

using namespace std;
class Point {
private:
    int x;
    int y;
public:
    Point(int,int);
    ~Point();
    int getAb();
    int getOr();
    void affiche();
    Point(const Point&);
};
#endif // POINT_H_INCLUDED
