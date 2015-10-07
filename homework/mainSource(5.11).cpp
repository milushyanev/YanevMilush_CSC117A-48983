/******************************************************************************/
/********************** Calculate Days of an certain year **********************
********************************************************************************
00000000011111111112222222222333333333344444444445555555555666666666677777777778
12345678901234567890123456789012345678901234567890123456789012345678901234567890
/******************************************************************************/


#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	int days,orgs;
	//using double for percentage and pop for population
	float increase,pop;
	
	//Ask User for # of Organisms
	cout << "Enter the starting number of organisms:  ";
	cin >> orgs;
	pop = orgs;
	//while loop to manage user input be greater than 2
	while (orgs < 2){
		cout << "Starting number of organisms must be at least 2" << endl;
		cout << "Enter the starting number of organisms:  ";
		cin >> orgs;
	}

		//Ask User for % Poulation Increase
		cout << "Enter the average daily population incease (as a %):  ";
	cin >> increase;
	//while loop to keep percentage more than 0
	while (increase < 0){
		cout << "Enter a positive number starting from 1" << endl;
		cout << "Enter the average daily population incease (as a %):  ";
		cin >> increase;
	}

	//Ask User for # Days to Multiply
	cout << "Enter the number of days to multiply:  ";
	cin >> days;
	//while loop to protect from putting negative values for days
	while (days < 1){
		cout << "Enter valid days starting from 1" << endl;
		cout << "Enter the number of days to multiply:  ";
		cin >> days;
	}

	cout << "		  Population Chart\n\n";
	cout << "======================================\n\n";
	cout << " DAY #			Population\n";

	//Will display initial population plus up to your requested amount of days
	for (int count = 1; count <= days; count++)
	{
		//setprecision to keep numbers within 1 decimal space
		cout << setprecision(1) << fixed;
		//result of organisms
	pop = pop*(1 + (increase / 100));
	//print our result for everyday
		cout << "Day: " << count << "      " << "Population: " << pop<<endl;
	}
	return 0;
}