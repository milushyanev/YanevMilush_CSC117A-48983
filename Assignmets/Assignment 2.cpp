/******************************************************************************/
/********************************  Assignment 2 ********************************
********************************************************************************
00000000011111111112222222222333333333344444444445555555555666666666677777777778
12345678901234567890123456789012345678901234567890123456789012345678901234567890
/******************************************************************************/

#include <iostream>
#include <stdlib.h>
#include <map>

using namespace std;

float mean(int array[], int size);
float median(int array[], int size);
int * mode(int array[], int size);



int main()
{
	int size = 20;
	int array[20] = { 7, 1, 1, 1, 1, 1, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5, 6, 6, 6, 6 };
	cout << "Input array: ";
	for (int i = 0; i < size; i++) {
		cout << array[i] << " ";
	}
	cout << "\n";

	cout << "The mean of the array is " << mean(array, size) << endl;

	cout << "The median of the array is " << median(array, size) << endl;

	//creating a pointer to function
	int *modes = mode(array, size);
	cout << "Number of modes: " << modes[0];
	cout << "\nMax. frequency of mode 1: " << modes[1] << "\nModes: ";
	//foor loop to calculate modes (mode+2)
	for (int i = 2; i < modes[0] + 2; i++) {
		cout << modes[i] << " ";
	}
	cout << "\n";

	return 0;
}

float mean(int array[], int size)
{
	float average = 0;
	for (int i = 0; i<size; i++)
		average += array[i];
	return average / size;
}

	//adress of code of the function "compare_function"
	//when using void to pointer means that the type of variable can vary
int compare_function(const void *a, const void *b) {
	//can convert variable into a different type 
	//take pointer a (void) -> (int) *x
	// *x takes the value of the address of x(&x), "pointer de-reference"
	int *x = (int *)a;
	int *y = (int *)b;
	//take the result of x-y
	return *x - *y;
}

float median(int array[], int size) {
	//qsort algorithm to sort an array,
	//qsort(array,size,how big is every element in array (int), pointer of function to show )
	qsort(array, size, sizeof(int), compare_function);
	if (size % 2) {
		return (float)array[size / 2];
	}
	else {
		return ((float)(array[size / 2 - 1] + array[size / 2])) / 2.0;
	}
}

	// use a map to count the frequency of each element in the array
	// hash table with key int, value int
	// map template<arguments>function
std::map<int, int> modes;

	// compare keys in the map based on their values
	// hash table starts with empty table, using key as index, and value as value
int comp_modes(const void *a, const void *b) {
	int *x = (int *)a;
	int *y = (int *)b;
	return modes[*y] - modes[*x];
}

int * mode(int array[], int size) {

	//clear the elemets in the hash table (map)
	modes.clear();

	int i;
	//count how many times certain elements occurs in the array of elements
	for (i = 0; i < size; i++) {
	//check if certain element is in the hash table and if its not there zero the table and start over	
	// method find (if not there modes.end=0, if element there counter +1)
	// number of keys in hash table will be element +1,different elements only
		if (modes.find(array[i]) == modes.end()) {
			modes[array[i]] = 0;
		}
	//counter +1
		modes[array[i]] += 1;
	}
	// get the number of modes, only different elements
	int n_modes = modes.size();

	// allocate memory for the results array, modes +2 (number of modes,frequency)
	int * result = new int[n_modes + 2];
	result[0] = n_modes;

	// copy the unsorted modes to the results array
	i = 0;
	//create a cycle that will iterate the keys from the hash table and show only different elemets
	//keys come not in order,after 3rd element
	for (std::map<int, int>::iterator it = modes.begin(); it != modes.end(); ++it)
	{
	//iterator->first element (key, not value), count++
		result[2 + i] = it->first;
		i++;
	}

	// sort the modes based on their frequencies in descending order
	qsort(result + 2, n_modes, sizeof(int), comp_modes);

	// get the maximum frequency
	result[1] = modes[result[2]];

	return result;
}