/*
Milush Yanev
Chapter 14, Problem 4

*/


#include <iostream>
#include "NumDays.h"
using namespace std;

int main() {
	NumDays num1;
	NumDays num2(12);
	num1 = num2++;
	num1 = num2--;
	num1 = --num2;
	cout << num1.getNumDays();
	return 0;
}