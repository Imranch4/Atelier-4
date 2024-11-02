#include <iostream>
#include <cstring>

class Fichier {
private:
    char* P;
    size_t longueur;

public:

    Fichier() : P(nullptr), longueur(0) {}

    ~Fichier() {
        delete[] P;
    }

    void Creation(size_t taille) {
        P = new char[taille];
        longueur = taille;
    }

    void Remplit() {
        if (P != nullptr) {
            for (size_t i = 0; i < longueur; ++i){
                P[i] = 'A' + (i % 26);
            }
        }
    }

    void Affiche() const {
        if (P != nullptr) {
            for (size_t i = 0; i < longueur; ++i) {
                std::cout << P[i];
            }
            std::cout << std::endl;
        }
    }
};

int main() {

    Fichier* fichier = new Fichier();

    fichier->Creation(100);
    fichier->Remplit();
    fichier->Affiche();

    delete fichier;

    return 0;
}
