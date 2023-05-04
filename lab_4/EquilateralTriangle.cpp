//
//  EquilateralTriangle.cpp
//  lab_4
//
//  Created by Антон Прохоров on 02/05/2023.
//

#include "Header.h"
#include <iostream>
#include <cmath>

EquilateralTriangle::EquilateralTriangle() : a_(0), mass_(0), center_of_mass_({0,0}) {}

EquilateralTriangle::EquilateralTriangle(double a, double mass, const CVector2D& center_of_mass) : a_(a), mass_(mass), center_of_mass_(center_of_mass) {}

double EquilateralTriangle::square() const {
    return sqrt(3) / 4 * pow(a_, 2);
}

double EquilateralTriangle::perimeter() const {
    return 3 * a_;
}

double EquilateralTriangle::mass() const {
    return mass_;
}

CVector2D EquilateralTriangle::position() const {
    return center_of_mass_;
}

bool EquilateralTriangle::operator==(const IPhysObject& ob) const {
    return mass_ == ob.mass();
}

bool EquilateralTriangle::operator<(const IPhysObject& ob) const {
    return mass_ < ob.mass();
}

void EquilateralTriangle::draw() const {
    std::cout << "Equilateral Triangle: side length = " << a_ << ", mass = " << mass_ << ", center of mass = (" << center_of_mass_.x << "," << center_of_mass_.y << ")" << std::endl;
}

void EquilateralTriangle::initFromDialog() {
    std::cout << "Enter side length: ";
    std::cin >> a_;
    std::cout << "Enter mass: ";
    std::cin >> mass_;
    std::cout << "Enter x-coordinate of center of mass: ";
    std::cin >> center_of_mass_.x;
    std::cout << "Enter y-coordinate of center of mass: ";
    std::cin >> center_of_mass_.y;
}

const char* EquilateralTriangle::classname() const {
    return "EquilateralTriangle";
}

unsigned int EquilateralTriangle::size() const {
    return sizeof(*this);
}
