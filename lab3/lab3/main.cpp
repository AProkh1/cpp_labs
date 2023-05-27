//
//  main.cpp
//  lab3
//
//  Created by Антон Прохоров on 18/03/2023.
//

#include <iostream>
#include "Complex.h"
#include "Stack.h"

int main() {
    // Complex Number
    Complex z1(2, 3);
    Complex z2(1, -2);

    Complex z3 = z1 + z2;
    std::cout << "z1 + z2 = ";
    z3.display();

    Complex z4 = z1 * z2;
    std::cout << "z1 * z2 = ";
    z4.display();

    double length = static_cast<double>(z1);
    std::cout << "The length of z1 is " << length << std::endl;

    // Stack of Integers
    Stack stack;
    stack << 5 << 10 << 15;
    stack.display();

    int value;
    stack >> value;
    std::cout << "Removed value from stack: " << value << std::endl;

    stack.display();

    return 0;
}
