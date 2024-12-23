#include"ArticleLocal.h"
#include"ArticleImprter.h"
#include"magasin.h"
int main()
{
    Article A(1,"les information sur l'article ",1200.0);
    //A.afficher();

    ArticleImporter Ai(1,"les information sur l'article ",1200.0,200.0);
    //Ai.afficher();

    ArticleLocal Al(1,"les information sur l'article ",1200.0,200.0);
    //Al.afficher();

    Magasin M(100);
    M.ajouter(&A);
    M.ajouter(&Ai);
    M.ajouter(&Al);
    M.affiche();
    return 0;
}
