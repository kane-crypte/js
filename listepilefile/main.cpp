#include <iostream>

struct Place {
    void* element;
    Place* suivant;
};

class Liste {
protected:
    int m_longueur;
    Place* m_premier;
    Place* m_courant;

public:
    Liste() : m_longueur(0), m_premier(nullptr), m_courant(nullptr) {}

    Liste(const Liste& autre) : m_longueur(0), m_premier(nullptr), m_courant(nullptr) {
        Place* tmp = autre.m_premier;
        while (tmp) {
            ajouter(m_longueur + 1, tmp->element);
            tmp = tmp->suivant;
        }
    }

    ~Liste() {
        while (m_premier) {
            supprimer(1);
        }
    }

    Liste& operator=(const Liste& autre) {
        if (this != &autre) {
            while (m_premier) supprimer(1);
            Place* tmp = autre.m_premier;
            while (tmp) {
                ajouter(m_longueur + 1, tmp->element);
                tmp = tmp->suivant;
            }
        }
        return *this;
    }

    int ajouter(int i, void* pe) {
        if (i < 1 || i > m_longueur + 1) return -1;

        Place* nouveau = new Place{pe, nullptr};
        if (i == 1) {
            nouveau->suivant = m_premier;
            m_premier = nouveau;
        } else {
            Place* tmp = m_premier;
            for (int j = 1; j < i - 1; ++j) tmp = tmp->suivant;
            nouveau->suivant = tmp->suivant;
            tmp->suivant = nouveau;
        }
        ++m_longueur;
        return 0;
    }

    int supprimer(int i) {
        if (i < 1 || i > m_longueur) return -1;
        Place* tmp = m_premier;

        if (i == 1) {
            m_premier = tmp->suivant;
        } else {
            Place* pred = nullptr;
            for (int j = 1; j < i; ++j) {
                pred = tmp;
                tmp = tmp->suivant;
            }
            pred->suivant = tmp->suivant;
        }
        delete tmp;
        --m_longueur;
        return 0;
    }

    void init() { m_courant = m_premier; }

    int existe() { return m_courant != nullptr; }

    void prochain() {
        if (m_courant) m_courant = m_courant->suivant;
    }

    void* icme(int i) {
        if (i < 1 || i > m_longueur) return nullptr;
        Place* tmp = m_premier;
        for (int j = 1; j < i; ++j) tmp = tmp->suivant;
        return tmp->element;
    }

    int longueur() { return m_longueur; }

    void afficher() {
        Place* tmp = m_premier;
        while (tmp) {
            std::cout << *((int*)tmp->element) << " ";
            tmp = tmp->suivant;
        }
        std::cout << std::endl;
    }
};

class Pile : private Liste {
public:
    Pile() : Liste() {}

    void empiler(void* pe) {
        ajouter(1, pe);
    }

    void* depiler() {
        if (m_longueur == 0) return nullptr;
        void* elem = icme(1);
        supprimer(1);
        return elem;
    }

    void afficherPile() {
        afficher();
    }
};

class File : private Liste {
public:
    File() : Liste() {}

    void enfiler(void* pe) {
        ajouter(m_longueur + 1, pe);
    }

    void* defiler() {
        if (m_longueur == 0) return nullptr;
        void* elem = icme(1);
        supprimer(1);
        return elem;
    }

    void afficherFile() {
        afficher();
    }
};

int main() {
    int a = 10, b = 20, c = 30;

    std::cout << "Test de la Pile\n";
    Pile p;
    p.empiler(&a);
    p.empiler(&b);
    p.empiler(&c);
    std::cout << "Pile après empilement : ";
    p.afficherPile();

    std::cout << "Élément dépilé : " << *((int*)p.depiler()) << std::endl;
    std::cout << "Pile après dépilement : ";
    p.afficherPile();

    std::cout << "\nTest de la File\n";
    File f;
    f.enfiler(&a);
    f.enfiler(&b);
    f.enfiler(&c);
    std::cout << "File après enfilement : ";
    f.afficherFile();

    std::cout << "Élément défilé : " << *((int*)f.defiler()) << std::endl;
    std::cout << "File après défilement : ";
    f.afficherFile();

    return 0;
}
