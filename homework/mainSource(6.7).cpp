/******************************************************************************/
/**********************                                   **********************
********************************************************************************
00000000011111111112222222222333333333344444444445555555555666666666677777777778
12345678901234567890123456789012345678901234567890123456789012345678901234567890
/******************************************************************************/


#include <iostream>
#include<iomanip>

using namespace std;

void celsius(double temp[], int size);
void showTemp(double temp[], int size);


int main()
{
	//set up size of array
	const int tempSize = 21;
	float temp[tempSize] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20 };

	cout << "Fahrenheit to Celsius conversion chart 0 to 20 degrees\n";
		//call function to show range of degrees
	cout << "\nRange of degrees is: " << endl;
		showTemp(temp, tempSize);
		cout << "\n" << endl;
		//calculate range
		cout << "Actual converted degrees: \n" << endl;
		celsius(temp,tempSize);
		cout <<"\n"<< endl;

	return 0;
}
void celsius(double temp[], int size)
{
		for (int i = 0; i < 20; i++)
		{
			double celsius1;
			//use setprecision for temperatures
			cout << setprecision(1) << fixed; 
			//formula to convert F to C (temp-32)* (5/9)
			celsius1 = temp[i] - 32.0 * (5.0 / 9.0);
			//output
			cout << celsius1 << ", ";
		  
		}
		
}
void showTemp(double temp[], int size)
{
	for (int i = 0; i < size; i++){
		//use setprecision for temperatures
		cout << setprecision(1) << fixed;
		cout << temp[i] << ", ";
	}
}
