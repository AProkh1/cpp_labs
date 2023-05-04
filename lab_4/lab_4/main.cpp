//
//  main.cpp
//  lab_4
//
//  Created by Антон Прохоров on 13/04/2023.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include "Header.h"
#include "Ellipse.hpp"

int main()
{
    EquilateralTriangle tr;
    tr.initFromDialog();

    Ellipse el;
    el.initFromDialog();

    Figures fig(tr, el);
    fig.drawAll();

    return 0;
}
