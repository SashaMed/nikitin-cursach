#include "List.h"

template<typename T>
List<T>::List()
{
	size = 0;
	head = nullptr;
	tail = nullptr;
}

template<typename T>
List<T>::~List()
{
	this->clear();
}

template<typename T>
void List<T>::push_back(T data)
{
	Node<T>* node = new Node<T>;
	node->data = data;
	node->next = nullptr;
	node->prev = tail;
	if (tail)
		tail->next = node;
	tail = node;
	if (head == nullptr)
		head = node;
	size++;
}

template<typename T>
void List<T>::push_front(T data)
{
	Node<T>* node = new Node<T>;
	node->data = data;
	node->next = head;
	node->prev = nullptr;
	if (head)
		head->prev = node;
	head = node;
	if (tail == nullptr)
		tail = node;
	size++;
}

template<typename T>
void List<T>::output()
{
	if (!head)
	{
		cout << "The list is empty, add node" << endl;
	}
	else
	{
		int buf_size = 0;
		Node<T>* current = head;
		cout << "-------------------------------------" << endl;
		while (buf_size < size)
		{
			cout << current->data << endl;
			current = current->next;
			buf_size++;
		}
		cout << "-------------------------------------" << endl;
	}
}

template<typename T>
void List<T>::clear()
{
	while (size)
		pop_front();
}

template<typename T>
void List<T>::pop_front()
{
	if (!head)
	{
		cout << "The list is empty, add node" << endl;
		return;
	}
	Node<T>* node = head;
	head = head->next;
	if (head)
		head->prev = nullptr;
	delete node;
	size--;
}

template<typename T>
void List<T>::pop_back()
{
	if (!head)
	{
		cout << "The list is empty, add node" << endl;
		return;
	}
	Node<T>* node = tail;
	tail = tail->prev;
	if (tail)
		tail->next = nullptr;
	delete node;
	size--;
}

template<typename T>
T& List<T>::operator[](int number)
{
	Node<T>* curr = head;
	if (number < 0 || number >= size) return curr->data;
	for (int i = 0; i < number; i++)
		curr = curr->next;
	return curr->data;
}

template<typename T>
int List<T>::get_size()
{
	return size;
}

template<typename T>
Iterator<T> List<T>::begin()
{
	Iterator<T> it;
	if (!head) return it;
	it.current = head;
	return it;
}

template<typename T>
Iterator<T> List<T>::end()
{
	Iterator<T> it;
	it.current = tail->next;
	return it;
}