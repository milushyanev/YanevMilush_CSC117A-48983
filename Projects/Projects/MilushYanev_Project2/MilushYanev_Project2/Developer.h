#ifndef DEVELOPER_H
#define DEVELOPER_H
#include <string>

using namespace std;

class Developer{
protected:
	string name;
	string date;
	int number;

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