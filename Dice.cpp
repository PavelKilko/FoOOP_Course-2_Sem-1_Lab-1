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

std::ostream& operator<<(std::ostream& out, const Dice &d)
{
    out << "D(" << d.get_count_of_sides() << ") = ";
    auto *currentSide = d.sides.get_front();
    while (currentSide)
    {
        out << currentSide->value;
        currentSide = currentSide->next;
    }
    out << ";";
    return out;
}

std::ostream& operator<<(std::ostream& out, const Dice::Side &s)
{
    out << "[" << s.number << ", " << s.dropProbability << "] ";
    return out;
}

bool operator< (const Dice &d1, const Dice &d2)
{
    if (d1.get_count_of_sides() != d2.get_count_of_sides())
        return d1.get_count_of_sides() < d2.get_count_of_sides();
    else
        return d1.get_full_probability() < d2.get_full_probability();
}

bool operator< (const Dice::Side &s1, const Dice::Side &s2)
{
    if (s1.number != s2.number)
        return s1.number < s2.number;
    else
        return s1.dropProbability < s2.dropProbability;
}

ExpectedSum::ExpectedSum()
{
    sumValue = 0;
    sumProbability = 1;
}

ExpectedSum::ExpectedSum(int sV, double sP)
{
    sumValue = sV;
    sumProbability = sP;
}
