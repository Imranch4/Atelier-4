#include <iostream>

struct Element {
    int donnees;
    Element* next;
};
class Liste {
private:
    Element* head;

public:
    Liste() : head(nullptr) {}

    ~Liste() {
        while (head != nullptr) {
            Element* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void ajouterDebut(int valeur) {
        Element* nouvelElement = new Element;
        nouvelElement->donnees = valeur;
        nouvelElement->next = head;
        head = nouvelElement;
    }

    void supprimerDebut() {
        if (head != nullptr) {
            Element* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void afficherListe() const {
        Element* courant = head;
        while (courant != nullptr) {
            std::cout << courant->donnees << " ";
            courant = courant->next;
        }
        std::cout << std::endl;
    }
};

int main() {
    Liste maListe;
    maListe.ajouterDebut(5);
    maListe.ajouterDebut(10);
    maListe.ajouterDebut(20);
    maListe.ajouterDebut(40);
    maListe.ajouterDebut(80);
    maListe.ajouterDebut(160);
    maListe.ajouterDebut(320);
    maListe.ajouterDebut(640);
    maListe.ajouterDebut(1280);

    std::cout << "Liste: ";
    maListe.afficherListe();

    maListe.supprimerDebut();
    std::cout << "Liste apres suppression: ";
    maListe.afficherListe();

    return 0;
}
