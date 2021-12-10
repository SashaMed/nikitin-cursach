#include"Operator.h"
#include"Client.h"
#include"AdminClient.h"

int main() {
	Tarrif *tarrifArr = new Tarrif[2];
	Connection *conArr = new Connection[2];
	Internet* inetArr = new Internet[2];
	Operator* operArr = new Operator[2];


	conArr[0].setName("danila");
	conArr[0].setCost(51);
	conArr[0].setMinutes(0);
	conArr[0].setCount_SMS(1);

	conArr[1].setName("pitsa");
	conArr[1].setCost(4);
	conArr[1].setMinutes(2000);
	conArr[1].setCount_SMS(20000);

	inetArr[0].setName("zala ebani");
	inetArr[0].setCost(2012);
	inetArr[0].setLimit(8900);
	inetArr[0].setSpeed(250);


	inetArr[1].setName("byfly ebani");
	inetArr[1].setCost(30);
	inetArr[1].setLimit(1000000);
	inetArr[1].setSpeed(250);


	tarrifArr[0].setInternet(inetArr[0]);
	tarrifArr[0].setConnection(conArr[0]);
	tarrifArr[0].setTarrif_Name("lemon");

	tarrifArr[1].setInternet(inetArr[1]);
	tarrifArr[1].setConnection(conArr[1]);
	tarrifArr[1].setTarrif_Name("arbuz");

	Operator *oper = new Operator[3];
	oper[0].setTariff(tarrifArr[0]);
	oper[0].setOperatorName("life govan");
	oper[0].setNumber("+375447750026");

	
	oper[1].setOperatorName("chad A1");
	oper[1].setTariff(tarrifArr[1]);
	oper[1].setNumber("+375447275676");

	oper[2].setOperatorName("virgin MTS");
	/*oper[2].setTariff(tarrifArr[1]);*/
	oper[2].setConnection(conArr[1]);
	oper[2].setNumber("++375331234567");


	Client sasha("mednis", "sasha", "+375447750026", oper[0]);
	sasha.setPass("12345");

	Client mama("gatal", "anna", "+375447275676", oper[1]);
	mama.setPass("god");

	Client oleg("vector", "oleg", "+375331234567", oper[2]);
	oleg.setPass("321");

	Admin admin("dashkevich", "nikita", "+375293063043");
	admin.setPass("sexing");

	vector<Client*> clientArr;
	clientArr.push_back(&sasha);
	clientArr.push_back(&mama);
	clientArr.push_back(&oleg);
	clientArr.push_back(&admin);

	vector< Operator*> operVec;
	operVec.push_back(&sasha.getOperator());
	operVec.push_back(&mama.getOperator());
	operVec.push_back(&oleg.getOperator());

	vector<Tarrif*> tariffVec;
	tariffVec.push_back(&tarrifArr[0]);
	tariffVec.push_back(&tarrifArr[1]);

	Client* temp;
	string forNum;
	string forPass;
	char sw;
	int fl = 0;
	vector<Internet> inetVec;
	vector<Connection> conVec;
	for (int q = 0; q < 2; q++)
	{
		inetVec.push_back(inetArr[q]);
		conVec.push_back(conArr[q]);

	}
	while (1)
	{
		system("cls");
		cout << "Choose operation: \n\n";
		cout << "1. Log in.\n2. Registration.\n3. Exit.\n";
		cout << endl;
		fflush(stdin);
		cin >> sw;

		switch (sw) {
		case '1':

			cout << "\nInput phone number: ";
			cin >> forNum;
			cout << "\nInput password: ";
			cin >> forPass;
			cin.get();
			fl = 0;
			for (int i = 0; i < clientArr.size(); i++)
			{
				if (clientArr[i]->getNumber() == forNum && clientArr[i]->getPass() == forPass)
				{
					fl++;
					//clientArr[i]->menu(clientArr, operVec, tariffVec, inetVec, conVec);
					if (clientArr[i]->class_cheak() == 0 ) { clientArr[i]->menu( operVec, tariffVec, inetVec, conVec); }
					else { clientArr[i]->menu(clientArr, operVec, &tariffVec, &inetVec, &conVec); }
					break;
				}
			}
			if (fl == 0)
			{
				cout << "\nUser is not found.\n";
				cin.get();
			}
			break;
		case '2':
			temp = new Client;
			clientArr.push_back(temp);
			//operVec.push_back(&temp->getOperator());
			if (temp->registration(tariffVec,operVec) == false) clientArr.pop_back();
			operVec.push_back(&temp->getOperator());
			break;
		case '3':
			return 0;
		default:
			system("cls");
			break;
		}
	

	}

	
	return 0;
}