#include <iostream>

using namespace std;

class MatriceCreuse {
private:
    int nlig;
    int ncol;
    int* M;

public:
    // Constructeur : initialise la matrice avec des zéros
    MatriceCreuse(int lignes, int colonnes) {
        nlig = lignes;
        ncol = colonnes;
        M = new int[nlig * ncol];

        // Initialisation manuelle à 0
        for (int i = 0; i < nlig * ncol; i++) {
            M[i] = 0;
        }
    }

    // Destructeur : libérer la mémoire
    ~MatriceCreuse() {
        delete[] M;
    }

    // Accès aux éléments de la matrice
    int& operator()(int i, int j) {
        return M[i * ncol + j];
    }

    // Affichage de la matrice
    void afficher() {
        for (int i = 0; i < nlig; i++) {
            for (int j = 0; j < ncol; j++) {
                cout << M[i * ncol + j] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    MatriceCreuse mat(3, 3);

    mat(0, 1) = 5;
    mat(1, 2) = 8;
    mat(2, 0) = 3;

    cout << "Matrice creuse :" << endl;
    mat.afficher();

    return 0;
}
