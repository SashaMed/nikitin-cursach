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
	//in >> c.minutes;
	input_number_in_diapazone<unsigned int>(in, c.minutes, 0, 1000000);
	cout << "Count SMS: ";
	//in >> c.count_SMS;
	input_number_in_diapazone<unsigned int>(in, c.count_SMS, 0, 1000000);
	return in;
}

void Connection::print_shapka() {
	cout << setw(SETWSIZE) << "NAME OF CONNECTION" << setw(SETWSIZE) << "CONNECTION COST" 
		<< setw(SETWSIZE) << "COUNT OF MINUTS" << setw(SETWSIZE) << "COUNT OF SMS" << endl;
}

ostream& operator<<(ostream& out, const Connection& c)
{
	out << dynamic_cast<const Service_class&>(c);
	out << setw(SETWSIZE) << c.minutes << setw(SETWSIZE) << c.count_SMS;
	return out;
}

ostream& operator<<(fstream& out, const Connection obj)
{
	out << setw(SETWSIZE);
	out << obj.name;
	out << " ";
	out << obj.cost;
	out << " ";
	out << obj.minutes;
	out << " ";
	out << obj.count_SMS;
	out << endl;
	return out;
}

ifstream& operator>>(ifstream& in, Connection& obj)
{
	Func_Class func;
	char* buf = new char[SETWSIZE+1];
	in.getline(buf, SETWSIZE+1);
	in.clear();
	obj.name = func.sdvig(buf); 	in.get();
	in >> obj.cost;	in.get();
	in >> obj.minutes;	in.get();
	in >> obj.count_SMS; in.get(); //in.get();
	return in;
}
