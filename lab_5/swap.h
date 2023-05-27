//
//  swap.h
//  lab_5
//
//  Created by Антон Прохоров on 27/05/2023.
//

#ifndef SWAP_H
#define SWAP_H

template<typename T>
void swap(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}

#endif // SWAP_H
