/******************************************************************************/
/******************************  Homework 9.2 **********************************
********************************************************************************
00000000011111111112222222222333333333344444444445555555555666666666677777777778
12345678901234567890123456789012345678901234567890123456789012345678901234567890
/******************************************************************************/

#include <iostream>
using namespace std;



int main()
{

	int n;
	float sum,avg;

	//create a pointer for array
	int *tests;

	cout << "How many tests do you want to enter:";
	cin >> n;

	//dynamic array allocate
	tests = new int[n];

	cout << "\nEnter the test's scores \n";

	//for loop to add tests one by one
	for (int i = 0; i < n; i++){
		cout << "\nScore of test " << (i + 1) << " : ";
		cin >> tests[i]	;	
	}
	//for loop for estimating the sum
	for (int i = 0; i < n; i++){
	
		sum += tests[i];
	}

	//print out results
	cout<<"\nThe sum is " << sum << endl;
	avg = sum / n;
	cout <<"\nThe average is "<< avg << endl;
	cout << "\n" << endl;

	//free memory or de-allocate array
	delete []tests;

	return 0;
}