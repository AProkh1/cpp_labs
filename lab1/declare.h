//
//  declare.h
//  lab1
//
//  Created by Антон Прохоров on 18/03/2023.
//

#ifndef declare_h
#define declare_h

void changeLargerByRemainder(int* x, int* y);
void changeLargerByRemainder(int& x, int& y);

void roundRealNumber(float* num);
void roundRealNumber(float& num);

void reduceCircleRadius(float* radius, float reduction);
void reduceCircleRadius(float& radius, float reduction);

void transformMatrix(int (*matrix)[3]);
void transformMatrix(int (&matrix)[3][3]);

#endif /* declare_h */
