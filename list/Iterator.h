#pragma once
#include "Node.h"

template <class T>
class List;

template <typename T>
class Iterator
{
public:
	Node<T>* current;
	Iterator() : current(nullptr)
	{}

	Iterator(Node<T>* cur) 
	{
		current = cur;
	}
	Iterator<T> operator++();
	Iterator<T> operator--();

	Iterator<T> operator+(int n);
	Iterator<T> operator-(int n);

	Iterator<T> operator+=(int n);

	bool operator==(Iterator& iter);
	bool operator!=(Iterator& iter);

	T& operator *();
};
