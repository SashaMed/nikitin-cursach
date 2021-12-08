#pragma once
#include"Operator.h"
#include <iostream>
#include <string.h>
#include <iomanip>
using namespace std;


class Client
{
private:
	string surname;
	string name;
	string number;
	string pass;
	Operator oper;
public:
	Client();
	Client(string s, string n, string num);
	Client(string surn, string name, string num, Operator op);
	Client(const Client& obj);


	void setSurname(string str);
	void setName(string str);
	void setNumber(string str);
	void setOperator(Operator op);
	void setPass(string str);
	void client_info();

	string getPass();
	string getSurname();
	string getName();
	string getNumber();
	Operator& getOperator();

	void menu(vector<Operator*> operVec, vector<Tarrif*> tariffVec, Internet inetArr[],Connection conArr[]);

	~Client();
	friend istream& operator>>(istream& in, Client& c);
	friend ostream& operator<<(ostream& out, const Client& c);
};