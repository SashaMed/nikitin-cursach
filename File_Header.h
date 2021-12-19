#pragma once
#include"Service_class.h"






template<typename T>
class T_File  {
private:
	ofstream out;
	ifstream in;
	fstream fstream;
	string path;
public:
	T_File(string n)  { path = n; };
	~T_File() {
		if (out.is_open()) { out.close(); }
		if (in.is_open()) { in.close(); }
		if (fstream.is_open()) { fstream.close(); }
	}



	T read() {
		if (!in.is_open()) {
			in.open(path);
		}
		T temp;
		in >> temp;
		return temp;
	}



	void write(T obj) {
		if (!fstream.is_open()) {
			fstream.open(path);
		}
		fstream << obj;
	}

	void Out_Close() {
		fstream.close();
	}

	void In_Close() {
		in.close();
	}

	bool In_Eof() {
		if (in.eof()) return true;
		return false;
	}

	char get() {
		if (in.is_open())
			return in.get();
		else return '\0';
	}

};