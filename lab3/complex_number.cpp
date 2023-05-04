//
//  complex_number.cpp
//  lab3
//
//  Created by Антон Прохоров on 18/03/2023.
//

#include "complex_number.h"
#include <cmath>

// Constructors
Complex::Complex() : re_(0), im_(0) {}

Complex::Complex(double re, double im) : re_(re), im_(im) {}

Complex::Complex(const Complex& other) : re_(other.re_), im_(other.im_) {}

Complex::Complex(double re) : re_(re), im_(0) {}

// Operators
Complex Complex::operator*(double real) const {
    return Complex(re_ * real, im_ * real);
}

Complex Complex::operator+(const Complex& other) const {
    return Complex(re_ + other.re_, im_ + other.im_);
}

Complex Complex::operator*(const Complex& other) const {
    return Complex(re_ * other.re_ - im_ * other.im_, re_ * other.im_ + im_ * other.re_);
}

double Complex::operator double() const {
    return std::sqrt(re_ * re_ + im_ * im_);
}

// Length of the complex number
double Complex::length() const {
    return static_cast<double>(*this);
}

// Display on screen
std::ostream& operator<<(std::ostream& os, const Complex& c) {
    os << c.re_ << " + " << c.im_ << "i";
    return os;
}
