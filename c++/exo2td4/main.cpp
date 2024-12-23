#include"Employe.h"
#include"Entrprise.h"
#include"liste.h"
int main()
{
    Employe E(1,"kane","Alassane","Info");
    //E.afficher();
    Individu I(2,"ka","Moussa");
    //I.afficher();
    Entreprise En(1,"Seneau",&I,2);
    //En.afficher();

    Liste L(4);
    L.ajouter(&E);
    L.ajouter(&I);
    L.ajouter(&En);

    L.afficher();
    return 0;
}
