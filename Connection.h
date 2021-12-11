#pragma once
#include"Service_class.h"


class Connection : public Service_class
{
protected:
	unsigned int minutes;
	unsigned int count_SMS;
public:
	Connection();
	Connection(unsigned int m, unsigned int s, unsigned int c, string name);
	Connection(const Connection &obj);
	~Connection();

	void setMinutes(unsigned int m);
	void setCount_SMS(unsigned int c);

	unsigned int getMinutes();
	unsigned int getCount_SMS();
	void print_shapka();


	friend istream& operator>>(istream& in, Connection& c);
	friend ostream& operator<<(ostream& out, const Connection& c);

	friend ostream& operator << (fstream& out, const Connection obj);
	friend ifstream& operator >> (ifstream& in, Connection& obj);
};