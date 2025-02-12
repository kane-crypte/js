#include <iostream>
#include <string>

using namespace std;

// Classe de base : Personne
class Personne {
protected:
    string nom;
    string adresse;
    int anneeArrivee;

public:
    Personne(string n, string a, int annee) : nom(n), adresse(a), anneeArrivee(annee) {}

    virtual void afficher() const {
        cout << "Nom : " << nom << "\nAdresse : " << adresse << "\nAnnée d'arrivée : " << anneeArrivee << endl;
    }

    virtual int getAnciennete(int anneeActuelle) const {
        return anneeActuelle - anneeArrivee;
    }

    virtual ~Personne() {}
};

// Classe Etudiant
class Etudiant : public Personne {
private:
    double moyenneAnnuelle;

public:
    Etudiant(string n, string a, int annee, double moyenne)
        : Personne(n, a, annee), moyenneAnnuelle(moyenne) {}

    void afficher() const override {
        Personne::afficher();
        cout << "Type : Etudiant\nMoyenne Annuelle : " << moyenneAnnuelle << endl;
    }
};

// Classe Personnel (hérite de Personne)
class Personnel : public Personne {
protected:
    string bureau;

public:
    Personnel(string n, string a, int annee, string b)
        : Personne(n, a, annee), bureau(b) {}

    void afficher() const override {
        Personne::afficher();
        cout << "Type : Personnel\nBureau : " << bureau << endl;
    }
};

// Classe Administratif (hérite de Personnel)
class Administratif : public Personnel {
public:
    Administratif(string n, string a, int annee, string b)
        : Personnel(n, a, annee, b) {}

    void afficher() const override {
        Personnel::afficher();
        cout << "Rôle : Administratif" << endl;
    }
};

// Classe Enseignant (hérite de Personnel)
class Enseignant : public Personnel {
protected:
    string numCasier;
    double salaire;

public:
    Enseignant(string n, string a, int annee, string b, string casier, double s)
        : Personnel(n, a, annee, b), numCasier(casier), salaire(s) {}

    void afficher() const override {
        Personnel::afficher();
        cout << "Rôle : Enseignant\nNuméro de Casier : " << numCasier
             << "\nSalaire Mensuel : " << salaire << " €" << endl;
    }
};

// Classe Vacataire (hérite de Enseignant)
class Vacataire : public Enseignant {
private:
    int heuresTravaillees;
    double tarifHoraire;

public:
    Vacataire(string n, string a, int annee, string b, string casier, int heures, double tarif)
        : Enseignant(n, a, annee, b, casier, 0), heuresTravaillees(heures), tarifHoraire(tarif) {}

    void afficher() const override {
        Personnel::afficher();
        cout << "Rôle : Vacataire\nNuméro de Casier : " << numCasier
             << "\nHeures Travaillées : " << heuresTravaillees
             << "\nTarif Horaire : " << tarifHoraire
             << "\nSalaire Mensuel Calculé : " << (heuresTravaillees * tarifHoraire) << " €" << endl;
    }
};

// Classe Institut
class Institut {
private:
    string nom;
    Personne** membres;

public:
    Institut(string nom) : nom(nom), membres(nullptr) {}

    ~Institut() {
        delete[] membres;
    }

    void ajouterMembre(Personne* membre) {
        int count = 0;
        while (membres && membres[count]) count++;

        Personne** temp = new Personne*[count + 2];

        for (int i = 0; i < count; i++) {
            temp[i] = membres[i];
        }

        temp[count] = membre;
        temp[count + 1] = nullptr;

        delete[] membres;
        membres = temp;
    }

    void afficherMembres() const {
        cout << "Institut : " << nom << "\nListe des membres :\n";
        if (!membres) {
            cout << "Aucun membre enregistré.\n";
            return;
        }

        int i = 0;
        while (membres[i]) {
            membres[i]->afficher();
            cout << "---------------------\n";
            i++;
        }
    }

    void afficherAncienneteMoyenne(int anneeActuelle) const {
        if (!membres) {
            cout << "Aucun membre enregistré.\n";
            return;
        }

        int total = 0, count = 0;
        while (membres[count]) {
            total += membres[count]->getAnciennete(anneeActuelle);
            count++;
        }

        cout << "Ancienneté moyenne : " << (count ? (total / count) : 0) << " ans\n";
    }
};

// Programme principal
int main() {
    Institut institut("AVENIR");

    institut.ajouterMembre(new Enseignant("Jean", "Paris", 2010, "B102", "C12", 3000));
    institut.ajouterMembre(new Administratif("Claire", "Lyon", 2015, "A201"));
    institut.ajouterMembre(new Etudiant("Alex", "Marseille", 2021, 15.2));
    institut.ajouterMembre(new Vacataire("Paul", "Toulouse", 2018, "B205", "C30", 20, 50));

    institut.afficherMembres();
    institut.afficherAncienneteMoyenne(2025);

    return 0;
}
