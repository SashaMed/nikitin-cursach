#include "Input_exception.h"

int Input_exception::get_code()
{
	return this->error;
}

void input_letters(istream& in, string& str)
{
	bool flag;
	do
	{
		try
		{
			flag = 1;
			rewind(stdin);
			getline(in, str);
			for (int i = 0; i < str.length(); i++)
				if ((str[i] < 'A' || str[i]>'z') && str[i] != ' ' && str[i] != '-')
					throw Input_exception(1, "The string must contain only letters and a hyphen!");
		}
		catch (Input_exception& exception)
		{
			flag = 0;
			cout << "Code:" << exception.get_code() << " Exception:" << exception.what() << endl;
			str.clear();
		}
	} while (!flag);
}

void input_letters_and_numbers(std::istream& in, string& str)
{
	bool flag;
	do
	{
		try
		{
			flag = 1;
			rewind(stdin);
			getline(in, str);
			for (int i = 0; i < str.length(); ++i)
				if ((str[i] < 'A' || str[i]>'z') && (str[i] < '0' || str[i]>'9') && str[i] != ' ' && str[i] != '-')
					throw Input_exception(2, "The string must contain only letters, numbers and a hyphen!");
		}
		catch (Input_exception& exception)
		{
			flag = 0;
			cout << "Code:" << exception.get_code() << " Exception:" << exception.what() << endl;
			str.clear();
		}
	} while (!flag);
}


void input_phone_number(std::istream& in, string& str)
{
	bool flag;
	do
	{
		try
		{
			flag = 1;
			rewind(stdin);
			getline(in, str);
			for (int i = 0; i < str.length(); ++i)
				if ((str[i] < '0' || str[i]>'9') && str[i] != ' ' && str[i] != '-' && str[i] != '+')
					throw Input_exception(2, "The string must contain only phone number!");
		}
		catch (Input_exception& exception)
		{
			flag = 0;
			cout << "Code:" << exception.get_code() << " Exception:" << exception.what() << endl;
			str.clear();
		}
	} while (!flag);
}

void terminate()
{
	cout << "It's a terminate!" << endl;
	abort();
}