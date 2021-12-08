#pragma once
#include <iostream>
using namespace std;

template<typename T>
struct Node
{
    Node* next;
    Node* prev;
    T data;
};

template<typename T>
class List
{
private:
    int size;
    Node<T>* head;

public:
    List();
    ~List();
    void push_back(T data);
    void push_front(T data);
    void output();
    void clear();
    void pop_front();
    void pop_back();
    bool find();
    T& operator[](int number);
    int get_size();
};
