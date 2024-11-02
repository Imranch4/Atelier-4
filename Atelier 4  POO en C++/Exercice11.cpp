#include <iostream>
#include <vector>
#include <algorithm>


class Traitement {
private:
    std::vector<int> vecteur;

public:
    void Initialise() { //1.
        int count = 0;
        while (count < 15) {
            std::cout << "Entrez un entier pair non nul: ";
            int valeur;
            std::cin >> valeur;

            if (valeur <= 0 || valeur % 2 != 0) {
                std::cout << "Valeur invalide entrer un entier pair non nul." << std::endl;
            } else {
                vecteur.push_back(valeur);
                count++;
            }
        }
    }

    void show() const { //2.
        if (vecteur.empty()) {
            std::cout << "Le vecteur est vide." << std::endl;
            return;
        }

        std::cout << "Les elements du vecteur sont: ";
        for (const int& val : vecteur) {
            std::cout << val << " ";
        }
        std::cout << "\n" << std::endl;
    }

    friend double moyenne(const Traitement& t); //3
    friend double median(const Traitement& t);
};

double moyenne(const Traitement& t) {
    if (t.vecteur.empty()) {
        throw std::runtime_error("Le vecteur est vide.");
    }
    double sum = 0;
    for (int val : t.vecteur) {
        sum += val;
    }
    return sum / t.vecteur.size();
}

double median(const Traitement& t) {
    if (t.vecteur.empty()) {
        throw std::runtime_error("Le vecteur est vide.");
    }
    std::vector<int> vecteur_trie = t.vecteur;
    std::sort(vecteur_trie.begin(), vecteur_trie.end());
    size_t size = vecteur_trie.size();
    if (size % 2 == 0) {
        return (vecteur_trie[size / 2 - 1] + vecteur_trie[size / 2]) / 2.0;
    } else {
        return vecteur_trie[size / 2];
    }
}

int main() {
    Traitement t;
    t.Initialise();
    t.show();
    try {
        std::cout << "La moyenne est: " << moyenne(t) << std::endl;
        std::cout << "La mediane est: " << median(t) << std::endl;
    } catch (const std::runtime_error& e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}
