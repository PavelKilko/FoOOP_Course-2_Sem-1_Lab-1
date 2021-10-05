//
// Created by Pavel Kilko on 10/5/2021.
//

#ifndef LAB1_LINKEDLIST_H
#define LAB1_LINKEDLIST_H

template <class T>
class ArrayList
{
private:
    int length;
    int frontPos;
    int backPos;
    T array[100000];

public:
    ArrayList();

    void push_back(T);

    void push_front(T);

    bool is_empty();

    void clear();
};

#endif //LAB1_LINKEDLIST_H
