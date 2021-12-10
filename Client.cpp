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

int Client::class_cheak()
{
	return 0;
}


void Client::menu( vector<Operator*> operVec, vector<Tarrif*> tariffVec, vector<Internet> inetVec, vector<Connection> conVec)
{
	int temp = 0;
	int fl = 0;
	string inputTemp;
	char switch_on;
	Operator* operTemp = &this->getOperator();


	while (1)
	{
		system("cls");
		cout << "Logged into account: \n";
		cout << *this << endl<< endl;
		cout << "Choose operation: \n\n";
		cout << "1. See balance.\n2. Change tariff.\n3. Connect internet.\n4. Temporary block of number.\n";
		cout << "5. Top up balance.\n6. Change internet.\n7. Change connection.\n8. See info.\n9. Exit.\n\n";

		if (this->getOperator().getBlockCheak() == true)
		{
			cout << "Number is temporary blocked.\n";
			cout << " Do you want to unblock the number? (y/n)?\n";
			cin >> switch_on;
			if (switch_on == 'y')
			{
				this->getOperator().setBlockCheak(false);
				cout << "Number has been unblocked.\n";
			}
			else { cout << "Number has not been unblocked.\n"; }
			rewind(stdin);  _getch();
		}
		else
		{
			cin >> switch_on;
			cin.get();
			cin.clear();
			fflush(stdin);
			switch (switch_on)
			{
			case '1':
				cout << "BALANCE: " << oper.getBalance() << "$" << endl;
				rewind(stdin); 	_getch();
				break;


			case '2':
				cout << "CHOOSE TARIFF: \n" << endl;
				for (int i = 0; i < tariffVec.size(); i++)
				{
					cout << i + 1 << ")\n";
					cout << *tariffVec[i] << endl;
				}
				cin >> temp;
				if (temp > tariffVec.size()) { cout << "Wrong input." << endl; rewind(stdin);  _getch(); break; }
				cout << "It will cost " << tariffVec[temp - 1]->getTarrifCost() << "$, continue (y/n)?\n";
				cin >> switch_on;
				if (switch_on == 'y')
				{
					this->getOperator().setTariff(*tariffVec[temp - 1]);
					this->getOperator().change_balance(-(int)tariffVec[temp - 1]->getTarrifCost());
					cout << "Tariff has been changed.\n";
				}
				else { cout << "Tariff has not been changed.\n"; }
				rewind(stdin);  _getch();
				break;


			case '3':
				if (this->getOperator().getInternet().getName() != "\0")
				{
					cout << "You already have internet:\n";
					this->getOperator().getInternet().print_shapka();
					cout << this->getOperator().getInternet() << endl;
					rewind(stdin); 	_getch();
				}
				else
				{
					cout << "CHOOSE INTERNET: \n" << endl;
					cout << "  "; inetVec[0].print_shapka();
					for (int i = 0; i < inetVec.size(); i++)
					{
						cout << i + 1 << ")\n";
						cout << inetVec[i] << endl;
					}

					cin >> temp;
					if (temp > inetVec.size()) { cout << "Wrong input." << endl; rewind(stdin);  _getch(); break; }
					cout << "It will cost " << inetVec[temp - 1].getCost() << "$, continue (y/n)?\n";
					cin >> switch_on;
					if (switch_on == 'y')
					{
						this->getOperator().setInternet(inetVec[temp - 1]);
						this->getOperator().change_balance(-(int)inetVec[temp - 1].getCost());
						cout << "Internet has been changed.\n";
					}
					else { cout << "Internet has not been changed.\n"; }
					rewind(stdin);  _getch();
				}
				break;


			case '4':
				cout << "Do you want to block number? (y/n)?\n";
				cin >> switch_on;
				if (switch_on == 'y')
				{
					this->getOperator().setBlockCheak(true);
					cout << "Number has been blocked.\n";
				}
				else { cout << "Number has not been blocked.\n"; }
				rewind(stdin);  _getch();
				break;


			case '5':
				
				fl = 0;
				cout << "Input number to top up balance, or input 'this' to top up balance on this number.\n";
				cin >> inputTemp;
				if (inputTemp != "this")
				{
					for (int j = 0; j < operVec.size(); j++)
					{
						if (operVec[j]->getNumber() == inputTemp)
						{
							fl++;
							operTemp = operVec[j];
						}

					}
					if (fl == 0)
					{
						cout << "\nUser is not found.\n";
						rewind(stdin);  _getch();
						break;
					}
				}
				else
				{
					operTemp = &this->getOperator();
				}

				cout << "Input amount of money to top up balance.\n";
				cin >> temp;
				operTemp->change_balance(temp);
				cout << temp << "$ was credited to the " << operTemp->getNumber() << " balance.\n";
				rewind(stdin);  _getch();
				break;


			case '6':
				cout << "CHOOSE INTERNET: \n" << endl;
				cout << "  "; inetVec[0].print_shapka();
				for (int i = 0; i < inetVec.size(); i++)
				{
					cout << i + 1 << ")\n";
					cout << inetVec[i] << endl;
				}

				cin >> temp;
				if (temp > inetVec.size()) { cout << "Wrong input." << endl; rewind(stdin);  _getch(); break; }
				cout << "It will cost " << inetVec[temp - 1].getCost() << "$, continue (y/n)?\n";
				cin >> switch_on;
				if (switch_on == 'y')
				{
					this->getOperator().setInternet(inetVec[temp - 1]);
					this->getOperator().change_balance(-(int)inetVec[temp - 1].getCost());
					cout << "Internet has been changed.\n";
				}
				else { cout << "Internet has not been changed.\n"; }

				rewind(stdin);  _getch();
				break;


			case '7':
				cout << "CHOOSE CONNECTION: \n" << endl;
				cout << "  "; conVec[0].print_shapka();
				for (int i = 0; i < conVec.size(); i++)
				{
					cout << i + 1 << ")\n";
					cout << conVec[i] << endl;
				}

				cin >> temp;
				if (temp > conVec.size()) { cout << "Wrong input." << endl; rewind(stdin);  _getch(); break; }
				cout << "It will cost " << conVec[temp - 1].getCost() << "$, continue (y/n)?\n";
				cin >> switch_on;
				if (switch_on == 'y')
				{
					this->getOperator().setConnection(conVec[temp - 1]);
					this->getOperator().change_balance(-(int)conVec[temp - 1].getCost());
					cout << "Connection has been changed.\n";
				}
				else { cout << "Connection has not been changed.\n"; }

				rewind(stdin);  _getch();
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
}


bool Client::registration(vector<Tarrif*> tariffVec, vector<Operator*> operVec)
{
	string inputTemp;
	char inputChar;
	int inputInt;
	system("cls");
	cout << "\nREGISTRATION: \n";
	cout << "\nInput phone number: ";
	cin >> inputTemp;
	this->getOperator().setNumber(inputTemp);
	this->setNumber(inputTemp);
	cout << "\nInput password: ";
	cin >> inputTemp;
	this->setPass(inputTemp);
	cout << "\nInput name: ";
	cin >> inputTemp;
	this->setName(inputTemp);
	cout << "\nInput surname: ";
	cin >> inputTemp;
	this->setSurname(inputTemp);
	cout << "\nChoose operator: \n";
	for (int i = 0; i < operVec.size(); i++)
	{
		cout << i + 1 << ") ";
		cout << operVec[i]->getOperatorName() << endl;
	}
	cin >> inputInt;
	this->getOperator().setOperatorName(operVec[inputInt-1]->getOperatorName());
	
	for (int i = 0; i < tariffVec.size(); i++)
	{
		cout << i + 1 << ")\n";
		cout << *tariffVec[i] << endl;
	}
	cin >> inputInt;
	this->getOperator().setTariff(*tariffVec[inputInt - 1]);


	cout << "\nComplete registration? (y/n)?" << endl;
	cin >> inputChar;
	if (inputChar == 'y') return true;
	return false;
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

void Client::print_shapka()
{
	cout << setw(SETWSIZE) << "SURNAME" << setw(SETWSIZE) << "NAME" << setw(SETWSIZE) << "NUMBER";
}

ostream& operator<<(ostream& out, const Client& c)
{
	//out << setw(SETWSIZE) << "SURNAME" << setw(SETWSIZE) << "NAME" << setw(SETWSIZE) <<"NUMBER"<<endl;
	out << setw(SETWSIZE) << c.surname << setw(SETWSIZE) << c.name << setw(SETWSIZE) << c.number;
	return out;
}


