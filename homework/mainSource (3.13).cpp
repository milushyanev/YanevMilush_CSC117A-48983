/******************************************************************************/
/*************************** Currency Conversion *******************************
********************************************************************************
00000000011111111112222222222333333333344444444445555555555666666666677777777778
12345678901234567890123456789012345678901234567890123456789012345678901234567890
/******************************************************************************/

#include <iostream>
#include<iomanip>
using namespace std;

int main()
{
	// using double for currency conversion
	float USD;
	
	//setting yens and euros to constants of $1
	float const yen_per_dollar = 98.93;
	float const euros_per_dollar = 0.74;

	//enter the amount you want to convert
	cout << "Enter U.S. dollars:  $";cin >> USD;
	
	//setting setprecision to 2 to calculate cents
	cout << setprecision(2) << fixed;

	//print the result of conversion
	cout <<"\n$"<<USD <<" = " << USD*yen_per_dollar<<" Yens"<< endl;
	cout <<"$"<<USD <<" = "<< USD*euros_per_dollar <<"   Euros\n"<< endl;

	
	return 0;
}