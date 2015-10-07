/******************************************************************************/
/**********************                                   **********************
********************************************************************************
00000000011111111112222222222333333333344444444445555555555666666666677777777778
12345678901234567890123456789012345678901234567890123456789012345678901234567890
/******************************************************************************/


#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	//ifstream for creating a file
	ifstream infile;

	//size of array
	int array[12];
	//max size of file name
	char fileName[21];
	//declare variables
	int number, total = 0,nums = 0,size;

	//create a name , later on it shout be "nameCreated.txt"
	cout << "Enter a file name: ";
	cin >> fileName;

	infile.open(fileName);

	//create a for loop to indicate size of array and count++
	for (int i = 0; i < 12; i++)
	{
		infile >> array[i];
		total += array[i];
	}

	int lowest = array[0];
	int highest = array[0];

	//for loop to find which number is lowest and highest

	for (int i = 0; i < 12; i++)
	{
		if (array[i] > highest)
			highest = array[i];
		if (array[i] < lowest)
			lowest = array[i];
	}

	//output results

	cout << "Total: " << total << endl;

	//to find average you need to divide the total by the numbers in array (12)
	cout << "Average: " << total / 12 << endl;
	cout << "Highest: " << highest << endl;
	cout << "Lowest: " << lowest << endl;

	//save
	infile.close();

	return 0;
}
