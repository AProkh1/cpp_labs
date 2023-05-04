//
//  square.h
//  lab3
//
//  Created by Антон Прохоров on 18/03/2023.
//

#ifndef SQUARE_H
#define SQUARE_H

#include <iostream>

class Vector2D {
public:
    Vector2D();
    Vector2D(double x, double y);

    // Operators
    Vector2D operator+(const Vector2D& other) const;
    Vector2D operator*(double real) const;

    double x() const;
    double y() const;

private:
    double x_;
    double y_;
};

class Square {
public:
    Square();
    Square(double x, double y, double side, double angle);
    Square(const Square& other);

    // Operators
    bool operator==(const Square& other) const;
    bool operator!=(const Square& other) const;
    bool operator<(const Square& other) const;
    bool operator>(const Square& other) const;
    Square operator*(double real) const;
    Square operator+(const Vector2D& vec) const;

    double x() const;
    double y() const;
    double side() const;
    double angle() const;

    // Display on screen
    friend std::ostream& operator<<(std::ostream& os, const Square& s);

private:
    double x_;
    double y_;
    double side_;
    double angle_;
};

#endif /* square_h */
