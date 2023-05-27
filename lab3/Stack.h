//
//  Stack.h
//  lab3
//
//  Created by Антон Прохоров on 27/05/2023.
//

#ifndef STACK_H
#define STACK_H

class Stack {
private:
    int data[100];
    int size;

public:
    Stack();

    Stack& operator<<(int value);
    Stack& operator>>(int& value);

    void display() const;
};

#endif // STACK_H
