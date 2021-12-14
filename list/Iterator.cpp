#include "Iterator.h"

template<typename T>
Iterator<T> Iterator<T>::operator++()
{
	if (current == nullptr) return *this;
	current = current->next;
	return *this;
}

template<typename T>
Iterator<T> Iterator<T>::operator--()
{
	if (current->prev == nullptr) return *this;
	current = current->prev;
	return *this;
}

template<typename T>
Iterator<T> Iterator<T>::operator+(int n)
{
	if (current == nullptr) return *this;
	for (int i = 0; i < n; i++)
		current = current->next;
	return *this;
}

template<typename T>
Iterator<T> Iterator<T>::operator-(int n)
{
	if (current->prev == nullptr) return *this;
	for (int i = 0; i < n; i++)
		current = current->prev;
	return *this;
}

template<typename T>
Iterator<T> Iterator<T>::operator+=(int n)
{
	if (current == nullptr) return *this;
	for (int i = 0; i < n; i++)
		current = current->next;
	return *this;
}

template<typename T>
bool Iterator<T>::operator==(Iterator& iter)
{
	if (current == nullptr && iter.current == nullptr)
		return true;
	if (current == nullptr || iter.current == nullptr)
		return false;
	if (current->data == iter.current->data && current->next == iter.current->next && current->prev == iter.current->prev)
		return true;
	return false;
}

template<typename T>
bool Iterator<T>::operator!=(Iterator& iter)
{
	if (current == nullptr && iter.current == nullptr)
		return false;
	if ((current == nullptr && iter.current != nullptr) || (current != nullptr && iter.current == nullptr))
		return true;
	if (current->data == iter.current->data && current->next == iter.current->next && current->prev == iter.current->prev)
		return false;
	return true;
}

template<typename T>
T& Iterator<T>::operator *()
{
	return current->data;
}