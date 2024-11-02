#include <iostream>
#include <string>

class Personne {
private:
    std::string nom;
    std::string prenom;
    std::string dateNaissance;

public:
    Personne(const std::string& nom, const std::string& prenom, const std::string& dateNaissance)
        : nom(nom), prenom(prenom), dateNaissance(dateNaissance) {}

    virtual void Afficher() const {
        std::cout << "Nom: " << nom << ", Prenom: " << prenom << ", Date de Naissance: " << dateNaissance << std::endl;
    }
};

class Employe : public Personne {
private:
    double salaire;

public:
    Employe(const std::string& nom, const std::string& prenom, const std::string& dateNaissance, double salaire)
        : Personne(nom, prenom, dateNaissance), salaire(salaire) {}

    void Afficher() const override {
        Personne::Afficher();
        std::cout << "Salaire: " << salaire << std::endl;
    }
};

class Chef : public Employe {
private:
    std::string service;

public:
    Chef(const std::string& nom, const std::string& prenom, const std::string& dateNaissance, double salaire, const std::string& service)
        : Employe(nom, prenom, dateNaissance, salaire), service(service) {}

    void Afficher() const override {
        Employe::Afficher();
        std::cout << "Service: " << service << std::endl;
    }
};

class Directeur : public Chef {
private:
    std::string societe;

public:
    Directeur(const std::string& nom, const std::string& prenom, const std::string& dateNaissance, double salaire, const std::string& service, const std::string& societe)
        : Chef(nom, prenom, dateNaissance, salaire, service), societe(societe) {}

    void Afficher() const override {
        Chef::Afficher();
        std::cout << "Societe: " << societe << std::endl;
    }
};

int main() {
    Personne p("Adil", "Benrlitom", "02/08/1994");
    Employe e("Smith", "Jane", "02/02/1985", 30000);
    Chef c("Mohamed Amine", "Ouarid", "21/11/1998", 65000, "IT");
    Directeur d("Pujan", "Mehta", "19/04/1972", 900000, "Logistique et de transport", "FedEx");

    p.Afficher();
    e.Afficher();
    c.Afficher();
    d.Afficher();

    return 0;
}
