#include <iostream>
#include "societeliste.h"
#include "voiture.h"

int main() {
    // Cr�ation d'une soci�t� avec 10 listes cha�n�es (pour l'exemple)
    Societeliste societe(10);

    // Cr�ation de quelques objets Voiture
    Voiture voiture1("AB123", "Toyota", "Corolla", 2020, "Berline", "Voiture tr�s fiable");
    Voiture voiture2("CD456", "Honda", "Civic", 2022, "Compacte", "Voiture �conomique");
    Voiture voiture3("EF789", "BMW", "X5", 2021, "SUV", "Voiture de luxe");

    // Insertion des voitures dans la soci�t�
    societe.insertion(voiture1);
    societe.insertion(voiture2);
    societe.insertion(voiture3);

    // Affichage de toutes les voitures dans la soci�t�
    std::cout << "Toutes les voitures dans la soci�t� : " << std::endl;
    societe.afficher();
    std::cout << std::endl;

    // Recherche d'une voiture par cl�
    const char* cleRecherchee = "AB123";
    std::cout << "Recherche de la voiture avec la cl� " << cleRecherchee << " : ";
    if (societe.rechercher(cleRecherchee)) {
        std::cout << "Voiture trouv�e !" << std::endl;
    } else {
        std::cout << "Voiture non trouv�e." << std::endl;
    }

    // Suppression d'une voiture par cl�
    const char* cleASupprimer = "CD456";
    std::cout << "Suppression de la voiture avec la cl� " << cleASupprimer << "..." << std::endl;
    societe.suppression(cleASupprimer);

    // Affichage apr�s suppression
    std::cout << "Affichage apr�s suppression : " << std::endl;
    societe.afficher();

    // Utilisation des op�rateurs surcharg�s
    // Insertion avec l'op�rateur <<
    societe << voiture1;
    std::cout << "Affichage apr�s insertion avec l'op�rateur << : " << std::endl;
    societe.afficher();

    // Recherche avec l'op�rateur %
    const char* cleRecherchee2 = "EF789";
    if (societe % cleRecherchee2) {
        std::cout << "La voiture avec la cl� " << cleRecherchee2 << " est pr�sente." << std::endl;
    } else {
        std::cout << "La voiture avec la cl� " << cleRecherchee2 << " n'est pas pr�sente." << std::endl;
    }

    // Suppression avec l'op�rateur >>
    societe >> cleASupprimer;
    std::cout << "Affichage apr�s suppression avec l'op�rateur >> : " << std::endl;
    societe.afficher();

    return 0;
}
