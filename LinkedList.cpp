//
// Created by Pavel Kilko on 10/5/2021.
//

#include "LinkedList.h"

template<typename T>
ArrayList<T>::ArrayList() {
    length = 0;
    frontPos = 50000;
    backPos = 50001;
}

template<typename T>
void ArrayList<T>::push_back(T n)
{
    if (length == 100000 || backPos == 99999)
        return;
    array[backPos] = n;
    length++;
    backPos++;
}

template<typename T>
void ArrayList<T>::push_front(T n)
{
    if (length == 100000 || backPos == 99999)
        return;
    array[frontPos] = n;
    length++;
    frontPos--;
}

template<typename T>
bool ArrayList<T>::is_empty()
{
    if (length == 0)
        return true;
    else
        return false;
}

template<typename T>
void ArrayList<T>::clear()
{
    length = 0;
    frontPos = 50000;
    backPos = 50001;
}