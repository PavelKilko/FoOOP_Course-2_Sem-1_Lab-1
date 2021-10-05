//
// Created by Pavel Kilko on 10/5/2021.
//

#ifndef LAB1_LIST_H
#define LAB1_LIST_H

#include <iostream>

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

    T pop_back();

    T pop_front();

    void print();

    int get_length(){ return length; }

    void insertion_sort(int, int);

    void quick_sort(int, int);
};

template <class T>
class LinkedList
{
private:
    class ListNode {
    public:
        T value;
        ListNode *next = nullptr;
        ListNode *prev = nullptr;
    } *front, *back;

    int length;

    ListNode *merge(ListNode *first, ListNode *second);

    ListNode *split(ListNode *front);

    ListNode *merge_sort(ListNode *front);

public:
    LinkedList();

    void push_back(T);

    void push_front(T);

    bool is_empty();

    T pop_back();

    T pop_front();

    void clear();

    int get_length(){ return length; }

    ListNode * get_front() const { return front; }

    void merge_sort();
};

#endif //LAB1_LIST_H
