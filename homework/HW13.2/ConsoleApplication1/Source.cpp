/*
Milush Yanev
Chapter 13, Problem 2
*/

#include <iostream>
using namespace std;

class Date{
private:
	int month, day, year;
public:
	void getdate();
	void print1();
	void print2();
	void print3();
};

int main(int argc, char** argv) {
	Date date;
	int choice;
	cout << "Hello!" << endl << endl;
	date.getdate();
	cout << "What format do you want to output the date as?" << endl;
	cout << "1. MM/DD/YYYY\n2. Month/DD/YYYY\n3. DD/Month/YYYY" << endl;
	cin >> choice;
	switch (choice){
	case 1:
		date.print1();
		break;
	case 2:
		date.print2();
		break;
	case 3:
		date.print3();
		break;
	default:
		return 0;
	}
	return 0;
}

void Date::getdate(){
	cout << "Please enter a date." << endl;
	cout << "Enter the number that corresponds to the month of the year." << endl;
	cin >> month;
	while (month<1 || month>12){
		cout << "Error. Invalid month. Try again." << endl;
		cin >> month;
	}
	cout << "Enter the day." << endl;
	cin >> day;
	while (day<1 || day>31){
		cout << "Error. Invalid day. Try again." << endl;
		cin >> day;
	}
	cout << "Enter the year." << endl;
	cin >> year;
	cout << "Thanks!" << endl;
}

void Date::print1(){
	cout << month << "/" << day << "/" << year << endl;
}

void Date::print2(){
	if (month == 1)cout << "January";
	if (month == 2)cout << "February";
	if (month == 3)cout << "March";
	if (month == 4)cout << "April";
	if (month == 5)cout << "May";
	if (month == 6)cout << "June";
	if (month == 7)cout << "July";
	if (month == 8)cout << "August";
	if (month == 9)cout << "September";
	if (month == 10)cout << "October";
	if (month == 11)cout << "November";
	if (month == 12)cout << "December";
	cout << " " << day << ", " << year << endl;
}

void Date::print3(){
	cout << day << " ";
	if (month == 1)cout << "January";
	if (month == 2)cout << "February";
	if (month == 3)cout << "March";
	if (month == 4)cout << "April";
	if (month == 5)cout << "May";
	if (month == 6)cout << "June";
	if (month == 7)cout << "July";
	if (month == 8)cout << "August";
	if (month == 9)cout << "September";
	if (month == 10)cout << "October";
	if (month == 11)cout << "November";
	if (month == 12)cout << "December";
	cout << " " << year << endl;
}