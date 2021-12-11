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


	friend ostream& operator << (fstream& out, const Operator obj)
	{
		out << setw(SETWSIZE);
		out << obj.operatorName;
		out << setw(SETWSIZE);
		out << obj.number;
		out << setw(SETWSIZE);
		out << obj.tarrif_name;
		out << " ";
		out << obj.blockCheak;
		out << " ";
		out << obj.balance;
		out << endl;
		return out;
	}

	friend ifstream& operator >> (ifstream& in, Operator& obj)
	{
		Func_Class func; char c;
		char* buf = new char[SETWSIZE + 1];		
		in.getline(buf, SETWSIZE + 1);
		in.clear();
		obj.operatorName = func.sdvig(buf);		
		in.getline(buf, SETWSIZE + 1);
		in.clear();
		obj.number = func.sdvig(buf);		
		in.getline(buf, SETWSIZE + 1);
		in.clear();
		obj.tarrif_name = func.sdvig(buf);
		in.get();
		in >> obj.blockCheak;
		in.get();
		in >> obj.balance;
		in.get();
		return in;
	}


};
