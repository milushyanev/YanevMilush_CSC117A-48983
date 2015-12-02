#ifndef EMPLOYEE_H
#define	EMPLOYEE_H
#include <string>
using namespace std;

class Employee {
public:
	Employee();
	Employee(string, int, string);
	Employee(const Employee& orig);
	~Employee();
	void setName(string);
	void setNumber(int);
	void setDate(string);
	string getName();
	int getNumber();
	string getDate();

protected:
	string name;
	int number;
	string date;
};

#endif	