#pragma once
#include <iostream>
#include "Iterator.cpp"
#include "Node.h"
using namespace std;

template<typename T>
class List
{
private:
    int size;
    Node<T>* head;
    Node<T>* tail;
public:
    friend class Iterator<T>;
    List();
    ~List();
    void push_back(T data);
    void push_front(T data);
    void output();
    void clear();
    void pop_front();
    void pop_back();
    T& operator[](int number);
    int get_size();
    Iterator<T> begin();
    Iterator<T> end();
};

