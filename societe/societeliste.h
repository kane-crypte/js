#ifndef SOCIETELISTE_H_INCLUDED
#define SOCIETELISTE_H_INCLUDED

#include "voiture.h"
#include <iostream>
#include <cstring>

// Structure du noeud pour la liste chaînée
struct Noeud {
    Voiture voiture;  // La voiture associée au noeud
    Noeud* suivant;   // Le pointeur vers le prochain noeud

    // Constructeur pour initialiser le noeud avec une voiture
    Noeud(const Voiture& v) : voiture(v), suivant(nullptr) {}
};

// Classe Societeliste pour gérer les voitures
class Societeliste {
private:
    int nbml;  // Nombre de listes chaînées
    Noeud** voitures;  // Tableau de listes chaînées de voitures

    // Fonction de hachage pour obtenir un index pour une clé donnée
    int hachage(const char* cle) const {
        int hash = 0;
        int longueur = strlen(cle);
        for (int i = 0; i < longueur; ++i) {
            hash = (hash * 31 + cle[i]) % nbml;  // Une méthode simple de hachage
        }
        return hash;
    }

public:
    // Constructeur pour initialiser la société avec un nombre de listes
    Societeliste(int nbml) : nbml(nbml) {
        voitures = new Noeud*[nbml];
        for (int i = 0; i < nbml; ++i) {
            voitures[i] = nullptr;  // Initialisation des listes chaînées à null
        }
    }

    // Destructeur pour libérer la mémoire allouée
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

    // Méthode pour insérer une voiture dans la société
    void insertion(const Voiture& v) {
        int index = hachage(v.getCle());  // Calcul de l'index
        Noeud* nouveauNoeud = new Noeud(v);  // Création du nouveau noeud
        nouveauNoeud->suivant = voitures[index];  // Lier au début de la liste
        voitures[index] = nouveauNoeud;  // Insérer en tête de liste
    }

    // Méthode pour rechercher une voiture par sa clé
    bool rechercher(const char* cle) const {
        int index = hachage(cle);  // Calcul de l'index
        Noeud* courant = voitures[index];
        while (courant) {
            if (strcmp(courant->voiture.getCle(), cle) == 0) {
                return true;  // Voiture trouvée
            }
            courant = courant->suivant;
        }
        return false;  // Voiture non trouvée
    }

    // Méthode pour supprimer une voiture par sa clé
    void suppression(const char* cle) {
        int index = hachage(cle);  // Calcul de l'index
        Noeud* courant = voitures[index];
        Noeud* precedent = nullptr;

        while (courant) {
            if (strcmp(courant->voiture.getCle(), cle) == 0) {
                if (precedent) {
                    precedent->suivant = courant->suivant;  // Supprimer du milieu ou fin
                } else {
                    voitures[index] = courant->suivant;  // Supprimer du début
                }
                delete courant;  // Libérer la mémoire
                return;
            }
            precedent = courant;
            courant = courant->suivant;
        }
    }

    // Méthode pour afficher toutes les voitures de la société
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

    // Opérateur d'affectation
    Societeliste& operator=(const Societeliste& s) {
        if (this == &s) return *this;  // Auto-assignation
        // Libérer la mémoire existante
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

    // Surcharge d'opérateurs
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
