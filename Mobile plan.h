#pragma once
#include"Tarrif.h"
#include"Internet.h"
#include"Connection.h"



class Mobile_plan 
{
protected:
	float balance;
	float cost;
	bool Internet_connection;
public:
	Mobile_plan();
	Mobile_plan(float b, float c, bool I, string num, bool bl, string bl_d);
	~Mobile_plan();
	void Replenishment(); //пополнение баланса
	friend istream& operator>>(istream& in, Mobile_plan& mb);
	friend ostream& operator<<(ostream& out, const Mobile_plan& mb);
	void set_Internet_connection(bool I_conn);
};
