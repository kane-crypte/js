#include"CombatDelutte.h"
#include"MatchDefootball.h"
#include"Agenda.h"
int main()
{

    Agenda Ag(10);
    CombatDelutte combat(Date(12,10,2024),"Combat de lutte ",200000,50000,20000);
    Ag.ajouter(&combat);
    //combat.affiche();

    MatchDefootball football(Date(23,6,2024),"Match de football",100000,50000,10000);
   // football.affiche();
   Ag.ajouter(&football);
   Ag.affiche();

   cout << "Cout Tatal de l'Agenda est : " << Ag.coutTotalAgenda() << endl;
    return 0;
}
