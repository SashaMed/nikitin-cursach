#include"Service_class.h"


Service_class::Service_class()
{
	this->cost = 0;
	this->name = "\0";
}

Service_class::Service_class(unsigned int n, string str) 
{
	this->name = name;
	this->cost = n;
}

Service_class::Service_class(const Service_class &obj) 
{
	this->name = obj.name;
	this->cost = obj.cost;
}


void Service_class::setCost(unsigned int n) 
{
	this->cost = n;
}

unsigned int Service_class::getCost() 
{
	return this->cost;
}

istream& operator>>(istream& in, Service_class& c) 
{
	cout << "Name: ";
	in >> c.name;
	cout << "Cost: ";
	in >> c.cost;
	return in;
}

ostream& operator<<(ostream& out, const Service_class& c) 
{
	out << setw(SETWSIZE) << c.name << setw(SETWSIZE) << c.cost;
	return out;
}


void Service_class::setName(string str)
{
	this->name = str;
}

string Service_class::getName()
{
	return this->name;
}

