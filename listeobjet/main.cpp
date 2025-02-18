#include <iostream>
using namespace std;

// Définition de la classe Objet
class Objet {
private:
    int valeur;

public:
    Objet(int v) : valeur(v) {}
    int getValeur() const { return valeur; }
    void afficher() const { cout << "Objet: " << valeur << endl; }
};

// Définition de la structure Noeud en dehors de la classe Liste
struct Noeud {
    Objet* objet;
    Noeud* suivant;

    Noeud(Objet* obj) : objet(obj), suivant(nullptr) {}
};

// Définition de la classe Liste
class Liste {
private:
    Noeud* debut;
    Noeud* fin;

public:
    Liste() : debut(nullptr), fin(nullptr) {}

    ~Liste() {
        Noeud* courant = debut;
        while (courant) {
            Noeud* temp = courant;
            courant = courant->suivant;
            delete temp->objet; // Libération de la mémoire de l'objet
            delete temp;        // Suppression du noeud
        }
    }

    void ajouter(Objet* obj) {
        Noeud* nouveau = new Noeud(obj);
        if (!debut) {
            debut = fin = nouveau;
        } else {
            fin->suivant = nouveau;
            fin = nouveau;
        }
    }

    void afficher() const {
        Noeud* courant = debut;
        while (courant) {
            courant->objet->afficher();
            courant = courant->suivant;
        }
    }
};

// Fonction principale
int main() {
    Liste liste;

    // Ajout d'objets à la liste
    liste.ajouter(new Objet(1));
    liste.ajouter(new Objet(2));
    liste.ajouter(new Objet(3));

    // Affichage des objets de la liste
    liste.afficher();

    return 0;
}
