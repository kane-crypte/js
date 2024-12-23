#include"Commercial.h"
#include"Manutentionnaire.h"
#include"Personnel.h"

int main()
{
    Commercial E("kane","Alassane",24,18000);


    Manutentionnaire M("ka","Mamadou",30,24);


    Personnel P(5);
    P.ajoute(&E);
    P.ajoute(&M);
    P.affiche_salaires();
    cout << "Moyen des salaire :" << P.salaire_moyen();
    return 0;
}
