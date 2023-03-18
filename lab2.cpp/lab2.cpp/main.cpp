//
//  main.cpp
//  lab2.cpp
//
//  Created by Антон Прохоров on 18/03/2023.
//

#include <iostream>
#include <cmath>

class Complex {
private:
    double real;
    double imaginary;

public:
    Complex() : real(0), imaginary(0) {}

    // Copy constructor
    Complex(const Complex& other) : real(other.real), imaginary(other.imaginary) {}

    // Constructor for a complex number
    Complex(double real, double imaginary) : real(real), imaginary(imaginary) {}

    // Constructor for a real number
    Complex(double real) : real(real), imaginary(0) {}

    // Multiplication of a complex number by a real number
    Complex operator*(double real) const {
        return Complex(this->real * real, this->imaginary * real);
    }

    // Addition of two complex numbers
    Complex operator+(const Complex& other) const {
        return Complex(this->real + other.real, this->imaginary + other.imaginary);
    }

    // Multiplication of two complex numbers
    Complex operator*(const Complex& other) const {
        double real = this->real * other.real - this->imaginary * other.imaginary;
        double imaginary = this->real * other.imaginary + this->imaginary * other.real;
        return Complex(real, imaginary);
    }

    // Length of a complex number
    double length() const {
        return std::sqrt(real * real + imaginary * imaginary);
    }

    // Display on screen
    void display() const {
        std::cout << real << " + " << imaginary << "i" << std::endl;
    }
};

int main() {
    Complex z1(2, 3);
    Complex z2(1, -2);

    Complex z3 = z1 + z2;
    std::cout << "z1 + z2 = ";
    z3.display();

    Complex z4 = z1 * z2;
    std::cout << "z1 * z2 = ";
    z4.display();

    Complex z5 = z1 * 2.5;
    std::cout << "z1 * 2.5 = ";
    z5.display();

    std::cout << "The length of z1 is " << z1.length() << std::endl;

    return 0;
}
