#pragma once
#include <iostream>
#include <string.h>
#include <vector>
#include <iomanip>
using namespace std;

#define SETWSIZE 18

class Service_class {
protected:
	string name;
	unsigned int cost;
public:
	Service_class();
	Service_class(unsigned int n, string str);
	Service_class(const Service_class &obj);
	~Service_class() {};

	void setCost(unsigned int n);
	void setName(string str);
	string getName();
	unsigned int getCost();
	virtual void print_shapka() = 0;

	friend istream& operator>>(istream& in, Service_class& c);
	friend ostream& operator<<(ostream& out, const Service_class& c);
};