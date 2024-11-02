#include <iostream>
#include <string>

class Animal {
protected:
    std::string name;
    int age;

public:
    void set_value(std::string n, int a) {
        name = n;
        age = a;
    }
};

class Zebra : public Animal {
public:
    void affichage() {
        std::cout << "Zebra Nom: " << name << ", Age: " << age << std::endl;
        std::cout << "Les zebres vivent dans des plaines semi-arides, comme en Somalie, a Djibouti et en Erythrée." << std::endl;
    }
};

class Dolphin : public Animal {
public:
    void affichage() {
        std::cout << "Dolphin Nom: " << name << ", Age: " << age << std::endl;
        std::cout << "Le dauphin vit dans des zones temperees et tropicales de la planete. Selon l'espece, il peut vivre dans des eaux douces ou dans l'ocean." << std::endl;
    }
};

int main() {
    Zebra z;
    Dolphin d;

    z.set_value("Dottie",19);
    d.set_value("Coral", 16);

    z.affichage();
    d.affichage();

    return 0;
}
