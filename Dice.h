//
// Created by Pavel on 10/6/2021.
//

#ifndef LAB1_DICE_H
#define LAB1_DICE_H

#include "List.h"

class Dice
{
private:
    int countOfSides;
    double fullProbability;
    class Side
    {
    public:
        int number;
        double dropProbability;

        Side()
        {
            number = 1;
            dropProbability = 0;
        }

        Side(int n, double dP)
        {
            if (n < 0) n = 1;
            if (dP > 1) dP = 1;
            if (dP < 0) dP = 0;
            number = n;
            dropProbability = dP;
        }
    };
    LinkedList<Side> sides;

public:
    Dice();

    explicit Dice(int);

    void add_side(int, double);

    int get_count_of_sides() const { return countOfSides; }
    double get_full_probability() const { return fullProbability; }
    auto *get_front_side() { return sides.get_front(); }

    friend std::ostream& operator<<(std::ostream&, const Dice&);

    friend std::ostream& operator<<(std::ostream&, const Side&);

    friend bool operator< (const Dice&, const Dice&);

    friend bool operator< (const Side&, const Side&);
};

#endif //LAB1_DICE_H
