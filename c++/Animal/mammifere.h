#ifndef MAMMIFERE_H_INCLUDED
#define MAMMIFERE_H_INCLUDED

#include "animal.h"

class Mammifere :public Animal {
public:
    Mammifere();
    ~Mammifere();
    void exprimer();
};

#endif // MAMMIFERE_H_INCLUDED
