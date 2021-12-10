#include "Tarrif.h"

Tarrif::Tarrif()
{
	tarrif_name = "\0";
	conName = "\0";
	inetName = "\0";
	//balance = 0;
	cost = 0;
}


Tarrif::Tarrif(string t_n)
{
	tarrif_name = t_n;
	//balance = 0;
	cost = 0;
	conName = "\0";
	inetName = "\0";
}

Tarrif::Tarrif(string t_n, int b, Connection con, Internet inet)
{
	tarrif_name = t_n;
	conName = con.getName();
	inetName = inet.getName();
	connectionType = con;
	inetType = inet;
	//balance = b;
	cost = con.getCost() + inet.getCost();
}

Tarrif::Tarrif(const Tarrif &obj)
{
	tarrif_name = obj.tarrif_name;
	connectionType = obj.connectionType;
	inetType = obj.inetType;
	//balance = obj.balance;
	cost = obj.cost;
}

Tarrif::~Tarrif() {}


void Tarrif::setTarrif_Name(string str)
{
	this->tarrif_name = str;
}

void Tarrif::setConnection( Connection con)
{
	this->connectionType = con;
	this->cost = con.getCost() + this->inetType.getCost();
	this->conName = con.getName();
}

void Tarrif::setInternet( Internet inet)
{
	this->inetType = inet;
	this->inetName = inet.getName();
	this->cost = inet.getCost() + this->connectionType.getCost();
}






//int Tarrif::getBalance()
//{
//	return balance;
//}

int Tarrif::getTarrifCost() 
{
	return cost;
}

string Tarrif::getTarrif_Name()
{
	return tarrif_name;
}

string Tarrif::getInetName()
{
	return inetName;
}

string Tarrif::getConName()
{
	return conName;
}

Connection Tarrif::getConnection()
{
	return connectionType;
}

Internet Tarrif::getInternet()
{
	return inetType;
}




istream& operator >> (istream& in, Tarrif& t)
{
	cout << "Tarrif name: ";
	in >> t.tarrif_name;
	return in;
}

ostream& operator<<(ostream& out, const Tarrif& t)
{
	Connection c;
	Internet i;
	out << setw(SETWSIZE) << "TARIFF NAME" << setw(SETWSIZE) << "CONNECTION COST,$" << setw(SETWSIZE)  << endl;
	out << setw(SETWSIZE) << t.tarrif_name << setw(SETWSIZE) << t.cost << setw(SETWSIZE)  << endl;
	//i.print_shapka();
	cout << setw(SETWSIZE) << "NAME OF CONNECTION" << setw(SETWSIZE) << "COUNT OF MINUTS" << setw(SETWSIZE) 
		<< "COUNT OF SMS" << endl;
	//out << t.inetType << endl;
	Connection tempC(t.connectionType);
	cout << setw(SETWSIZE) << tempC.getName() << setw(SETWSIZE) << tempC.getMinutes() << setw(SETWSIZE)
		<< tempC.getCount_SMS() << endl;
	//c.print_shapka();
	//out << t.connectionType << endl;
	Internet tempI(t.inetType);
	cout << setw(SETWSIZE) << "NAME OF INTERNET" << setw(SETWSIZE) << "INTERNET SPEED,MB/S" << setw(SETWSIZE) 
		<< "INTERNET LIMIT,GB" << endl;
	cout << setw(SETWSIZE) << tempI.getName() << setw(SETWSIZE) << tempI.getSpeed() << setw(SETWSIZE)
		<< tempI.getLimit() << endl;


	return out;
}