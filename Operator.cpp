#include "Operator.h"

Operator::Operator()
{
	operatorName = "\0";
	number = "\0";
	blockCheak = false;
}

Operator::Operator(string oP, string num)
{
	operatorName = "\0";
	number = "\0";
	blockCheak = false;
}

Operator::Operator(const Operator &obj) : Tarrif(obj)
{
	operatorName = obj.operatorName;
	number = obj.number;
	blockCheak = obj.blockCheak;
}


Operator::Operator(const Tarrif& obj) : Tarrif(obj)
{
	operatorName = "\0";
	number = "\0";
	blockCheak = false;
}

Operator::~Operator() { }

void Operator::setBlockCheak(bool b)
{
	blockCheak = b;
}

void Operator::setOperatorName(string str)
{
	operatorName = str;
}

void Operator::setNumber(string str)
{
	number = str;
}


void Operator::setTariff( Tarrif obj)
{
	//this->balance -= obj.getTarrifCost();
	this->setTarrif_Name(obj.getTarrif_Name());
	this->setInternet(obj.getInternet());
	this->setConnection(obj.getConnection());
}


string Operator::getOperatorName()
{
	return operatorName;
}

string Operator::getNumber()
{
	return number;
}

bool Operator::getBlockCheak()
{
	return blockCheak;
}


void Operator::info()
{
	cout << setw(SETWSIZE) << "OPERATOR NAME" << setw(SETWSIZE) << "NUMBER" << endl;
	cout << setw(SETWSIZE) << operatorName << setw(SETWSIZE) << number << endl;
	Tarrif temp(getTarrif_Name(), getBalance(), getConnection(),getInternet());
	cout << temp << endl;
	//cout << 
}



ostream& operator<<(ostream& out, const Operator& op)
{
	//out << setw(10) << op.number << setw(10) << op.block << setw(10) << op.block_date;
	return out;
}