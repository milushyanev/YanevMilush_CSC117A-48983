/******************************************************************************/
/******************************  Homework 10.6 *********************************
********************************************************************************
00000000011111111112222222222333333333344444444445555555555666666666677777777778
12345678901234567890123456789012345678901234567890123456789012345678901234567890
/******************************************************************************/

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <ctime>
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes
int *filAry(int);
void destroy(int *);
//void prntAry(int*,int);
void arrayToFile(int *,int);
void fileToArr(int *,int);
/*
 *
 */
//Begin Execution
int main(int argc, char** argv) {
    //Declare Variables, Array, fstream objects, and pointer
    int SIZE=0;
    int arr[SIZE];
    int *ptr=NULL;
    fstream file;
    //set random number seed
    srand(static_cast<unsigned int>(time(0)));
    //Prompt User
    cout<<"Enter the size of your array"<<endl;
    cin>>SIZE;
    //Call function
    ptr=filAry(SIZE);
    arrayToFile(ptr,SIZE);
    fileToArr(ptr,SIZE);
    //prntAry(ptr,SIZE);
    //Deallocate memory
    destroy(ptr);
    //Exit Program
    return 0;
}
//read array from file
void fileToArr(int *arr,int size){
    //Declare objects
    fstream inFile;
    //open file
    inFile.open("outFile.txt",ios::in|ios::binary);
    //Read in from file
    for(int i=0;i<size;i++){
    inFile.read(reinterpret_cast<char *>(arr[i]),sizeof(arr));
    }
    //Display array contents
    for(int j=0;j<size;j++){
        cout<<arr[j]<<" "<<endl;
        cout<<endl;
    }
    //Close the file
    inFile.close();
}
//write array to file
void arrayToFile(int *arr,int size){
    //Declare objects
    fstream outFile;
    //Open file
    outFile.open("outfile.txt",ios::out|ios::binary);
    //Write to file
    for(int i=0;i<size;i++){
    outFile.write(reinterpret_cast<char *>(arr[i]),sizeof(arr));
    }
    //Close file
    outFile.close();
}
/*
//Print the array
void prntAry(int *arr,int size){
    cout<<endl;
    for(int i=0;i<size;i++){
        cout<<arr[i]<<endl;
    }

}
 */
//Destroy dynamic array
void destroy(int *arr){
    delete []arr;
    arr=NULL;
}
//Fill Array
int *filAry(int size){
    //Declare pointer
    int *ptr=NULL;
    //Allocate memory
    ptr=new int[size];
    //Loop to fill array
    for(int i=0;i<size;i++){
        ptr[i]=rand()%90+10;
    }
    return ptr;
}
