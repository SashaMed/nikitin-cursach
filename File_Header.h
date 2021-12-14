#pragma once
#include"Service_class.h"



class File {
protected:
	ofstream out;
	ifstream in;
	fstream fstr;
public:
	string path;
	File(string n) { path = n; }
};


template<typename valueType>
class T_File : public File {
public:
	T_File(string n) :File(n) {};
	~T_File() {
		if (out.is_open()) { out.close(); }
		if (in.is_open()) { in.close(); }
		if (fstr.is_open()) { fstr.close(); }
	}
	bool open(string path, unsigned int mode) {
		switch (mode)
		{
		case 1:
			out.open(path);
			if (out.is_open()) return true;
			return false;
		case 2:
			in.open(path);
			if (in.is_open()) return true;
			return false;
		case 3:
			fstr.open(path, ofstream::app);
			if (fstr.is_open()) return true;
			return false;
		default:
			break;
		}
	}

	valueType read() {
		if (!in.is_open()) {
			in.open(path);
		}
		valueType buf;
		in >> buf;
		return buf;
	}

	valueType read(string p) {
		if (!in.is_open()) {
			in.open(p);
		}
		valueType buf;
		in >> buf;
		in.close();
		return buf;
	}


	void write(valueType obj) {
		if (!fstr.is_open()) {
			fstr.open(path);
		}
		fstr << obj;
	}

	void Outclose() {
		fstr.close();
	}

	void Inclose() {
		in.close();
	}

	bool InEof() {
		if (in.eof()) return true;
		return false;
	}

	char get() {
		if (in.is_open())
			return in.get();
		else return '\0';
	}

};