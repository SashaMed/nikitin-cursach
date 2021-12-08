#pragma once
#include"Service_class.h"


class Internet : public Service_class
{
protected:
	float speed;
	int limit;
public:
	Internet();
	Internet(float s, int l, int c, string n);
	Internet(const Internet& obj);
	~Internet();

	void setSpeed(float s);
	void setLimit(int i);

	float getSpeed();
	int getLimit();
	void print_shapka();

	friend istream& operator>>(istream& in, Internet& I);
	friend ostream& operator<<(ostream& out, const Internet& I);
};