#include "Algorithm.h"

template<typename T>
List<T>& Algorithm<T>::find(Iterator<T> begin, Iterator<T> end, T& buf)
{
	List<T>* objList = new List<T>;
	for (begin; begin != end; ++begin)
	{
		if (*begin == buf)
			(*objList).push_back(*begin);
	}
	return *objList;
}

template<typename T>
void Algorithm<T>::sort(int choise, Iterator<T> begin, Iterator<T> end)
{
	T e = *begin;
	int sort_choise = e.sort_selection();
	for (; begin != end; ++begin)
	{
		Iterator<T> u = begin;
		for (Iterator<T> i = ++u; i != end; ++i)
		{
			T sr;
			sr = sr.help_sort(*i, sort_choise);
			if (choise == 1)
				if (*begin > sr)
				{
					T buf = *begin;
					*begin = *i;
					*i = buf;
				}
			if (choise == 2)
				if (*begin < sr)
				{
					T buf = *begin;
					*begin = *i;
					*i = buf;
				}
		}
	}
}

template<typename T>
void Algorithm<T>::print(Iterator<T> begin, Iterator<T> end)
{
		cout << "-------------------------------------" << endl;
		for (; begin != end; ++begin)
		{
			cout << *begin << endl;
		}
		cout << "-------------------------------------" << endl;
}
