#include <iostream>
#include <string>

int main() {
    std::string dateEtheure = "021120240730";

    std::string jour = dateEtheure.substr(0, 2);
    std::string mois = dateEtheure.substr(2, 2);
    std::string annees = dateEtheure.substr(4, 4);
    std::string heures = dateEtheure.substr(8, 2);
    std::string minute = dateEtheure.substr(10, 2);

    std::cout << "Jour : " << jour << std::endl;
    std::cout << "Mois : " << mois << std::endl;
    std::cout << "Année : " << annees << std::endl;
    std::cout << "Heure : " << heures << std::endl;
    std::cout << "Minute : " << minute << std::endl;


    return 0;
}
