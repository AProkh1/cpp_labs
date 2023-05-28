//
//  QueueUnderflowException.h
//  lab_5
//
//  Created by Антон Прохоров on 28/05/2023.
//

#ifndef QueueUnderflowException_h
#define QueueUnderflowException_h

#include <exception>
#include <string>

namespace AHTOXA{
    class QueueUnderflowException : public QueueException {
    public:
        QueueUnderflowException(const char* msg) : QueueException(msg) {}
    };
}

#endif /* QueueUnderflowException_h */
