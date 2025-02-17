#include "societe.h"


Societe::Societe(int nbml, int nbmc) : nbml(nbml), nbmc(nbmc) {
    voitures = new Voiture**[nbml];
    for (int i = 0; i < nbml; ++i) {
        voitures[i] = new Voiture*[nbmc];
        for (int j = 0; j < nbmc; ++j) {
            voitures[i][j] = nullptr;
        }
    }
}

Societe::~Societe() {
    for (int i = 0; i < nbml; ++i) {
        for (int j = 0; j < nbmc; ++j) {
            delete voitures[i][j];
        }
        delete[] voitures[i];
    }
    delete[] voitures;
}

int Societe::hachage(const char* cle) const {
    int h = 0;
    for (int i = 0; cle[i] != '\0'; ++i) {
        h = (h + cle[i]) % nbml;
    }
    return h;
}

void Societe::insertion(const Voiture& v) {
    int ligne = hachage(v.getCle());
    for (int i = 0; i < nbmc; ++i) {
        if (voitures[ligne][i] == nullptr) {
            voitures[ligne][i] = new Voiture(v);
            return;
        }
    }
}

bool Societe::rechercher(const char* cle) const {
    int ligne = hachage(cle);
    for (int i = 0; i < nbmc; ++i) {
        if (voitures[ligne][i] != nullptr && strcmp(voitures[ligne][i]->getCle(), cle) == 0) {
            return true;
        }
    }
    return false;
}

void Societe::suppression(const char* cle) {
    int ligne = hachage(cle);
    for (int i = 0; i < nbmc; ++i) {
        if (voitures[ligne][i] != nullptr && strcmp(voitures[ligne][i]->getCle(), cle) == 0) {
            delete voitures[ligne][i];
            voitures[ligne][i] = nullptr;
            return;
        }
    }
}

void Societe::afficher() const {
    for (int i = 0; i < nbml; ++i) {
        std::cout << "Ligne " << i << ": ";
        bool first = true;
        for (int j = 0; j < nbmc; ++j) {
            if (voitures[i][j] != nullptr) {
                if (!first) std::cout << " ";
                voitures[i][j]->afficher();
                first = false;
            }
        }
        std::cout << "\n";
    }
}

Societe::Societe(const Societe& s) : nbml(s.nbml), nbmc(s.nbmc) {
    voitures = new Voiture**[nbml];
    for (int i = 0; i < nbml; ++i) {
        voitures[i] = new Voiture*[nbmc];
        for (int j = 0; j < nbmc; ++j) {
            if (s.voitures[i][j] != nullptr) {
                voitures[i][j] = new Voiture(*s.voitures[i][j]);
            } else {
                voitures[i][j] = nullptr;
            }
        }
    }
}

Societe& Societe::operator=(const Societe& s) {
    if (this != &s) {
        for (int i = 0; i < nbml; ++i) {
            for (int j = 0; j < nbmc; ++j) {
                delete voitures[i][j];
            }
            delete[] voitures[i];
        }
        delete[] voitures;

        nbml = s.nbml;
        nbmc = s.nbmc;
        voitures = new Voiture**[nbml];
        for (int i = 0; i < nbml; ++i) {
            voitures[i] = new Voiture*[nbmc];
            for (int j = 0; j < nbmc; ++j) {
                if (s.voitures[i][j] != nullptr) {
                    voitures[i][j] = new Voiture(*s.voitures[i][j]);
                } else {
                    voitures[i][j] = nullptr;
                }
            }
        }
    }
    return *this;
}

Societe& Societe::operator<<(const Voiture& v) {
    insertion(v);
    return *this;
}

Societe& Societe::operator>>(const char* cle) {
    suppression(cle);
    return *this;
}

bool Societe::operator%(const char* cle) const {
    return rechercher(cle);
}
