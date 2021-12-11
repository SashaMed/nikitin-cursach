#include "Internet.h"


Internet::Internet()
{
	speed = 0;
	limit = 0;
}

Internet::Internet(float s, int l, int c, string n) : Service_class(c,n)
{
	speed = s;
	limit = l;
}

Internet::Internet(const Internet &obj) : Service_class(obj)
{
	speed = obj.speed;
	limit = obj.limit;
}

Internet::~Internet() {}

void Internet::setSpeed(float s)
{
	this->speed = s;
}

void Internet::setLimit(int i) 
{
	this->limit = i;
}

float Internet::getSpeed()
{
	return this->speed;
}

int Internet::getLimit()
{
	return this->limit;
}

void Internet::print_shapka()
{
	cout << setw(SETWSIZE) << "NAME OF INTERNET"<< setw(SETWSIZE) << "CONNECTION COST"
		<< setw(SETWSIZE) <<"INTERNET SPEED,MB/S" << setw(SETWSIZE) << "INTERNET LIMIT,GB" << endl;
}


istream& operator >> (istream& in, Internet& I)
{
	in >> dynamic_cast<Service_class&>(I);
	cout << "Speed: ";
	//in >> I.speed;
	input_number_in_diapazone<float>(in, I.speed, 0, 1000000);
	cout << "Limit: ";
	input_number_in_diapazone<int>(in, I.limit, 0, 1000000);
	//in >> I.limit;
	return in;
}

ostream& operator << (ostream& out, const Internet& I)
{
	out << dynamic_cast<const Service_class&>(I);
	out << setw(SETWSIZE) << I.speed << setw(SETWSIZE) << I.limit;
	return out;
}


ostream& operator<<(fstream& out, const Internet obj)
{
	out << setw(SETWSIZE);
	out << obj.name;
	out << " ";
	out << obj.cost;
	out << " ";
	out << obj.speed;
	out << " ";
	out << obj.limit;
	out << endl;
	return out;
}

ifstream& operator>>(ifstream& in, Internet& obj)
{
	Func_Class func;
	char* buf = new char[SETWSIZE]; 
	in.getline(buf, SETWSIZE);
	in.clear();
	obj.name = func.sdvig(buf); 	in.get();
	in >> obj.cost;	in.get();
	in >> obj.speed;	in.get();
	in >> obj.limit; in.get(); in.get();
	return in;
}