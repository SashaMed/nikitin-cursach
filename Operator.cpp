#include "Operator.h"

Operator::Operator()
{
	balance = 0;
	operatorName = "\0";
	number = "\0";
	blockCheak = false;
}

Operator::Operator(string op, string num)
{
	balance = 0;
	operatorName = op;
	number = num;
	blockCheak = false;
}

Operator::Operator(const Operator &obj) : Tarrif(obj)
{
	balance = obj.balance;
	operatorName = obj.operatorName;
	number = obj.number;
	blockCheak = obj.blockCheak;
}


Operator::Operator(const Tarrif& obj) : Tarrif(obj)
{
	balance = 0;
	operatorName = "\0";
	number = "\0";
	blockCheak = false;
}

Operator::Operator(string op, string num, int b)
{
	balance = b;
	operatorName = op;
	number = num;
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

void Operator::setBalance(int b)
{
	balance = b;
}

//void Operator::setOperatorName(string str)
//{
//	operatorName = str;
//}


int Operator::getBalance()
{
	return balance;
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

void Operator::change_balance(int n)
{
	this->balance += n;
}

void Operator::info()
{
	Internet tempI(inetType);
	Connection tempC(connectionType);
	cout << setw(SETWSIZE) << "OPERATOR NAME" << setw(SETWSIZE) << "NUMBER" 
		<< setw(SETWSIZE)<< "BALANCE,$" <<  setw(SETWSIZE) << "TARIFF NAME" << endl;
	cout << setw(SETWSIZE) << operatorName << setw(SETWSIZE) << number 
		<< setw(SETWSIZE) << balance << setw(SETWSIZE) <<  tarrif_name << endl;


	cout << setw(SETWSIZE) << "NAME OF CONNECTION" << setw(SETWSIZE) << "COUNT OF MINUTS" << setw(SETWSIZE)
		<< "COUNT OF SMS" << endl;
	cout << setw(SETWSIZE) << tempC.getName() << setw(SETWSIZE) << tempC.getMinutes() << setw(SETWSIZE)
		<< tempC.getCount_SMS() << endl;

	cout << setw(SETWSIZE) << "NAME OF INTERNET" << setw(SETWSIZE) << "INTERNET SPEED,MB/S" << setw(SETWSIZE)
		<< "INTERNET LIMIT,GB" << endl;
	cout << setw(SETWSIZE) << tempI.getName() << setw(SETWSIZE) << tempI.getSpeed() << setw(SETWSIZE)
		<< tempI.getLimit() << endl;
	 
}



ostream& operator<<(ostream& out, const Operator& op)
{
	//out << setw(10) << op.number << setw(10) << op.block << setw(10) << op.block_date;
	return out;
}