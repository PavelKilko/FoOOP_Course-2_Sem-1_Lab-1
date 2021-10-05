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

template<typename T>
T ArrayList<T>::pop_back()
{
    if (is_empty())
        return 0;
    length--;
    backPos--;
    T res = array[backPos];
    if (length == 0)
    {
        frontPos = 50000;
        backPos = 50001;
    }
    return res;
}

template<typename T>
T ArrayList<T>::pop_front()
{
    if (is_empty())
        return 0;
    length--;
    frontPos++;
    T res = array[frontPos];
    if (is_empty())
    {
        frontPos = 50000;
        backPos = 50001;
    }
    return res;
}

template<typename T>
void ArrayList<T>::print()
{
    for(int i = frontPos + 1; i < backPos; i++)
    {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}

template<typename T>
void ArrayList<T>::insertion_sort(int start, int end)
{
    if (start < 0 || start > length-1 ||
        end < 0 || end > length-1)
        return;
    for (int j = frontPos+1+start; j <= frontPos+1+end; j++)
    {
        int i = j-1;
        T key = array[j];
        while (i >= frontPos+1+start && array[i] > key)
        {
            array[i+1] = array[i];
            i--;
        }
        array[i+1] = key;
    }
}

template<typename T>
void ArrayList<T>::quick_sort(int start, int end)
{
    if (start < 0 || start > length-1 ||
        end < 0 || end > length-1)
        return;
    if(start < end)
    {
        int p;
        T pivot = (array[frontPos+1+start] + array[frontPos+1+end]) / 2;
        int i = start;
        int j = end;
        while(true)
        {
            while(array[frontPos+1+i] < pivot)
                i++;
            while(array[frontPos+1+j] > pivot)
                j--;
            if (i >= j)
            {
                p = j;
                break;
            }
            else
            {
                T addit;
                addit = array[frontPos+1+i];
                array[frontPos+1+i] = array[frontPos+1+j];
                array[frontPos+1+j] = addit;
                i++;
                j--;
            }
        }
        quick_sort(start, p);
        quick_sort(p+1, end);
    }
}

template<typename T>
LinkedList<T>::LinkedList()
{
    length = 0;
    front = nullptr;
    back = nullptr;
}

template<typename T>
void LinkedList<T>::push_back(T n)
{
    ListNode *newListNode;
    newListNode = new class ListNode;
    newListNode->value = n;
    newListNode->next = nullptr;
    length++;
    if (!back)
    {
        newListNode->prev = nullptr;
        front = newListNode;
        back = newListNode;
    }
    else
    {
        newListNode->prev = back;
        back->next = newListNode;
        back = newListNode;
    }
}

template<typename T>
void LinkedList<T>::push_front(T n)
{
    ListNode *newListNode;
    newListNode = new class ListNode;
    newListNode->value = n;
    newListNode->prev = nullptr;
    length++;
    if (!front)
    {
        newListNode->next = nullptr;
        front = newListNode;
        back = newListNode;
    }
    else
    {
        newListNode->next = front;
        front->prev = newListNode;
        front = newListNode;
    }
}
