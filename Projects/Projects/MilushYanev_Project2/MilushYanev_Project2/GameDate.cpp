#include <iostream>
#include <string>

//call GameDate header file 
#include "GameDate.h"

using namespace std;

//constructor
GameDate::GameDate()
{
	this->day = 0;
	this->month = 0;
	this->year = 0;
}
//copy constructor
GameDate::GameDate(const GameDate &obj)
{
	this->day = obj.day;
	this->month = obj.month;
	this->year = obj.year;
}
//destructor
GameDate::~GameDate()
{

}
//set Day
void GameDate::setDay(int d)
{
	this->day = d;
}
//set Month
void GameDate::setMonth(int m)
{
	this->month = m;

}
//set Year
void GameDate::setYear(int y)
{
	this->year = y;
}
//get the Date
int GameDate::getDay()
{
	return day;
}
//get Month
int GameDate::getMonth()
{
	return month;
}
//get Year
int GameDate::getYear()
{
	return year;
}
//initilize the array and fill it 
void GameDate::print()
{
	//create constant array that hold number of monhts
	static const int MonthDays[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 };
	//create string array that holds name of months
	static const string MonthName[] = { "", "January", "February", "March", "April",
		"May", "June", "July", "August", "September", "October", "November", "December" };

	//printing message month,day,year
	cout << MonthName[month] << " " << day << " " << year << endl;
}

void GameDate::MDY(GameDate *date)
{

	//initialize variables
	int day = 0;
	int month = 0;
	int year = 0;

	//enter a valid month
	cout << "Please enter a month between 1-12" << endl;
	cin >> month;

	//while loop to check input 
	while (month < 1 || month>12)
	{
		cout << "Please enter a valid month" << endl;
		cin >> month;
	}
	//if statement to determine days of certain month
	if (month == 1 || month == 3 || month == 5 || month == 7
		|| month == 8 || month == 10 || month == 12)
	{
		//enter valid days
		cout << "Please enter a day between 1-31" << endl;
		cin >> day;
		//while loop to check if corrected day was entered
		while (day < 1 || day >31)
		{
			cout << "Please enter a valid positive number between 1 and 31" << endl;
			cin >> day;
		}
	}
	else if (month == 4 || month == 6 || month == 9 || month == 11)
	{
		//enter valid days
		cout << "Please enter a day between 1-30" << endl;
		cin >> day;

		//while loop to check if corrected day was entered
		while (day < 1 || day >30)
		{
			cout << "Please enter a valid positive number between 1 and 30" << endl;
			cin >> day;
		}
	}
	else if (month == 2)
	{
		//enter valid days
		cout << "Please enter a day between 1-28" << endl;
		cin >> day;

		//while loop to check if corrected day was entered
		while (day < 1 || day >28)
		{
			cout << "Please enter a valid positive number between 1 and 28" << endl;
			cin >> day;
		}
	}
	//enter year from certain range
	cout << "Please enter a year between 1990 and 2100" << endl;
	cin >> year;

	//while loop to determine range
	while (year < 1990 || year>2100)
	{
		cout << "Please enter a year between 1990 and 2100" << endl;
		cin >> year;
	}
	//set day, month,year
	date->setDay(day);
	date->setMonth(month);
	date->setYear(year);

	//print out date
	date->print();
}