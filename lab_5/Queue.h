//
//  Queue.h
//  lab_5
//
//  Created by Антон Прохоров on 27/05/2023.
//

#ifndef QUEUE_H
#define QUEUE_H

#include "QueueException.h"
#include "QueueOverflowException.h"
#include "QueueUnderflowException.h"

template<int N, typename T>
class Queue {
private:
    int front;
    int rear;
    T data[N];
public:
    Queue() : front(-1), rear(-1) {}
    
    void enqueue(const T& value) {
        if (rear == N - 1) {
            throw AHTOXA::QueueOverflowException("Queue overflow.");
        }
        if (front == -1 && rear == -1) {
            front = rear = 0;
        } else {
            rear++;
        }
        data[rear] = value;
    }
    
    void dequeue() {
        if (front == -1) {
            throw AHTOXA::QueueUnderflowException("Removing an element from an empty queue.");
        }
        if (front == rear) {
            front = rear = -1;
        } else {
            front++;
        }
    }
    
    T peek() const {
        if (front == -1) {
            throw AHTOXA::QueueUnderflowException("Peeking an empty queue.");
        }
        return data[front];
    }
    
    bool isEmpty() const {
        return front == -1;
    }
    
    bool isFull() const {
        return rear == N - 1;
    }
};

#endif // QUEUE_H
