#include "Connection.h"

Connection::Connection()
{
	minutes = 0;
	count_SMS = 0;
}

Connection::Connection(unsigned int m, unsigned int s, unsigned int c, string name) : Service_class(c, name)
{
	minutes = m;
	count_SMS = s;
}

Connection::Connection(const Connection &obj) : Service_class(obj)
{
	minutes = obj.minutes;
	count_SMS = obj.count_SMS;
}

Connection::~Connection() {}

void Connection::setMinutes(unsigned int m)
{
	this->minutes = m;
}

void Connection::setCount_SMS(unsigned int c)
{
	this->count_SMS = c;
}

unsigned int Connection::getMinutes() 
{
	return this->minutes;
}

unsigned int Connection::getCount_SMS()
{
	return this->count_SMS;
}


istream& operator>>(istream& in, Connection& c)
{
	in >> dynamic_cast<Service_class&>(c);
	cout << "Minutes: ";
	in >> c.minutes;
	cout << "Count SMS: ";
	in >> c.count_SMS;
	return in;
}

void Connection::print_shapka() {
	cout << setw(SETWSIZE) << "NAME OF SERVICE" << setw(SETWSIZE) << "COST OF SERVICE" 
		<< setw(SETWSIZE) << "COUNT OF MINUTS" << setw(SETWSIZE) << "COUNT OF SMS" << endl;
}

ostream& operator<<(ostream& out, const Connection& c)
{
	out << dynamic_cast<const Service_class&>(c);
	out << setw(SETWSIZE) << c.minutes << setw(SETWSIZE) << c.count_SMS;
	return out;
}