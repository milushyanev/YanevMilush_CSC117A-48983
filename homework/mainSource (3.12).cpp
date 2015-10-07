/******************************************************************************/
/*************************** Temperature Conversion ****************************
********************************************************************************
00000000011111111112222222222333333333344444444445555555555666666666677777777778
12345678901234567890123456789012345678901234567890123456789012345678901234567890
/******************************************************************************/

#include <iostream>
#include<iomanip>
using namespace std;
int main()

{
	int number1;
	//using double because temperatures need to be average to one decimal place after the number
	float Celsius, temperature;

	cout << "\nEnter Celsius temperature:";
	cin >> Celsius;

	// using the formula for temperature conversion -> F=(9/5*C)+32
	temperature = (9 * Celsius) / 5 + 32;
	//using setprecision set up to 1 because we don't need temperature with more than 1 number after decimal
	cout << setprecision(1) << fixed;
	//output the result conversion
	cout << "\nFahrenheit temperature is: " << temperature << endl;
	cout << "" << endl;

	return 0;
}