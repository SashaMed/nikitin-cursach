#include "Client.h"

Client::Client()
{
	surname = "\0";
	name = "\0";
	number = "\0";
	pass = "\0";
}

Client::Client(string s, string n, string num)
{
	number = num;
	surname = s;
	name = n;
	pass = "\0";
}

Client::Client(string s, string n, string num, Operator op)
{
	number = num;
	surname = s;
	name = n;
	oper = op;
	pass = "\0";
}

Client::Client(const Client &obj)
{
	surname = obj.surname;
	name = obj.name;
	number = obj.number;
	oper = obj.oper;
	pass = obj.pass;
}


void Client::setSurname(string str)
{
	surname = str;
}

void Client::setName(string str)
{
	name = str;
}

void Client::setNumber(string str)
{
	number = str;
}

void Client::setOperator(Operator op)
{
	oper = op;
}

void Client::setPass(string str)
{
	pass = str;
}

string Client::getPass()
{
	return pass;
}

string Client::getSurname()
{
	return surname;
}

Client::~Client() { }

string Client::getName()
{
	return name;
}

string Client::getNumber()
{
	return number;
}

Operator& Client::getOperator()
{
	return oper;
}

void Client::client_info()
{

}


void Client::menu(vector<Operator*> operVec, vector<Tarrif*> tariffVec, Internet inetArr[], Connection conArr[])
{
	int temp;
	cout << "Logged into account: \n";
	cout << *this<< endl;
	char switch_on;
	while (1) {
		system("cls");
		cout << "Choose operation: \n\n";
		cout << "1. See balance.\n2. Change tariff.\n3. Connect internet.\n4. Temporary block of number.\n";
		cout << "5. Top up balance.\n6. Change internet.\n7. Change connection.\n8. See info.\n9. Exit.\n";
		cin >> switch_on;
		cin.get();
		cin.clear();
		fflush(stdin);
		switch (switch_on)
		{
		case '1':
			cout << "BALANCE: " << oper.getBalance()<< "$" << endl;
			cin.get();
			
			break;
		case '2':

			cout << "CHOOSE TARIFF: \n" << endl;
			for (int i = 0; i < tariffVec.size(); i++)
			{
				cout << i + 1 << ")\n";
				cout << *tariffVec[i] << endl;
			}
			cin >> temp;
			if (temp > tariffVec.size()) break;
			this->getOperator().setTariff(*tariffVec[temp-1]);
			break;

		case '8':
			this->getOperator().info();
			cout << endl;
			cin.get();
			break;
		case '9':
			return;
			break;
		default:
			break;
		}
	}
}

istream& operator>>(istream& in, Client& c)
{
	cout << "Surname: ";
	in >> c.surname;
	cout << "Name: ";
	in >> c.name;
	cout << "Middle name: ";
	return in;
}

ostream& operator<<(ostream& out, const Client& c)
{
	out << setw(SETWSIZE) << "SURNAME" << setw(SETWSIZE) << "NAME" << setw(SETWSIZE) <<"NUMBER"<<endl;
	out << setw(SETWSIZE) << c.surname << setw(SETWSIZE) << c.name << setw(SETWSIZE) << c.number;
	return out;
}


