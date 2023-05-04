//
//  declare.cpp
//  lab1
//
//  Created by Антон Прохоров on 18/03/2023.
//

#include <stdio.h>
#include <cmath>
#include "declare.h"

void changeLargerByRemainder(int* x, int* y) {
    if (*x > *y) {
        *x = *x % *y;
    } else {
        *y = *y % *x;
    }
}

void changeLargerByRemainder(int& x, int& y) {
    if (x > y) {
        x = x % y;
    } else {
        y = y % x;
    }
}

void roundRealNumber(float* num) {
    *num = round(*num);
}

void roundRealNumber(float& num) {
    num = round(num);
}

void reduceCircleRadius(float* radius, float reduction) {
    *radius -= reduction;
}

void reduceCircleRadius(float& radius, float reduction) {
    radius -= reduction;
}

void transformMatrix(int (*matrix)[3]) {
    int temp = matrix[0][1];
    matrix[0][1] = matrix[1][0];
    matrix[1][0] = temp;

    temp = matrix[0][2];
    matrix[0][2] = matrix[2][0];
    matrix[2][0] = temp;

    temp = matrix[1][2];
    matrix[1][2] = matrix[2][1];
    matrix[2][1] = temp;
}

void transformMatrix(int (&matrix)[3][3]) {
    int temp = matrix[0][1];
    matrix[0][1] = matrix[1][0];
    matrix[1][0] = temp;

    temp = matrix[0][2];
    matrix[0][2] = matrix[2][0];
    matrix[2][0] = temp;

    temp = matrix[1][2];
    matrix[1][2] = matrix[2][1];
    matrix[2][1] = temp;
}
