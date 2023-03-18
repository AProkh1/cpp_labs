//
//  complex_number.h
//  lab3
//
//  Created by Антон Прохоров on 18/03/2023.
//

#ifndef COMPLEX_NUMBER_H
#define COMPLEX_NUMBER_H

#include <iostream>

class Complex {
public:
    // Constructors
    Complex();
    Complex(double re, double im);
    Complex(const Complex& other);
    explicit Complex(double re);

    // Operators
    Complex operator*(double real) const;
    Complex operator+(const Complex& other) const;
    Complex operator*(const Complex& other) const;
    double operator double() const;

    // Length of the complex number
    double length() const;

    // Display on screen
    friend std::ostream& operator<<(std::ostream& os, const Complex& c);

private:
    double re_;
    double im_;
}; /* complex_number_h */
