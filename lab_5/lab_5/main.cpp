//
//  main.cpp
//  lab_5
//
//  Created by Антон Прохоров on 03/05/2023.
//

#include <iostream>
#include "Queue.h"

int main() {
    Queue<5, int> q;
    try {
        std::cout << "Enqueueing values..." << std::endl;
        q.enqueue(1);
        q.enqueue(2);
        q.enqueue(3);
        q.enqueue(4);
        q.enqueue(5);
        q.enqueue(6);
    } catch (const AHTOXA::QueueOverflowException& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    try {
        std::cout << "Dequeuing values..." << std::endl;
        while (!q.isEmpty()) {
            std::cout << q.peek() << std::endl;
            q.dequeue();
        }
        q.dequeue();
    } catch (const AHTOXA::QueueUnderflowException& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    return 0;
}
