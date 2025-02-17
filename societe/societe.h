#ifndef SOCIETE_H_INCLUDED
#define SOCIETE_H_INCLUDED

#include"voiture.h"

class Societe {
private:
    int nbml, nbmc;
    Voiture*** voitures;  // Tableau de pointeurs de voitures

    int hachage(const char* cle) const;  // Fonction de hachage

public:
    Societe(int nbml, int nbmc);
    ~Societe();

    void insertion(const Voiture& v);
    bool rechercher(const char* cle) const;
    void suppression(const char* cle);
    void afficher() const;

    Societe(const Societe& s);  // Constructeur de recopie
    Societe& operator=(const Societe& s);  // Opérateur d'affectation

    // Surcharge d'opérateurs
    Societe& operator<<(const Voiture& v);
    Societe& operator>>(const char* cle);
    bool operator%(const char* cle) const;
};


#endif // SOCIETE_H_INCLUDED
