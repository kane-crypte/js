#include <iostream>
#include "societeliste.h"
#include "voiture.h"

int main() {
    // Création d'une société avec 10 listes chaînées (pour l'exemple)
    Societeliste societe(10);

    // Création de quelques objets Voiture
    Voiture voiture1("AB123", "Toyota", "Corolla", 2020, "Berline", "Voiture très fiable");
    Voiture voiture2("CD456", "Honda", "Civic", 2022, "Compacte", "Voiture économique");
    Voiture voiture3("EF789", "BMW", "X5", 2021, "SUV", "Voiture de luxe");

    // Insertion des voitures dans la société
    societe.insertion(voiture1);
    societe.insertion(voiture2);
    societe.insertion(voiture3);

    // Affichage de toutes les voitures dans la société
    std::cout << "Toutes les voitures dans la société : " << std::endl;
    societe.afficher();
    std::cout << std::endl;

    // Recherche d'une voiture par clé
    const char* cleRecherchee = "AB123";
    std::cout << "Recherche de la voiture avec la clé " << cleRecherchee << " : ";
    if (societe.rechercher(cleRecherchee)) {
        std::cout << "Voiture trouvée !" << std::endl;
    } else {
        std::cout << "Voiture non trouvée." << std::endl;
    }

    // Suppression d'une voiture par clé
    const char* cleASupprimer = "CD456";
    std::cout << "Suppression de la voiture avec la clé " << cleASupprimer << "..." << std::endl;
    societe.suppression(cleASupprimer);

    // Affichage après suppression
    std::cout << "Affichage après suppression : " << std::endl;
    societe.afficher();

    // Utilisation des opérateurs surchargés
    // Insertion avec l'opérateur <<
    societe << voiture1;
    std::cout << "Affichage après insertion avec l'opérateur << : " << std::endl;
    societe.afficher();

    // Recherche avec l'opérateur %
    const char* cleRecherchee2 = "EF789";
    if (societe % cleRecherchee2) {
        std::cout << "La voiture avec la clé " << cleRecherchee2 << " est présente." << std::endl;
    } else {
        std::cout << "La voiture avec la clé " << cleRecherchee2 << " n'est pas présente." << std::endl;
    }

    // Suppression avec l'opérateur >>
    societe >> cleASupprimer;
    std::cout << "Affichage après suppression avec l'opérateur >> : " << std::endl;
    societe.afficher();

    return 0;
}
