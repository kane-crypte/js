#ifndef VOITURE_H_INCLUDED
#define VOITURE_H_INCLUDED

#include<iostream>
#include<cstring>

using namespace std;

class Voiture {
private:
    char* cles;
    char* marque;
    char* gamme;
    int annee;
    char* modele;
    char* presentation;

public:
    // Constructeur
    Voiture(char* c, char* m, char* g, int a, char* mod, char* p)
        : annee(a)
    {
        cles = new char[strlen(c) + 1];
        strcpy(cles, c);

        marque = new char[strlen(m) + 1];
        strcpy(marque, m);

        gamme = new char[strlen(g) + 1];
        strcpy(gamme, g);

        modele = new char[strlen(mod) + 1];
        strcpy(modele, mod);

        presentation = new char[strlen(p) + 1];
        strcpy(presentation, p);
    }

    // Destructeur
    ~Voiture() {
        delete[] cles;
        delete[] marque;
        delete[] gamme;
        delete[] modele;
        delete[] presentation;
    }

    // Méthode pour afficher les informations de la voiture
    void afficher() {
        std::cout << "Clé: " << cles << std::endl;
        std::cout << "Marque: " << marque << std::endl;
        std::cout << "Gamme: " << gamme << std::endl;
        std::cout << "Année: " << annee << std::endl;
        std::cout << "Modèle: " << modele << std::endl;
        std::cout << "Présentation: " << presentation << std::endl;
    }

    // Getter pour la clé
    const char* getCle() const {
        return cles;
    }

    // Constructeur de copie
    Voiture(const Voiture& v)
        : annee(v.annee) {
        cles = new char[strlen(v.cles) + 1];
        strcpy(cles, v.cles);

        marque = new char[strlen(v.marque) + 1];
        strcpy(marque, v.marque);

        gamme = new char[strlen(v.gamme) + 1];
        strcpy(gamme, v.gamme);

        modele = new char[strlen(v.modele) + 1];
        strcpy(modele, v.modele);

        presentation = new char[strlen(v.presentation) + 1];
        strcpy(presentation, v.presentation);
    }

    // Opérateur d'assignation
    Voiture& operator=(const Voiture& v) {
        if (this != &v) {  // Éviter l'auto-affectation
            delete[] cles;
            delete[] marque;
            delete[] gamme;
            delete[] modele;
            delete[] presentation;

            cles = new char[strlen(v.cles) + 1];
            strcpy(cles, v.cles);

            marque = new char[strlen(v.marque) + 1];
            strcpy(marque, v.marque);

            gamme = new char[strlen(v.gamme) + 1];
            strcpy(gamme, v.gamme);

            modele = new char[strlen(v.modele) + 1];
            strcpy(modele, v.modele);

            presentation = new char[strlen(v.presentation) + 1];
            strcpy(presentation, v.presentation);

            annee = v.annee;
        }
        return *this;
    }
};




#endif // VOITURE_H_INCLUDED
