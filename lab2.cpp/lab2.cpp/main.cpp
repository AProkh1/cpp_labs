//
//  main.cpp
//  lab2.cpp
//
//  Created by Антон Прохоров on 18/03/2023.
//

#include <iostream>
#include "Complex.h"

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
