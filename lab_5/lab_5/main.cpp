//
//  main.cpp
//  lab_5
//
//  Created by Антон Прохоров on 03/05/2023.
//

#include <iostream>
#include <execution>

template<typename T>
void swap(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}

class QueueException : public std::exception {
public:
    QueueException(const char* msg) : std::exception(msg) {}
};

class QueueOverflowException : public QueueException {
public:
    QueueOverflowException(const char* msg) : QueueException(msg) {}
};

class QueueUnderflowException : public QueueException {
public:
    QueueUnderflowException(const char* msg) : QueueException(msg) {}
};

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
            throw QueueOverflowException("Queue overflow.");
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
            throw QueueUnderflowException("Removing an element from an empty queue.");
        }
        if (front == rear) {
            front = rear = -1;
        } else {
            front++;
        }
    }
    
    T peek() const {
        if (front == -1) {
            throw QueueUnderflowException("Peeking an empty queue.");
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
    } catch (const QueueOverflowException& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }try {
        std::cout << "Dequeuing values..." << std::endl;
        while (!q.isEmpty()) {
            std::cout << q.peek() << std::endl;
            q.dequeue();
        }
        q.dequeue();
    } catch (const QueueUnderflowException& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    return 0;
}

