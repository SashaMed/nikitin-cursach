#include "List.h"

template<typename T>
List<T>::List()
{
	size = 0;
	head = nullptr;
	cout << "Construct List" << endl;
}

template<typename T>
List<T>::~List()
{
	this->clear();
	delete[] head;
	cout << "Destructor List" << endl;
}

template<typename T>
void List<T>::push_back(T data)
{
	Node<T>* nd = new Node<T>;
	nd->data = data;
	nd->next = nullptr;
	if (!head)
	{
		nd->prev = nullptr;
		head = nd;
	}
	else
	{
		Node<T>* current = head;
		while (current->next)
			current = current->next;
		current->next = nd;
		nd->prev = current;
	}
	size++;
}

template<typename T>
void List<T>::push_front(T data)
{
	Node<T>* nd = new Node<T>;
	nd->data = data;
	nd->prev = nullptr;
	if (!head)
	{
		nd->next = nullptr;
		head = nd;
	}
	else
	{
		head->prev = nd;
		nd->next = head;
		head = nd;
	}
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
	while (head)
		pop_front();
}

template<typename T>
void List<T>::pop_front()
{
	if (!head)
		cout << "The list is empty, add node" << endl;
	else if (!head->next)
	{
		head = nullptr;
		size--;
	}
	else
	{
		Node<T>* temp = head;
		head = head->next;
		head->prev = nullptr;
		delete temp;
		size--;
	}
}

template<typename T>
void List<T>::pop_back()
{
	if (!head)
		cout << "The list is empty, add node" << endl;
	else if (!head->next)
	{
		head = nullptr;
		size--;
	}
	else
	{
		Node<T>* temp = head;
		while (temp->next)
			temp = temp->next;
		temp->prev->next = nullptr;
		temp->prev = nullptr;
		delete temp;
		size--;
	}
}

template<typename T>
bool List<T>::find()
{
	cout << "Input data";
	T data;
	cin >> data;
	bool flag = false;
	if (!head)
	{
		return flag;
	}
	else
	{
		Node<T>* current = head;
		while (current)
		{
			if (current->data == data)
			{
				flag = true;
				return flag;
			}
			current = current->next;
		}
		return flag;
	}
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