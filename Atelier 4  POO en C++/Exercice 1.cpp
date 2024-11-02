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

    cout << "Enter real and imaginary part of first complex number: ";
    cin >> r1 >> i1;
    c1.setValues(r1, i1);

    cout << "Enter real and imaginary part of second complex number: ";
    cin >> r2 >> i2;
    c2.setValues(r2, i2);

    cout << "Choose operation:\n1. Addition\n2. Subtraction\n3. Multiplication\n4. Division\n5. Equality\n";
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
                cout << "The complex numbers are equal." << endl;
            } else {
                cout << "The complex numbers are not equal." << endl;
            }
            break;
        default:
            cout << "Invalid choice!" << endl;
    }

    return 0;
}