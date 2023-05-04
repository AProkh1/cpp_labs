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
    
    int rows = 3;
    int cols = 4;

    // create a vector of vectors
    vector<vector<int>> matrix(rows, vector<int>(cols));

    // fill the matrix with values
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = i * cols + j;
        }
    }

    // print the matrix
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}
