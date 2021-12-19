//#include"list/List.cpp"
#include"list/Algorithm.cpp"
#include"Operator.h"
#include"Client.h"
#include"AdminClient.h"
#include"File_Header.h"
//#include"Algorithm.h"
//#include"List.h"



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

	
	List<Client> clientList;




	Connection* t;
	T_File<Connection> in_c(conPath);
	while (!in_c.In_Eof()) {
		t = new Connection;
		//in_c >> *t;
		*t = in_c.read();
		if (t->getName() == "") break;
		conVec.push_back(*t);
		cout << *t << endl;
	}
	in_c.In_Close();
	cout << endl;



	Internet* q;
	T_File<Internet> in_i(inetPath);
	in_i.get();
	while (!in_i.In_Eof()) {
		q = new Internet;
		//in_i >> *q;
		*q = in_i.read();
		inetVec.push_back(*q);
		cout << *q << endl;
	}
	in_i.In_Close();
	cout << endl;

	Tarrif* w;
	T_File<Tarrif> in_t(tariffPath);
	while (!in_t.In_Eof()) {
		w = new Tarrif;
		//in_t >> *w;
		*w = in_t.read();
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
	in_t.In_Close();
	cout << endl;

	
	T_File<Operator> in_o(operPath);
	Operator* o;
	while (!in_o.In_Eof()) {
		o = new Operator;
		//in_o >> *o;
		*o = in_o.read();
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
	in_o.In_Close();
	cout << endl;

	T_File<Client> in_cl(clientPath);
	Client* c;

	Admin* a = new Admin;
	//in_cl >> *a;
	*a = in_cl.read();
	clientList.push_back(*a);
	clientVec.push_back(a);
	while (!in_cl.In_Eof()) {
		c = new Client;
		//in_cl >> *c;
		*c = in_cl.read();
		if (c->getName() == "") break;
		for (int i = 0; i < operVec.size(); i++)
		{
			if (operVec[i]->getNumber() == c->getNumber())
			{
				c->setOperator(*operVec[i]);
			}
		}
		clientList.push_back(*c);
		clientVec.push_back(c);
		cout << *c;
		cout << endl;
	}
	in_cl.In_Close();
	cout << endl;


	
	cout << "Press any button to continue ";
	_getch();

	






	Client* temp;
	string forNum;
	string forPass;
	char sw;
	int fl = 0;


	List<Client> TempList;
	Client *ForLogin = new Client ;
	Algorithm<Client> al;
	T_File<Operator> out_o(operPath);
	T_File<Internet> out_i(inetPath);
	T_File<Connection> out_c(conPath);
	T_File<Tarrif> out_t(tariffPath);
	T_File<Client> out_cl(clientPath);
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
			ForLogin->setNumber(forNum);
			ForLogin->setPass(forPass);
			/**ForLogin = */
			if (al.find(clientList.begin(), clientList.end(), *ForLogin).get_size() == 0)
			{
				cout << "\nUser is not found.\n";
				cin.get();
				break;
			}
			fl = al.getIndex(clientList.begin(), clientList.end(),
				al.find(clientList.begin(), clientList.end(), *ForLogin)[0]);
				
			if (fl == -1)
			{
				cout << "\nUser is not found.\n";
				cin.get();
				break;
			}
			else {
				if (clientVec[fl]->class_cheak() == 0)
				{
					clientVec[fl]->menu(operVec, tariffVec, inetVec, conVec);
				}
				else { clientVec[fl]->menu(clientVec, operVec, &tariffVec, &inetVec, &conVec); }
				break;
			}
			//for (int i = 0; i < clientVec.size(); i++)
			//{
			//	if (clientVec[i]->getNumber() == forNum && clientVec[i]->getPass() == forPass)
			//	{
			//		fl++;
			//		if (clientVec[i]->class_cheak() == 0)
			//		{
			//			clientVec[i]->menu(operVec, tariffVec, inetVec, conVec);
			//		}
			//		else { clientVec[i]->menu(clientVec, operVec, &tariffVec, &inetVec, &conVec); }
			//		break;
			//	}
			//}

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
				out_i.write(inetVec[j]);
			}
			//out_i.close();

			for (int j = 0; j < conVec.size(); j++)
			{
				out_c.write(conVec[j]);
			}
			//out_c.close();


			for (int j = 0; j < tariffVec.size(); j++)
			{
				out_t.write(*tariffVec[j]);
			}
			//out_t.close();

			for (int j = 0; j < operVec.size(); j++)
			{
				//out_o << *operVec[j];
				out_o.write(*operVec[j]);
			}
			//out_o.close();

			out_cl.write(*clientVec[0]);
			for (int j = 1; j < clientVec.size(); j++)
			{

				out_cl .write( *clientVec[j]);
			}
			//out_cl.close();

			return 0;
		default:
			system("cls");
			break;
		}


	}	

	return 0;
}