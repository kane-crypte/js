#include <iostream>

template <typename T, size_t MaxSize>
class Pile {
private:
    T tableau[MaxSize];  // Le tableau pour stocker les éléments de la pile
    int topIndex;  // L'indice du sommet de la pile

public:
    // Constructeur qui initialise la pile vide (topIndex = 0)
    Pile() : topIndex(0) {}

    // Ajouter un élément au sommet de la pile
    void push(const T& element) {
        if (topIndex < MaxSize) {
            tableau[topIndex++] = element;  // Ajouter l'élément et incrémenter topIndex
        } else {
            std::cout << "Erreur : La pile est pleine, impossible d'ajouter l'élément." << std::endl;
        }
    }

    // Retirer l'élément au sommet de la pile
    void pop() {
        if (topIndex > 0) {
            --topIndex;  // Décrémenter topIndex pour retirer l'élément
        } else {
            std::cout << "Erreur : La pile est vide, impossible de retirer un élément." << std::endl;
        }
    }

    // Accéder à l'élément au sommet sans le retirer
    T top() const {
        if (topIndex > 0) {
            return tableau[topIndex - 1];  // Retourner l'élément au sommet sans le retirer
        } else {
            std::cout << "Erreur : La pile est vide, il n'y a pas de sommet." << std::endl;
            return T();  // Retourner une valeur par défaut de type T (pour éviter une erreur de compilation)
        }
    }

    // Vérifier si la pile est vide
    bool estVide() const {
        return topIndex == 0;  // La pile est vide quand topIndex est égal à 0
    }

    // Vérifier si la pile est pleine
    bool estPleine() const {
        return topIndex == MaxSize;  // La pile est pleine quand topIndex atteint MaxSize
    }
    // Afficher tous les éléments de la pile
    void afficher() const {
        if (topIndex == 0) {
            std::cout << "La pile est vide." << std::endl;
        } else {
            std::cout << "Contenu de la pile : ";
            for (int i = topIndex - 1; i >= 0; --i) {
                std::cout << tableau[i] << " ";
            }
            std::cout << std::endl;
        }
    }
};

int main() {
    Pile<int, 5> maPileInt;  // Créer une pile d'entiers avec une capacité maximale de 5

    // Tester l'ajout et le retrait d'éléments
    maPileInt.push(10);
    maPileInt.push(20);
    maPileInt.push(30);
    maPileInt.afficher();
    std::cout << "Sommet de la pile d'entiers : " << maPileInt.top() << std::endl;

    maPileInt.pop();  // Retirer un élément
    std::cout << "Sommet après pop : " << maPileInt.top() << std::endl;

    // Tester la pile pleine
    maPileInt.push(40);
    maPileInt.push(50);
    maPileInt.push(60);  // Cette opération échouera car la pile est pleine
    maPileInt.afficher();

    // Tester la pile vide
    maPileInt.pop();
    maPileInt.pop();
    maPileInt.pop();
    maPileInt.afficher();
    maPileInt.pop();  // Cette opération échouera car la pile est vide


    Pile<std::string, 5> maPileString;  // Créer une pile de chaînes de caractères avec une capacité maximale de 5

    // Tester l'ajout et le retrait d'éléments
    maPileString.push("Apple");
    maPileString.push("Banana");
    maPileString.push("Cherry");
    maPileString.afficher();
    std::cout << "Sommet de la pile de chaînes : " << maPileString.top() << std::endl;

    maPileString.pop();  // Retirer un élément
    std::cout << "Sommet après pop : " << maPileString.top() << std::endl;

    // Tester la pile pleine
    maPileString.push("Date");
    maPileString.push("Elderberry");
    maPileString.push("Fig");  // Cette opération échouera car la pile est pleine
    maPileString.afficher();
    // Tester la pile vide
    maPileString.pop();
    maPileString.pop();
    maPileString.pop();
    maPileString.afficher();
    maPileString.pop();
    maPileString.pop();
    maPileString.pop();  // Cette opération échouera car la pile est vide



    return 0;
}
