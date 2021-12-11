#pragma once
#include "Exception.h"

class Input_exception : public Exception
{
protected:
    int error;
public:
    Input_exception(int e = 0, string message = "") : error(e), Exception(message)
    {
    }

    int get_code();
};

template<typename T>
void input_number_in_diapazone(std::istream& in, T& num, T begin, T end)
{
	bool flag;
	do
	{
		try
		{
			flag = 1;
			in >> num;
		//	while (in.peek() == ' ') in.get();
			if (!in.good() || in.peek() != '\n')
				throw Input_exception(1, "No number was entered");
			if (num < begin || num > end)
				throw Input_exception(4, "The entered number doesn't belong to the specified range ");
		}
		catch (Input_exception& exception)
		{
			flag = 0;
			cout << "Code:" << exception.get_code() << " Exception:" << exception.what() << endl;
			in.clear();
			rewind(stdin);
		}
	} while (!flag);
}

void input_phone_number(std::istream& in, string& str);
void input_letters_and_numbers(std::istream& in, string& str);
void input_letters(istream& in, string& str);
void terminate();