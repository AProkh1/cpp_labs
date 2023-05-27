//
//  complex_number.cpp
//  lab3
//
//  Created by Антон Прохоров on 18/03/2023.
//

#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>

class Complex {
private:
    double real;
    double imaginary;

public:
    Complex();
    Complex(double real, double imaginary);

    Complex operator*(double scalar) const;
    Complex operator+(const Complex& other) const;
    Complex operator*(const Complex& other) const;
    double operator double() const;

    void display() const;
};

#endif // COMPLEX_H
