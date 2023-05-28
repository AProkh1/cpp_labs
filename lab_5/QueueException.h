//
//  QueueException.h
//  lab_5
//
//  Created by Антон Прохоров on 27/05/2023.
//

#ifndef QUEUE_EXCEPTION_H
#define QUEUE_EXCEPTION_H

#include <exception>
#include <string>

namespace AHTOXA{

    class QueueException : public std::exception {
    private:
        std::string message;
        
    public:
        QueueException(const char* msg) : message(msg) {}
        
        const char* what() const noexcept override {
            return message.c_str();
        }
    };
}

#endif // QUEUE_EXCEPTION_H
