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

	int getTarrifCost();
	string getTarrif_Name();
	string getInetName();
	string getConName();
	Connection getConnection();
	Internet getInternet();



	friend istream& operator>>(istream& in, Tarrif& t);
	friend ostream& operator<<(ostream& out, const Tarrif& t);

	friend ostream& operator << (fstream& out, const Tarrif obj)
	{
		out << setw(SETWSIZE);
		out << obj.tarrif_name;
		out << setw(SETWSIZE);
		out << obj.inetName;
		out << setw(SETWSIZE);
		out << obj.conName;
		out << endl;
		return out;
	}

	friend ifstream& operator >> (ifstream& in, Tarrif& obj)
	{
		Func_Class func; char c;
		char* buf = new char[SETWSIZE+1];		//in.get();
		in.getline(buf, SETWSIZE+1);
		in.clear();
		obj.tarrif_name = func.sdvig(buf);		//in.get();
		in.getline(buf, SETWSIZE+1);
		in.clear();
		obj.inetName = func.sdvig(buf);		//in.get();
		in.getline(buf, SETWSIZE+1);
		in.clear();
		obj.conName = func.sdvig(buf);		//in.get();
		//c = in.get();
		return in;
	}
};