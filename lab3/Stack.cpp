//
//  Stack.cpp
//  lab3
//
//  Created by Антон Прохоров on 27/05/2023.
//

#include "Stack.h"
#include <iostream>

Stack::Stack() : size(0) {}

Stack& Stack::operator<<(int value) {
    if (size < 100) {
        data[size++] = value;
    }
    return *this;
}

Stack& Stack::operator>>(int& value) {
    if (size > 0) {
        value = data[--size];
    }
    return *this;
}

void Stack::display() const {
    for (int i = 0; i < size; ++i) {
        std::cout << data[i] << " ";
    }
    std::cout << std::endl;
}
