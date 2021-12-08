#include"Operator.h"
#include"Client.h"

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

	Operator *oper = new Operator[2];
	oper[0].setTariff(tarrifArr[0]);
	oper[0].setOperatorName("life govan");
	oper[0].setNumber("+375447750026");

	
	oper[1].setOperatorName("chad A1");
	oper[1].setTariff(tarrifArr[1]);
	oper[1].setNumber("+375447275676");

	vector< Operator*> operVec;
	operVec.push_back(&oper[0]);
	operVec.push_back(&oper[1]);

	Client sasha("mednis", "sasha", "+375447750026", oper[0]);
	sasha.setPass("12345");

	Client mama("gatal", "anna", "+375447275676", oper[1]);
	mama.setPass("god");

	vector<Client*> clientArr;
	clientArr.push_back(&sasha);
	clientArr.push_back(&mama);

	vector<Tarrif*> tariffVec;
	tariffVec.push_back(&tarrifArr[0]);
	tariffVec.push_back(&tarrifArr[1]);

	string forNum;
	string forPass;
	char sw;
	int fl = 0;
	while (1)
	{
		system("cls");
		cout << "Choose operation: \n\n";
		cout << "1. Log in.\n2. Exit.\n";
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
					clientArr[i]->menu(operVec, tariffVec, inetArr,conArr);
					/*cout << "Autorized to: \n";
					cout << *clientArr[i];
					clientArr[i]->getOperator().setTarrif_Name("aaaaaaaaaaaaaaa");*/
					cin.get();
					break;
				}
			}
			if (fl ==0 ) cout << "\nUser is not found.\n";
			cin.get();
			break;
		case '2':
			return 0;
		default:
			system("cls");
			break;
		}
	

	}

	
	return 0;
}