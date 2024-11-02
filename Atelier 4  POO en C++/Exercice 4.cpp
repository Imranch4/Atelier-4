#include <iostream>
#include <cmath>

class vecteur3d {
private:
    float x, y, z;

public:
    vecteur3d(float x = 0, float y = 0, float z = 0) : x(x), y(y), z(z) {}

    void afficher() const {
        std::cout << "(" << x << ", " << y << ", " << z << ")" << std::endl;
    }

    vecteur3d somme(const vecteur3d& v) const {
        return vecteur3d(x + v.x, y + v.y, z + v.z);
    }

    float produitScalaire(const vecteur3d& v) const {
        return x * v.x + y * v.y + z * v.z;
    }

    bool coincide(const vecteur3d& v) const {
        return x == v.x && y == v.y && z == v.z;
    }

    float norme() const {
        return std::sqrt(x * x + y * y + z * z);
    }

    vecteur3d normaxParValeur(const vecteur3d& v) const {
        return (this->norme() > v.norme()) ? *this : v;
    }

    static vecteur3d* normaxParAdresse(const vecteur3d* v1, const vecteur3d* v2) {
        return (v1->norme() > v2->norme()) ? const_cast<vecteur3d*>(v1) : const_cast<vecteur3d*>(v2);
    }

    static vecteur3d& normaxParReference(vecteur3d& v1, vecteur3d& v2) {
        return (v1.norme() > v2.norme()) ? v1 : v2;
    }
};

int main() {
    vecteur3d v1(1.0, 2.0, 3.0);
    vecteur3d v2(4.0, 5.0, 6.0);

    std::cout << "Vecteur v1: ";
    v1.afficher();
    std::cout << "Vecteur v2: ";
    v2.afficher();

    vecteur3d v3 = v1.somme(v2);
    std::cout << "Somme de v1 et v2: ";
    v3.afficher();

    float produit = v1.produitScalaire(v2);
    std::cout << "Produit scalaire de v1 et v2: " << produit << std::endl;

    bool sontEgaux = v1.coincide(v2);
    std::cout << "v1 et v2 ont les memes composantes: " << (sontEgaux ? "Oui" : "Non") << std::endl;

    std::cout << "Norme de v1: " << v1.norme() << std::endl;
    std::cout << "Norme de v2: " << v2.norme() << std::endl;

    vecteur3d v4 = v1.normaxParValeur(v2);
    std::cout << "Vecteur avec la plus grande norme par valeu): ";
    v4.afficher();

    vecteur3d* v5 = vecteur3d::normaxParAdresse(&v1, &v2);
    std::cout << "Vecteur avec la plus grande norme par adresse: ";
    v5->afficher();

    vecteur3d& v6 = vecteur3d::normaxParReference(v1, v2);
    std::cout << "Vecteur avec la plus grande norme par reference: ";
    v6.afficher();

    return 0;
}
