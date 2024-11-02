#include <iostream>
using namespace std;

class Complex {
private:
    double real;
    double imag;

public:
    Complex(double r = 0, double i = 0) : real(r), imag(i) {}

    void setValues(double r, double i) {
        real = r;
        imag = i;
    }

    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imag + other.imag);
    }

    Complex operator-(const Complex& other) const {
        return Complex(real - other.real, imag - other.imag);
    }

    Complex operator*(const Complex& other) const {
        return Complex(real * other.real - imag * other.imag, real * other.imag + imag * other.real);
    }

    Complex operator/(const Complex& other) const {
        double denominator = other.real * other.real + other.imag * other.imag;
        return Complex((real * other.real + imag * other.imag) / denominator, 
                       (imag * other.real - real * other.imag) / denominator);
    }

    bool operator==(const Complex& other) const {
        return real == other.real && imag == other.imag;
    }

    void display() const {
        cout << real << " + " << imag << "i" << endl;
    }
};

int main() {
    double r1, i1, r2, i2;
    int choice;
    Complex c1, c2, result;

    cout << "Entrez la partie reelle et la partie imaginaire du premier nombre complexe: ";
    cin >> r1 >> i1;
    c1.setValues(r1, i1);

    cout << "Entrez la partie reelle et la partie imaginaire du deuxième nombre complexe: ";
    cin >> r2 >> i2;
    c2.setValues(r2, i2);

    cout << "Choisissez une opération :\n1. Addition\n2. Soustraction\n3. Multiplication\n4. Division\n5. Égalité\n";
    cin >> choice;

    switch (choice) {
        case 1:
            result = c1 + c2;
            cout << "Result: ";
            result.display();
            break;
        case 2:
            result = c1 - c2;
            cout << "Result: ";
            result.display();
            break;
        case 3:
            result = c1 * c2;
            cout << "Result: ";
            result.display();
            break;
        case 4:
            result = c1 / c2;
            cout << "Result: ";
            result.display();
            break;
        case 5:
            if (c1 == c2) {
                cout << "Les nombres complexes sont égaux." << endl;
            } else {
                cout << "Les nombres imaginaire sont égaux." << endl;
            }
            break;
        default:
            cout << "Choix invalide!" << endl;
    }

    return 0;
}
