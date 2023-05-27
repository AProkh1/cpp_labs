//
//  Complex.h
//  lab2.cpp
//
//  Created by Антон Прохоров on 27/05/2023.
//

#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>
#include <cmath>

class Complex {
private:
    double real;
    double imaginary;

public:
    // Default constructor
    Complex() : real(0), imaginary(0) {}

    // Copy constructor
    Complex(const Complex& other) : real(other.real), imaginary(other.imaginary) {}

    // Constructor for a complex number
    Complex(double real, double imaginary) : real(real), imaginary(imaginary) {}

    // Constructor for a real number
    Complex(double real) : real(real), imaginary(0) {}

    // Multiplication of a complex number by a real number
    Complex operator*(double scalar) const {
        return Complex(real * scalar, imaginary * scalar);
    }

    // Addition of two complex numbers
    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imaginary + other.imaginary);
    }

    // Multiplication of two complex numbers
    Complex operator*(const Complex& other) const {
        double resultReal = real * other.real - imaginary * other.imaginary;
        double resultImaginary = real * other.imaginary + imaginary * other.real;
        return Complex(resultReal, resultImaginary);
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

#endif
