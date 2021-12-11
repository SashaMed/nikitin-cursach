#pragma once
#include"Operator.h"
#include <iostream>
#include <string.h>
#include <iomanip>
using namespace std;


class Client
{
protected:
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
	void print_shapka();

	void operator=(const Client& obj);

	bool registration(vector<Tarrif*> tariffVec, vector<Operator*> operVec);
	void menu( vector<Operator*> operVec, vector<Tarrif*> tariffVec, vector<Internet> inetVec, vector<Connection> conVec);
	virtual void menu(vector<Client*> clientVec, vector<Operator*> operVec, vector<Tarrif*> *tariffVec, vector<Internet>* inetVec, vector<Connection> *conVec) {};
	virtual int class_cheak();

	~Client();
	friend istream& operator>>(istream& in, Client& c);
	friend ostream& operator<<(ostream& out, const Client& c);


	friend ostream& operator << (fstream& out, const Client obj)
	{
		out << setw(SETWSIZE);
		out << obj.surname;
		out << setw(SETWSIZE);
		out << obj.name;
		out << setw(SETWSIZE);
		out << obj.number;
		out << setw(SETWSIZE);
		out << obj.pass;
		out << endl;
		return out;
	}


	friend ifstream& operator >> (ifstream& in, Client& obj)
	{
		Func_Class func; char c;
		char* buf = new char[SETWSIZE +1];
		in.getline(buf, SETWSIZE +1);
		in.clear();
		obj.surname = func.sdvig(buf);
		in.getline(buf, SETWSIZE +1);
		in.clear();
		obj.name = func.sdvig(buf);
		in.getline(buf, SETWSIZE +1);
		in.clear();
		obj.number = func.sdvig(buf);
		in.getline(buf, SETWSIZE +1);
		in.clear();
		obj.pass = func.sdvig(buf);
		//in.get();
		return in;
	}
};