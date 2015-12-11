#include "Developer.h"

//set default class
Developer::Developer()
{
	name = "John Smith";
	number = 000;
	date = "1/1/2000";
}
Developer::Developer(string n, int num, string d)
{
	name = n;
	number = num;
	date = d;
}
Developer::Developer(const Developer& orig)
{
}
//alocate
Developer::~Developer()
{
}
//call functios for certain class
void Developer::setName(string n)
{
	name = n;
}
void Developer::setNumber(int num)
{
	number = num;
}
void Developer::setDate(string d)
{
	date = d;
}
//get result
string Developer::getName()
{
	return name;
}
int Developer::getNumber()
{
	return number;
}
string Developer::getDate()
{
	return date;
}