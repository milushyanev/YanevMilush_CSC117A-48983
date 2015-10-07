/******************************************************************************/
/******************************  Homework 12.7 *********************************
********************************************************************************
00000000011111111112222222222333333333344444444445555555555666666666677777777778
12345678901234567890123456789012345678901234567890123456789012345678901234567890
/******************************************************************************/


#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <cctype>
#include <iomanip>
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes
/*
 *
 */
int main(int argc, char** argv) {
    //Declare Variables
    int SIZE=51;
    char line;
    char fName[SIZE];
    char fName2[SIZE];
    //Create file stream objects
    ofstream outFile;
    fstream inFile;
    //Show User for filenames
    cout<<"Enter the filename for the first file."<<endl;
    cin>>fName;
    cout<<"Enter the filename for the second file."<<endl;
    cin>>fName2;
    cout<<"Enter a string to write to first file"<<endl;
    cin>>line;
    //Open file for input
    inFile.open(fName,ios::in|ios::out|ios::app);
    //Open file for output
    outFile.open(fName2,ios::out);
    //Validation
    if(!inFile){
        cout<<"The input file was not opened and encountered and error. "<<endl;
    }
    if(!outFile){
        cout<<"The output file was not opened and encountered an error."<<endl;
    }
    //write to first file
    cout<<"Writing string to file 1"<<endl;
    cout<<"...done."<<endl;
    inFile<<line<<endl;
    //send all characters to lowercase and write them to second file
    inFile.get(line);
    while(!inFile.eof()){
        outFile.put(tolower(line));
        inFile.get(line);
    }
    //Prompt User
    cout<<"The files have been converted"<<endl;
    //Close the files
    inFile.close();
    outFile.close();
     
    return 0;
}
