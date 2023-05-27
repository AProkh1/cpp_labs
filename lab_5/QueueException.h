//
//  QueueException.h
//  lab_5
//
//  Created by Антон Прохоров on 27/05/2023.
//

#ifndef QUEUE_EXCEPTION_H
#define QUEUE_EXCEPTION_H

#include <exception>

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

#endif // QUEUE_EXCEPTION_H
