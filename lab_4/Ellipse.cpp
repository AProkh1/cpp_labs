//
//  Ellipse.cpp
//  lab_4
//
//  Created by Антон Прохоров on 02/05/2023.
//

#include "Header.h"
#include <iostream>
#include <cmath>

Ellipse::Ellipse() : a_(0), b_(0), mass_(0), center_of_mass_({0,0}) {}

Ellipse::Ellipse(double a, double b, double mass, const CVector2D& center_of_mass) : a_(a), b_(b), mass_(mass), center_of_mass_(center_of_mass) {}

double Ellipse::square() const {
    return M_PI * a_ * b_;
}

double Ellipse::perimeter() const {
    return 4 * (M_PI * a_ * b_ + pow(a_ - b_, 2)) / (a_ + b_);
}

double Ellipse::mass() const {
    return mass_;
}

CVector2D Ellipse::position() const {
    return center_of_mass_;
}

bool Ellipse::operator==(const IPhysObject& ob) const {
    return mass_ == ob.mass();
}

bool Ellipse::operator<(const IPhysObject& ob) const {
    return mass_ < ob.mass();
}

void Ellipse::draw() const {
    std::cout << "Ellipse: semi-axes = (" << a_ << "," << b_ << "), mass = " << mass_ << ", center of mass = (" << center_of_mass_.x << "," << center_of_mass_.y << ")" << std::endl;
}

void Ellipse::initFromDialog() {
    std::cout << "Enter semi-axis a: ";
    std::cin >> a_;
    std::cout << "Enter semi-axis b: ";
    std::cin >> b_;
    std::cout << "Enter mass: ";
    std::cin >> mass_;
    std::cout << "Enter x-coordinate of center of mass: ";
    std::cin >> center_of_mass_.x;
    std::cout << "Enter y-coordinate of center of mass: ";
    std::cin >> center_of_mass_.y;
}

const char* Ellipse::classname() const {
    return "Ellipse";
}

unsigned int Ellipse::size() const {
    return sizeof(*this);
}
