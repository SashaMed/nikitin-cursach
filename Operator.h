#pragma once

#include"Tarrif.h"


class Operator : public Tarrif
{
protected:
	string operatorName;
	string number;
	bool blockCheak;
	int balance;
public:
	Operator();
	Operator(string oP, string num);
	Operator(string oP, string num, int b);
	Operator(const Operator& obj);
	Operator(const Tarrif& obj);
	~Operator();
	
	void setBlockCheak(bool b);
	void setOperatorName(string str);
	void setNumber(string str);
	void setTariff( Tarrif obj);
	void setBalance(int b);

	string getOperatorName();
	string getNumber();
	bool getBlockCheak();
	int getBalance();

	void change_balance(int n);

	void info();

	friend istream& operator>>(istream& in, Operator& op);
	friend ostream& operator<<(ostream& out, const Operator& op);
};
