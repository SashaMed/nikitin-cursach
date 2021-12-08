#pragma once

#include"Tarrif.h"


class Operator : public Tarrif
{
protected:
	string operatorName;
	string number;
	bool blockCheak;
public:
	Operator();
	Operator(string oP, string num);
	Operator(const Operator& obj);
	Operator(const Tarrif& obj);
	~Operator();
	
	void setBlockCheak(bool b);
	void setOperatorName(string str);
	void setNumber(string str);
	void setTariff( Tarrif obj);

	string getOperatorName();
	string getNumber();
	bool getBlockCheak();

	void info();

	friend istream& operator>>(istream& in, Operator& op);
	friend ostream& operator<<(ostream& out, const Operator& op);
};
