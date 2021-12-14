#pragma once
#include"List.cpp"


template <typename T>
class Algorithm
{
public:
	List<T>& find(Iterator<T> begin, Iterator<T> end, T& buff);
	void sort(int shoise, Iterator<T> begin, Iterator<T> end);
	void print(Iterator<T> begin, Iterator<T> end);
};
