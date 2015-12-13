#ifndef DEVELOPER_H
#define DEVELOPER_H
#include <string>
#include "my_NumberT.h"

using namespace std;

//using also a Template
class Developer{
protected:
	string name;
	string date;
	//template declaration
	my_NumberT<int> number;
	my_NumberT<float> salary;

public:
	Developer();
	Developer(string, int, string);
	Developer(const Developer& orig);
	~Developer();
	void setName(string);
	void setNumber(int);
	void setDate(string);
	string getName();
	int getNumber();
	string getDate();

};
#endif