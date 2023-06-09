//
//  main.cpp
//  lab1
//
//  Created by Антон Прохоров on 18/03/2023.
//

#include <iostream>
#include "declare.h"
using namespace std;

int main() {
    int x = 10, y = 20;
    cout << "Before changeLargerByRemainder using pointers: x = " << x << ", y = " << y << endl;
    changeLargerByRemainder(&x, &y);
    cout << "After changeLargerByRemainder using pointers: x = " << x << ", y = " << y << endl;
    
    int a = 30, b = 15;
    cout << "Before changeLargerByRemainder using references: a = " << a << ", b = " << b << endl;
    changeLargerByRemainder(a, b);
    cout << "After changeLargerByRemainder using references: a = " << a << ", b = " << b << endl;
    
    float num = 3.6;
    cout << "Before roundRealNumber using pointers: num = " << num << endl;
    roundRealNumber(&num);
}
