#include"Operator.h"
#include"Client.h"
#include"AdminClient.h"

int main() {

	const char* tariffPath = "_tariff.txt";
	const char* inetPath = "_internet.txt";
	const char* conPath = "_connection.txt";
	const char* operPath = "_operator.txt";
	const char* clientPath = "_client.txt";

	Tarrif* tarrifArr = new Tarrif[2];
	Connection* conArr = new Connection[2];
	Internet* inetArr = new Internet[2];
	Operator* operArr = new Operator[2];

	vector<Internet> inetVec;
	vector<Connection> conVec;
	vector<Tarrif*> tariffVec;
	vector< Operator*> operVec;
	vector<Client*> clientVec;





	Connection* t;
	ifstream in_c(conPath);
	while (!in_c.eof()) {
		t = new Connection;
		in_c >> *t;
		if (t->getName() == "") break;
		conVec.push_back(*t);
		cout << *t << endl;
	}
	in_c.close();
	cout << endl;


	Internet* q ;
	ifstream in_i(inetPath);
	in_i.get();
	while (!in_i.eof()) {
		q = new Internet;
		in_i >> *q;
		inetVec.push_back(*q);
		cout << *q << endl;
	}
	in_i.close();
	cout << endl;

	Tarrif* w;
	ifstream in_t(tariffPath);
	while (!in_t.eof()) {
		w = new Tarrif;
		in_t >> *w;
		if (w->getTarrif_Name() == "") break;
		for (int i = 0; i < inetVec.size(); i++)
		{
			if (inetVec[i].getName() == w->getInetName())
			{
				w->setInternet(inetVec[i]);
			}
		}
		for (int i = 0; i < conVec.size(); i++)
		{
			if (conVec[i].getName() == w->getConName())
			{
				w->setConnection(conVec[i]);
			}
		}
		tariffVec.push_back(w);
		cout << *w << endl;
	}
	in_t.close();
	cout << endl;

	
	ifstream in_o(operPath);
	Operator* o;
	while (!in_o.eof()) {
		o = new Operator;
		in_o >> *o;
		if (o->getOperatorName() == "") break;
		for (int i = 0; i < tariffVec.size(); i++)
		{
			if (tariffVec[i]->getTarrif_Name() == o->getTarrif_Name())
			{
				o->setTariff(*tariffVec[i]);
			}
		}

		operVec.push_back(o);
		o->info();
		cout << endl;
	}
	in_o.close();
	cout << endl;

	ifstream in_cl(clientPath);
	Client* c;

	Admin* a = new Admin;
	in_cl >> *a;
	clientVec.push_back(a);
	while (!in_cl.eof()) {
		c = new Client;
		in_cl >> *c;
		if (c->getName() == "") break;
		for (int i = 0; i < operVec.size(); i++)
		{
			if (operVec[i]->getNumber() == c->getNumber())
			{
				c->setOperator(*operVec[i]);
			}
		}

		clientVec.push_back(c);
		cout << *c;
		cout << endl;
	}
	in_cl.close();
	cout << endl;


	
	cout << "Press any button to continue ";
	_getch();

	conArr[0].setName("danila");
	conArr[0].setCost(51);
	conArr[0].setMinutes(0);
	conArr[0].setCount_SMS(1);

	conArr[1].setName("pitsa");
	conArr[1].setCost(4);
	conArr[1].setMinutes(2000);
	conArr[1].setCount_SMS(20000);

	inetArr[0].setName("zala ebanuti");
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

	Operator* oper = new Operator[3];
	oper[0].setTariff(tarrifArr[0]);
	oper[0].setOperatorName("life govan");
	oper[0].setNumber("+375447750026");


	oper[1].setOperatorName("chad A1");
	oper[1].setTariff(tarrifArr[1]);
	oper[1].setNumber("+375447275676");

	oper[2].setOperatorName("virgin MTS");
	oper[2].setTariff(tarrifArr[1]);
	oper[2].setNumber("+375331234567");


	Client sasha("mednis", "sasha", "+375447750026", oper[0]);
	sasha.setPass("12345");

	Client anna("gatal", "anna", "+375447275676", oper[1]);
	anna.setPass("godofwar");

	Client oleg("vector", "oleg", "+375331234567", oper[2]);
	oleg.setPass("321");

	Admin admin("dashkevich", "nikita", "+375293063043");
	admin.setPass("sexing");

	vector<Client*> clientVec2;
	clientVec2.push_back(&sasha);
	clientVec2.push_back(&anna);
	clientVec2.push_back(&oleg);
	clientVec2.push_back(&admin);

	//vector< Operator*> operVec;
	//operVec.push_back(&sasha.getOperator());
	//operVec.push_back(&anna.getOperator());
	//operVec.push_back(&oleg.getOperator());





	vector<Tarrif*> tariffVec2;
	tariffVec2.push_back(&tarrifArr[0]);
	tariffVec2.push_back(&tarrifArr[1]);


	Client* temp;
	string forNum;
	string forPass;
	char sw;
	int fl = 0;
	//vector<Internet> inetVec;
	//vector<Connection> conVec;
	

	//fstream out(conPath);
	//fstream out2(inetPath);

	//fstream out3(tariffPath);
	//for (int q = 0; q < 2; q++)
	//{
	//	out3 << *tariffVec2[q];
	//}
	//out3.close();
	
	//out2.close();
	//out.close();

	fstream out_o(operPath);
	fstream out_i(inetPath);
	fstream out_c(conPath);
	fstream out_t(tariffPath);
	fstream out_cl(clientPath);
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
			//cin >> forNum;
			input_phone_number(cin, forNum);
			cout << "\nInput password: ";
			//cin >> forPass;
			input_letters_and_numbers(cin, forPass);
			fl = 0;
			for (int i = 0; i < clientVec.size(); i++)
			{
				if (clientVec[i]->getNumber() == forNum && clientVec[i]->getPass() == forPass)
				{
					fl++;
					if (clientVec[i]->class_cheak() == 0)
					{
						clientVec[i]->menu(operVec, tariffVec, inetVec, conVec);
					}
					else { clientVec[i]->menu(clientVec, operVec, &tariffVec, &inetVec, &conVec); }
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
			clientVec.push_back(temp);
			//operVec.push_back(&temp->getOperator());
			if (temp->registration(tariffVec, operVec) == false) clientVec.pop_back();
			operVec.push_back(&temp->getOperator());
			break;
		case '3':
		
			for (int j = 0; j < inetVec.size(); j++)
			{
				out_i << inetVec[j];
			}
			out_i.close();

			for (int j = 0; j < conVec.size(); j++)
			{
				out_c << conVec[j];
			}
			out_c.close();


			for (int j = 0; j < tariffVec.size(); j++)
			{
				out_t << *tariffVec[j];
			}
			out_t.close();

			for (int j = 0; j < operVec.size(); j++)
			{
				out_o << *operVec[j];
			}
			out_o.close();

			out_cl << *clientVec[0];
			for (int j = 1; j < clientVec.size(); j++)
			{

				out_cl << *clientVec[j];
			}
			out_cl.close();

			return 0;
		default:
			system("cls");
			break;
		}


	}	

	return 0;
}