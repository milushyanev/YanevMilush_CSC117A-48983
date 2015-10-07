/******************************************************************************/
/***************************** Homework 9.6-9.7 ********************************
********************************************************************************
00000000011111111112222222222333333333344444444445555555555666666666677777777778
12345678901234567890123456789012345678901234567890123456789012345678901234567890
/******************************************************************************/

// This program shows the donations made to the United Cause
// by the employees of CK Graphics, Inc. It displays
// the donations in order from highest to lowest 
// and in the original order they were received.
#include <iostream>
using namespace std;
// Function prototypes
void arrSelectSort(int *[], int);
void showArray(const int[], int);
void showArrPtr(int *[], int);
int main()
{
	 
	 // Number of donations
	 int numDon;
	 //Dynamic array 
	 int *donations;
		 //Get the number of donations
	 cout << "How many donations you want to enter?";
	 cin >> numDon;
	 
		 // A dynamic array to hold donations
	 donations = new int[numDon];

		//Get donations
		
	 cout << "Enter donations one by one.\n";
	 for (int i = 0; i < numDon; i++){
		 cout << "Donations are" << (i + 1) << ": ";
		 cin >> donations[i];
	 }
	//array of pointers
	 int **arr = new int *[numDon]; 
	 for (int count = 0; count < numDon; count++){
		 arr[count] = &donations[count];
	 }
		
		 // Sort the elements of the array of pointers.
		arrSelectSort(arr, numDon);

		// Display the donations using the array of pointers. This
		// will display them in sorted order.
		cout << "The donations, sorted in descending order are: \n";
		showArrPtr(arr, numDon);
		// Display the donations in their original order.
		cout << "The donations, in their original order are: \n";
		showArray(donations, numDon);
		//delete array
		delete []donations;
return 0; 
}
//****************************************************************
// Definition of function arrSelectSort. *
// This function performs an ascending order selection sort on *
// arr, which is an array of pointers. Each element of array *
// points to an element of a second array. After the sort, *
// arr will point to the elements of the second array in *
// ascending order. *
//****************************************************************

void arrSelectSort(int *arr[], int numDon)
{
	int startScan, maxIndex;
	int *maxElem;
	for (startScan = 0; startScan < (numDon - 1); startScan++)
		{
		maxIndex = startScan;
		maxElem = arr[startScan];
		for (int index = startScan + 1; index < numDon; index++)
			{
				if (*(arr[index]) > *maxElem)
				{
					maxElem = arr[index];
				maxIndex = index;
				}
			}
		arr[maxIndex] = arr[startScan];
		arr[startScan] = maxElem;
		}
	}

//***********************************************************
// Definition of function showArray. *
// This function displays the contents of arr. size is the *
// number of elements. *
//***********************************************************
void showArray(const int arr[], int numDon)
{
	for (int count = 0; count < numDon; count++)
		cout << arr[count] << " ";
		cout << endl;
	}
//***************************************************************
// Definition of function showArrPtr. *
// This function displays the contents of the array pointed to *
// by arr. size is the number of elements. *
//***************************************************************
void showArrPtr(int *arr[], int numDon)
{
	for (int count = 0; count < numDon; count++)
		cout << *(arr[count]) << " ";
		cout << endl;
}