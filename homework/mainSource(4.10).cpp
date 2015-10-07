/******************************************************************************/
/********************** Calculate Days of an certain year **********************
********************************************************************************
00000000011111111112222222222333333333344444444445555555555666666666677777777778
12345678901234567890123456789012345678901234567890123456789012345678901234567890
/******************************************************************************/

#include <iostream>
using namespace std;

bool menuInputValidation(int choice, int numChoices);
int main()
{
	//creating variables as int because we dont need information after decimal place
	int month,year,days;
	//enter the number of a month
	cout << "enter a month from 1-12 ";cin >> month;
	
	//use while loop to check numbers (1-12) until right number is selected
	while (!menuInputValidation(month, 12)) {
		cout << "Enter month "; cin >> month;
	}
	//if statement to check months selected and provide days count
	if (month == 1 || month == 3 || month == 5 || month == 7 ||
		month == 8 || month == 10 || month == 12){
		days = 31;
	}
	//if statement to check months selected and provide days count
	if (month == 4 || month == 6 || month == 9 || month == 11){
		days = 30;
	}
	cout << "enter a year "; cin >> year;
	//if statements to check wheter or not leap year
	//if year is divided by 400 and 100(ex. 1600,2000),days are 29
	if (month == 2 && year % 100 == 0 && year % 400 == 0){
		days = 29;
	}
	//if year is divided by 4 but not by 100 (ex. 2012,2008), days are 29
	if (month == 2 && year % 100 != 0 && year % 4 == 0){
		days = 29;
	}
	//else if month is 2,days are 28
	else if (month==2){
		days = 28;
	}
	//print out the result
	cout << "number of days: " << days<<"\n"<<endl;
	return 0;
}
//menu called menuInputValidation to check if numbers are selected right
bool menuInputValidation(int choice, int numChoices)
{
	//if choice is not in the range, output cout statement
	if (choice <= 0 || choice > numChoices)
	{
		cout << "\nInvalid! Please select number ";
		//for statement to provide the choices you have
		for (int i = 1; i <= numChoices; i++)
		{
			cout << i;
		//if statement to give choices from certain range, separated by "or"
			if (i != numChoices)
			{
				cout << " or ";
			}
		}
		cout << endl;
		//return false until the conditions are met
		return false;
	}
	//return true if the conditions are met
	return true;
}