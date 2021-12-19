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

void Client::operator=(const Client& obj)
{
	this->name = obj.name;
	this->surname = obj.surname;
	this->number = obj.number;
	this->pass = obj.pass;
	this->setOperator(obj.oper);
}

void Client::menu(vector<Operator*> operVec, vector<Tarrif*> tariffVec, vector<Internet> inetVec, vector<Connection> conVec)
{
	for (int i = 0; i < operVec.size(); i++) {
		if (operVec[i]->getNumber() == this->number)
			this->getOperator() = *operVec[i];
	}
	int temp = 0;
	int fl = 0;
	int switch_int;
	string inputTemp;
	char switch_on;
	Operator* operTemp = &this->getOperator();
	vector< Client> otkat;
	otkat.push_back(*this);
	while (1)
	{
		system("cls");
		cout << "Logged into account: \n";
		cout << *this << endl << endl;
		cout << "Choose operation: \n\n";
		cout << "1. See balance.\n2. Change tariff.\n3. Connect internet.\n4. Temporary block of number.\n";
		cout << "5. Top up balance.\n6. See info.\n7. Exit.\n8. Undo last action.\n\n";

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
			input_number_in_diapazone(cin, switch_int, 1, 10);
			cin.get();
			cin.clear();
			fflush(stdin);
			switch (switch_int)
			{
			case 1:
				cout << "BALANCE: " << oper.getBalance() << "$" << endl;
				rewind(stdin); 	_getch();
				break;


			case 2:
				otkat.push_back(*this);
				cout << "CHOOSE TARIFF: \n" << endl;
				for (int i = 0; i < tariffVec.size(); i++)
				{
					cout << i + 1 << ")\n";
					cout << *tariffVec[i] << endl;
				}
				input_number_in_diapazone<int>(cin, temp, 1, tariffVec.size());
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


			case 3:
				otkat.push_back(*this);
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

					input_number_in_diapazone<int>(cin, temp, 1, inetVec.size());
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


			case 4:
				otkat.push_back(*this);
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


			case 5:
				otkat.push_back(*this);
				fl = 0;
				cout << "Input number to top up balance, or input '1111' to top up balance on this number.\n";
				input_phone_number(cin, inputTemp);
		
				if (inputTemp == "1111")
					inputTemp = number;
				for (int j = 0; j < operVec.size(); j++)
				{
					if (operVec[j]->getNumber() == inputTemp)
					{
						fl++;
						operTemp = operVec[j];
						break;
					}

				}
				if (fl == 0)
				{
					cout << "\nUser is not found.\n";
					rewind(stdin);  _getch();
					break;
				}

				cout << "Input amount of money to top up balance.\n";
				
				input_number_in_diapazone<int>(cin, temp, 1, 2000000);
				operTemp->change_balance(temp);
				if (inputTemp == number)
					this->getOperator().change_balance(temp);
				cout << temp << "$ was credited to the " << operTemp->getNumber() << " balance.\n";
				rewind(stdin);  _getch();
				break;

			case 6:
				this->getOperator().info();
				cout << endl;
				cin.get();
				break;
			case 7:
				for (int i = 0; i < operVec.size(); i++) {
					if (operVec[i]->getNumber() == this->number) {

						*operVec[i] = this->getOperator();
						operVec[i]->setConnection(this->getOperator().getConnection());
						operVec[i]->setInternet(this->getOperator().getInternet());
						break;
					}
				}
				return;
				break;
			case 8:
				if(otkat.size()>0)
				*this = otkat.back();
				otkat.pop_back();
				cout << endl;
				cin.get();
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
	//cin >> inputTemp;
	input_phone_number(cin, inputTemp);
	this->getOperator().setNumber(inputTemp);
	this->setNumber(inputTemp);
	cout << "\nInput password: ";
	//cin >> inputTemp;
	input_letters_and_numbers(cin, inputTemp);
	this->setPass(inputTemp);
	cout << "\nInput name: ";
	//cin >> inputTemp;
	input_letters(cin, inputTemp);
	this->setName(inputTemp);
	cout << "\nInput surname: ";
	//cin >> inputTemp;
	input_letters(cin, inputTemp);
	this->setSurname(inputTemp);
	cout << "\nChoose operator: \n";
	for (int i = 0; i < operVec.size(); i++)
	{
		cout << i + 1 << ") ";
		cout << operVec[i]->getOperatorName() << endl;
	}
	//cin >> inputInt;
	input_number_in_diapazone<int>(cin, inputInt, 1, operVec.size());
	this->getOperator().setOperatorName(operVec[inputInt-1]->getOperatorName());
	
	for (int i = 0; i < tariffVec.size(); i++)
	{
		cout << i + 1 << ")\n";
		cout << *tariffVec[i] << endl;
	}
	//cin >> inputInt;
	input_number_in_diapazone<int>(cin, inputInt, 1, tariffVec.size());
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


