#include "Mobile plan.h"

Mobile_plan::Mobile_plan()
{
	balance = 0;
	cost = 0;
	Internet_connection = false;
}

Mobile_plan::Mobile_plan(float b, float c, bool I, string num, bool bl, string bl_d) 
{
	balance = b;
	cost = c;
	Internet_connection = I;
}

Mobile_plan::~Mobile_plan()
{

}

void Mobile_plan::Replenishment()
{
	cout << "How much money do you want to put on the balance?" << endl;
	float money;
	cin >> money;
	if (money < 0)
		cout << "Uncorrect input" << endl;
	else
		balance += money;
}

istream& operator >> (istream& in, Mobile_plan& mb)
{
	
	cout << "Balance: ";
	in >> mb.balance;
	cout << "Cost: ";
	in >> mb.cost;
	cout << "Internet: ";
	in >> mb.Internet_connection;
	return in;
}

ostream& operator << (ostream& out, const Mobile_plan& mb)
{
	
	out << setw(10) << mb.balance << setw(10) << mb.cost << setw(10) << mb.Internet_connection;
	return out;
}

void Mobile_plan::set_Internet_connection(bool I_conn)
{
	Internet_connection = I_conn;
}