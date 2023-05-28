//
//  QueueOverflowException.h
//  lab_5
//
//  Created by Антон Прохоров on 28/05/2023.
//

#ifndef QueueOverflowException_h
#define QueueOverflowException_h

#include <exception>
#include <string>

namespace AHTOXA{
    class QueueOverflowException : public QueueException {
    public:
        QueueOverflowException(const char* msg) : QueueException(msg) {}
    };
}
#endif /* QueueOverflowException_h */
