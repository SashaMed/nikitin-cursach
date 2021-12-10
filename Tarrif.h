#pragma once
#include"Service_class.h"
#include"Internet.h"
#include"Connection.h"



class Tarrif 
{
protected:
	string tarrif_name;
	string conName;
	string inetName;
	Connection connectionType;
	Internet inetType;
	//int balance;
	int cost;
public:
	Tarrif();
	Tarrif(string t_n);
	Tarrif(string t_n,int b, Connection con, Internet inet);
	Tarrif(const Tarrif &obj);
	~Tarrif();

	void setTarrif_Name(string str);
	void setConnection(Connection con);
	void setInternet( Internet inet);

	//int getBalance();
	int getTarrifCost();
	string getTarrif_Name();
	string getInetName();
	string getConName();
	Connection getConnection();
	Internet getInternet();



	friend istream& operator>>(istream& in, Tarrif& t);
	friend ostream& operator<<(ostream& out, const Tarrif& t);
};