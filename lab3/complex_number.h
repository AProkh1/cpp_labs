//
//  complex_number.h
//  lab3
//
//  Created by Антон Прохоров on 18/03/2023.
//

#include "complex_number.h"
#include <cmath>

Complex::Complex() : real(0), imaginary(0) {}

Complex::Complex(double real, double imaginary) : real(real), imaginary(imaginary) {}

Complex Complex::operator*(double scalar) const {
    return Complex(real * scalar, imaginary * scalar);
}

Complex Complex::operator+(const Complex& other) const {
    return Complex(real + other.real, imaginary + other.imaginary);
}

Complex Complex::operator*(const Complex& other) const {
    double resultReal = real * other.real - imaginary * other.imaginary;
    double resultImaginary = real * other.imaginary + imaginary * other.real;
    return Complex(resultReal, resultImaginary);
}

double Complex::operator double() const {
    return std::sqrt(real * real + imaginary * imaginary);
}

void Complex::display() const {
    std::cout << real << " + " << imaginary << "i" << std::endl;
}
