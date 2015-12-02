/*
Milush Yanev
Chapter 14, Problem 1
*/

#include <iostream>
#include <string>
using namespace std;

class Numbers{
private:
	int number;
public:
	Numbers();
	void print();
	const static string less20[20] = { "zero", "one", "two", "three", "four", "five",
		"six", "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen",
		"fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen" };
	const static string less100[9] = { "", "", "twenty", "thirty", "forty", "fifty", "sixty",
		"seventy", "eighty", "ninety" };
	const static string hundred = "hundred";
	const static string thousand = "thousand";
};

int main(int argc, char** argv) {
	Numbers info;
	return 0;
}

Numbers::Numbers(){
	cout << "Enter a non-negative number between 0 and 9,999" << endl;
	cin >> number;
	print();
}

void Numbers::print(){
	int n = number;
	int numthou = number / 1000;
	cout << numthou << endl;
}