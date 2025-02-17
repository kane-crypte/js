#ifndef SOCIETELISTE_H_INCLUDED
#define SOCIETELISTE_H_INCLUDED

#include "voiture.h"
#include <iostream>
#include <cstring>

// Structure du noeud pour la liste cha�n�e
struct Noeud {
    Voiture voiture;  // La voiture associ�e au noeud
    Noeud* suivant;   // Le pointeur vers le prochain noeud

    // Constructeur pour initialiser le noeud avec une voiture
    Noeud(const Voiture& v) : voiture(v), suivant(nullptr) {}
};

// Classe Societeliste pour g�rer les voitures
class Societeliste {
private:
    int nbml;  // Nombre de listes cha�n�es
    Noeud** voitures;  // Tableau de listes cha�n�es de voitures

    // Fonction de hachage pour obtenir un index pour une cl� donn�e
    int hachage(const char* cle) const {
        int hash = 0;
        int longueur = strlen(cle);
        for (int i = 0; i < longueur; ++i) {
            hash = (hash * 31 + cle[i]) % nbml;  // Une m�thode simple de hachage
        }
        return hash;
    }

public:
    // Constructeur pour initialiser la soci�t� avec un nombre de listes
    Societeliste(int nbml) : nbml(nbml) {
        voitures = new Noeud*[nbml];
        for (int i = 0; i < nbml; ++i) {
            voitures[i] = nullptr;  // Initialisation des listes cha�n�es � null
        }
    }

    // Destructeur pour lib�rer la m�moire allou�e
    ~Societeliste() {
        for (int i = 0; i < nbml; ++i) {
            Noeud* courant = voitures[i];
            while (courant) {
                Noeud* temp = courant;
                courant = courant->suivant;
                delete temp;
            }
        }
        delete[] voitures;
    }

    // M�thode pour ins�rer une voiture dans la soci�t�
    void insertion(const Voiture& v) {
        int index = hachage(v.getCle());  // Calcul de l'index
        Noeud* nouveauNoeud = new Noeud(v);  // Cr�ation du nouveau noeud
        nouveauNoeud->suivant = voitures[index];  // Lier au d�but de la liste
        voitures[index] = nouveauNoeud;  // Ins�rer en t�te de liste
    }

    // M�thode pour rechercher une voiture par sa cl�
    bool rechercher(const char* cle) const {
        int index = hachage(cle);  // Calcul de l'index
        Noeud* courant = voitures[index];
        while (courant) {
            if (strcmp(courant->voiture.getCle(), cle) == 0) {
                return true;  // Voiture trouv�e
            }
            courant = courant->suivant;
        }
        return false;  // Voiture non trouv�e
    }

    // M�thode pour supprimer une voiture par sa cl�
    void suppression(const char* cle) {
        int index = hachage(cle);  // Calcul de l'index
        Noeud* courant = voitures[index];
        Noeud* precedent = nullptr;

        while (courant) {
            if (strcmp(courant->voiture.getCle(), cle) == 0) {
                if (precedent) {
                    precedent->suivant = courant->suivant;  // Supprimer du milieu ou fin
                } else {
                    voitures[index] = courant->suivant;  // Supprimer du d�but
                }
                delete courant;  // Lib�rer la m�moire
                return;
            }
            precedent = courant;
            courant = courant->suivant;
        }
    }

    // M�thode pour afficher toutes les voitures de la soci�t�
    void afficher() const {
        for (int i = 0; i < nbml; ++i) {
            Noeud* courant = voitures[i];
            while (courant) {
                courant->voiture.afficher();  // Afficher la voiture
                courant = courant->suivant;
            }
        }
    }

    // Constructeur de recopie
    Societeliste(const Societeliste& s) : nbml(s.nbml) {
        voitures = new Noeud*[nbml];
        for (int i = 0; i < nbml; ++i) {
            voitures[i] = nullptr;
            Noeud* courant = s.voitures[i];
            while (courant) {
                this->insertion(courant->voiture);  // Re-insertion de chaque voiture
                courant = courant->suivant;
            }
        }
    }

    // Op�rateur d'affectation
    Societeliste& operator=(const Societeliste& s) {
        if (this == &s) return *this;  // Auto-assignation
        // Lib�rer la m�moire existante
        for (int i = 0; i < nbml; ++i) {
            Noeud* courant = voitures[i];
            while (courant) {
                Noeud* temp = courant;
                courant = courant->suivant;
                delete temp;
            }
        }
        delete[] voitures;

        nbml = s.nbml;
        voitures = new Noeud*[nbml];
        for (int i = 0; i < nbml; ++i) {
            voitures[i] = nullptr;
            Noeud* courant = s.voitures[i];
            while (courant) {
                this->insertion(courant->voiture);  // Re-insertion de chaque voiture
                courant = courant->suivant;
            }
        }
        return *this;
    }

    // Surcharge d'op�rateurs
    Societeliste& operator<<(const Voiture& v) {
        this->insertion(v);
        return *this;
    }

    Societeliste& operator>>(const char* cle) {
        this->suppression(cle);
        return *this;
    }

    bool operator%(const char* cle) const {
        return this->rechercher(cle);
    }
};

#endif // SOCIETELISTE_H_INCLUDED
