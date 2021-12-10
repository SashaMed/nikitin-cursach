#pragma once
#include"Client.h"


class Admin : public Client
{
public:
	Admin();
	Admin(string s, string n, string num) : Client(s, n, num) {};
	Admin(string surn, string name, string num, Operator op) : Client(surn, name, num, op) {};
	Admin(const Client& obj) : Client(obj) {};

	void menu(vector<Client*> clientVec, vector<Operator*> operVec, vector<Tarrif*>  *tariffVec, vector<Internet> *inetVec, vector<Connection> *conVec)
	{
		this->getOperator().setOperatorName("admin");
		int inputInt;
		int fl = 0;
		string inputStr;
		char switch_on;
		char inputChar;
		Internet *itemp;
		Connection* ctemp;
		Tarrif* ttemp;
		while (1)
		{
			system("cls");
			cout << "Logged into admin account: \n";
			cout << *this << endl << endl;
			cout << "Choose operation: \n\n";
			cout << "1. View all users.\n2. New tariff.\n3. New internet.\n4. New connection.\n";
			cout << "5. Log in client account.\n7. Exit.\n\n";
			cin >> switch_on;
			cin.clear();
			fflush(stdin);
			switch (switch_on)
			{
			case '1':
				clientVec[0]->print_shapka(); cout << setw(SETWSIZE) << "OPERATOR NAME" << endl;
				for (int i = 0; i < clientVec.size(); i++)
				{
					cout << *clientVec[i] << setw(SETWSIZE) << clientVec[i]->getOperator().getOperatorName()<<endl;
				}

				rewind(stdin);  _getch();
				break;
			case '2':
				cout << "NEW TARIFF:\n\n";
				ttemp = new Tarrif;
				cout << "Input name of tariff: ";
				cin >> inputStr;
				ttemp->setTarrif_Name(inputStr);

				cout << "Choose internet for tariff:\n";
				for (int i = 0; i < inetVec->size(); i++)
				{
					cout << i + 1 << ")\n";
					cout << inetVec->at(i) << endl;
				}
				cin >> inputInt;
				ttemp->setInternet(inetVec->at(inputInt - 1));

				cout << "Choose connection for tariff:\n";
				for (int i = 0; i < conVec->size(); i++)
				{
					cout << i + 1 << ")\n";
					cout << conVec->at(i) << endl;
				}
				cin >> inputInt;
				ttemp->setConnection(conVec->at(inputInt - 1));
				cout << "New tariff was created: \n";
				//ttemp->print_shapka();
				cout << *ttemp;
				cout << "\nSave object? (y/n)?" << endl;
				cin >> inputChar;
				if (inputChar == 'y')
				{
					tariffVec->push_back(ttemp);
				}
				else
				{
					cout << "New tariff was not created: \n";
				}


				rewind(stdin);  _getch();
				break;
			case '3':
				cout << "NEW INTERNET:\n\n";
				itemp = new Internet;

				cout << "Input name of internet: ";
				cin >> inputStr;
				itemp->setName(inputStr);
				cout << "\nInput cost of internet: ";
				cin >> inputInt;
				itemp->setCost(inputInt);
				cout << "\nInput speed of internet: ";
				cin >> inputInt;
				itemp->setSpeed(inputInt);
				cout << "\nInput limit of internet: ";
				cin >> inputInt;
				itemp->setLimit(inputInt);
				//cin >> *itemp;
				cout << "New internet was created: \n";
				itemp->print_shapka();
				cout << *itemp;
				cout << "\nSave object? (y/n)?" << endl;
				cin.clear();
				fflush(stdin);
				cin >> inputChar;
				if (inputChar == 'y')
				{
					inetVec->push_back(*itemp);
				}
				else
				{
					cout << "New internet was not created: \n";
				}
				


				rewind(stdin);  _getch();
				break;
			case '4':
				cout << "NEW CONNECTION:\n\n";
				ctemp = new Connection;

				cout << "Input name of connection: ";
				cin >> inputStr;
				ctemp->setName(inputStr);
				cout << "\nInput cost of connection: ";
				cin >> inputInt;
				ctemp->setCost(inputInt);
				cout << "\nInput count of minuts for connection: ";
				cin >> inputInt;
				ctemp->setMinutes(inputInt);
				cout << "\nInput count of SMS for connection: ";
				cin >> inputInt;
				ctemp->setCount_SMS(inputInt);
				//cin >> *itemp;
				cout << "New connection was created: \n";
				ctemp->print_shapka();
				cout << *ctemp;
				cout << "\nSave object? (y/n)?" << endl;
				cin.clear();
				fflush(stdin);
				cin >> inputChar;
				if (inputChar == 'y')
				{
					conVec->push_back(*ctemp);

				}
				else
				{
					cout << "New connection was not created: \n";
				}



				rewind(stdin);  _getch();
				break;

			case'7':
				return;
			default:
				break;
			}

		}
	}

	int class_cheak() { return 1; };
};