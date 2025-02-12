#include <iostream>
#include <cstring>

using namespace std;

// Définition de la structure traduction
struct traduction {
    char* mot1;
    char* mot2;
};

class Dictionnaire {
private:
    traduction** tab;  // Tableau de pointeurs sur struct traduction
    int nb;            // Nombre de mots dans le dictionnaire

public:
    // Constructeur
    Dictionnaire() {
        tab = nullptr;
        nb = 0;
    }

    // Destructeur
    ~Dictionnaire() {
        for (int i = 0; i < nb; i++) {
            delete[] tab[i]->mot1;
            delete[] tab[i]->mot2;
            delete tab[i];
        }
        delete[] tab;
    }

    // Méthode d'ajout en maintenant l'ordre alphabétique
    void ajouter(const char* mot1, const char* mot2) {
        traduction* nouvelle = new traduction;
        nouvelle->mot1 = new char[strlen(mot1) + 1];
        nouvelle->mot2 = new char[strlen(mot2) + 1];
        strcpy(nouvelle->mot1, mot1);
        strcpy(nouvelle->mot2, mot2);

        // Nouveau tableau avec une case de plus
        traduction** nouveauTab = new traduction*[nb + 1];

        // Insérer le nouveau mot au bon endroit pour garder l'ordre
        int i = 0, j = 0;
        while (i < nb && strcmp(tab[i]->mot1, mot1) < 0) {
            nouveauTab[j++] = tab[i++];
        }
        nouveauTab[j++] = nouvelle;
        while (i < nb) {
            nouveauTab[j++] = tab[i++];
        }

        // Supprimer l'ancien tableau et mettre à jour
        delete[] tab;
        tab = nouveauTab;
        nb++;
    }

    // Méthode de recherche dichotomique
    const char* DSearch(const char* mot) {
        int gauche = 0, droite = nb - 1;
        while (gauche <= droite) {
            int milieu = (gauche + droite) / 2;
            int cmp = strcmp(tab[milieu]->mot1, mot);
            if (cmp == 0) return tab[milieu]->mot2;
            else if (cmp < 0) gauche = milieu + 1;
            else droite = milieu - 1;
        }
        return "Mot introuvable";
    }

    // Méthode d'affichage (pour tester)
    void afficher() {
        for (int i = 0; i < nb; i++) {
            cout << tab[i]->mot1 << " -> " << tab[i]->mot2 << endl;
        }
    }
};

// Programme principal
int main() {
    Dictionnaire dico;


    dico.ajouter("pomme", "apple");
    dico.ajouter("maison", "house");
    dico.ajouter("chat", "cat");
    dico.ajouter("chien", "dog");

    cout << "Dictionnaire : " << endl;
    dico.afficher();

    cout << "\nRecherche de 'chien' : " << dico.DSearch("chien") << endl;
    cout << "Recherche de 'oiseau' : " << dico.DSearch("oiseau") << endl;

    return 0;
}
