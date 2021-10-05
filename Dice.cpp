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

void Dice::add_side(int n, double dP)
{
    if (fullProbability == 1)
        return;
    Side s(n, dP);
    if (fullProbability + s.dropProbability > 1)
        s.dropProbability = 1 - fullProbability;
    fullProbability += s.dropProbability;
    sides.push_back(s);
    sides.merge_sort();
    countOfSides++;
};
