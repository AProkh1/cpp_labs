//
//  main.cpp
//  lab3
//
//  Created by Антон Прохоров on 18/03/2023.
//

#include <iostream>
#include "square.h"
#include "complex_number.h"

int main() {
    // Create a Square object
    Square s(0, 0, 5, 0);
    std::cout << "Square s: " << s << std::endl;
    // Create a Vector2D object and add it to the square
    Vector2D vec(2, 2);
    Square s2 = s + vec;
    std::cout << "Square s2: " << s2 << std::endl;

    // Multiply the square by a real number
    Square s3 = s * 2;
    std::cout << "Square s3: " << s3 << std::endl;

    // Compare two squares
    if (s == s2) {
        std::cout << "s and s2 are equal" << std::endl;
    } else {
        std::cout << "s and s2 are not equal" << std::endl;
    }

    // Create two complex numbers and multiply them
    Complex c1(1, 2);
    Complex c2(3, 4);
    Complex c3 = c1 * c2;
    std::cout << "c3: " << c3 << std::endl;

    return 0;
}
