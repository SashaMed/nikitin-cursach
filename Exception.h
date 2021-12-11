#pragma once
#include<iostream>
#include<string>
using namespace std;

class Exception
{
protected:
	string error_message;
public:
	Exception(string error_txt = "") : error_message(error_txt)
	{
	}
	string what();
};