//
//  main.cpp
//  lab7
//
//  Created by Антон Прохоров on 11/05/2023.
//

#include <iostream>
#include "RingBuffer.h"

int main() {
    RingBuffer<int> buffer(5);
    buffer.push_back(1);
    buffer.push_back(2);
    buffer.push_back(3);
    buffer.push_front(0);
    buffer.push_back(4);

    for (RingBuffer<int>::Iterator it = buffer.begin(); it != buffer.end(); it++) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    buffer.erase(RingBuffer<int>::Iterator(&buffer, 2));
    buffer.insert(RingBuffer<int>::Iterator(&buffer, 2), 6);

    for (int i = 0; i < buffer.size(); i++) {
        std::cout << buffer.at(i) << " ";
    }
    std::cout << std::endl;

    std::cout << "front: " << buffer.front() << std::endl;
    std::cout << "back: " << buffer.back() << std::endl;

    buffer.pop_front();
    buffer.pop_back();

    for (auto val : buffer) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    return 0;
}
