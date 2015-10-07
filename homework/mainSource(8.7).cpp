/******************************************************************************/
/**********************  Binary search and bubble sort algorithm    ************
********************************************************************************
00000000011111111112222222222333333333344444444445555555555666666666677777777778
12345678901234567890123456789012345678901234567890123456789012345678901234567890
/******************************************************************************/


#include<iostream>
using namespace std;

//copies of fuctions
void fillArray();
void sortArray(int array[], int size);
void dispay(int array[], int size);
int binarySearch(const int array[], int size, int value);

int main()
{

	fillArray();

	return 0;
}
void fillArray()
{
	//create and array with size 20
	const int size = 20;

	//set up values

	int value, array[size], searchValue;

	for (int count = 0; count < size; count++)
	{


		/* use a random number generator to fill an array with 20 
		random numbers from 1 to 100*/
		value = (rand() % 100) + 1;
		array[count] = value;

		//show the 20 items not in order

		cout << value << endl;
	}
	// call sortArray(array[], size); to show items in order
	sortArray(array, size); 
	
	
	//put statement for the search
	cout << "\nUser, give me a value from 1 to 100 to search for:> "; 
	cin >> searchValue;

/* must use the function for binarySearch
if statement to show wheter or not the number was found*/

	if (binarySearch(array, size, searchValue) != -1) 
	{
		cout << "The value was located in element:> \n" <<
			   binarySearch(array, size, searchValue) << endl;
	}
	else
	{
		cout << "Finished searching and there was no mach\n" << endl;
	}
}
void sortArray(int array[], int size)
/*bool swap,this function needs to sort the array values using the 
buuble sort algorithm from lowest to highest*/
{

	bool swap;
	int temp;
	do

	{
		swap = false;

		//if conditions are met swap to true
		for (int count = 0; count < (size - 1); count++)
		{
			if (array[count] > array[count + 1])
			{
				temp = array[count];
				array[count] = array[count + 1];
				array[count + 1] = temp;
				swap = true;
			}
		}
	} while (swap);

    // call display(array[], size) to show results;
	dispay(array, size);

}
//display the output of sorted array using (array[],size)
void dispay(int array[], int size)
{

	cout << "" << endl;

	//for loop to determine range
	for (int i = 0; i < size; i++)
	{
		cout << array[i] << endl;
	}


}
//create a function for binarySearch(const int array[], int size, int value)
int binarySearch(const int array[], int size, int value) 
{

	int first = 0,

		last = size - 1,

		middle,

		position = -1;

	bool found = false;

	while (!found && first <= last)

	{

		middle = (first + last) / 2;

		if (array[middle] == value)

		{

			found = true;

			position = middle;

		}

		else if (array[middle] > value)

			last = middle - 1;

		else

			first = middle + 1;

	}

	return position;

}