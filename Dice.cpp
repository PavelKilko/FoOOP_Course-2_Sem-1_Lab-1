//
// Created by Pavel on 10/6/2021.
//

#include "Dice.h"


Dice::Dice()
{
    countOfSides = 0;
    fullProbability = 0;
}

Dice::Dice(int c)
{
    if (c < 1) c = 1;
    countOfSides = c;
    fullProbability = 1;
    for (int i = 1; i <= countOfSides; i++)
    {
        Side s(i, 1.0 / c);
        sides.push_back(s);
    }
}

