/******************************************************************************/
/******************************  Homework 12.8 *********************************
********************************************************************************
00000000011111111112222222222333333333344444444445555555555666666666677777777778
12345678901234567890123456789012345678901234567890123456789012345678901234567890
/******************************************************************************/

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <iomanip>
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes
void numWords(char []);
void average(char []);
//Begin Execution
int main(int argc, char** argv) {
    //Declare variables and array
    const int SIZE=51;
    char word[SIZE];
    //Show User
    cout<<"Enter a string to calculate number of words and average letters "<<endl;
    cout<<"The string has to be less than "<<(SIZE-1)<<" characters "<<endl;
    cin.getline(word,SIZE);
    //Call functions show results
    numWords(word);
    average(word);
    //Exit Program
    return 0;
}
//Function will calculate the number of letters
void average(char str[]){
    //Declare variables
    int count=0;
    int w=0;
    float average;
    //Loop to count letter number
    for(int i=0;i<str[i];i++){
        if(isalpha(str[i])){
            count++;
         //loop to calculate number of words
        }for(int j=0;j<str[j];j++){
            if(str[j]==' '){
                w++;
            }
        }
        average=(w+1)/(count+1);

    }
    //Show User results with setprecision set to two decimals
    cout<<fixed<<setprecision(2);
    cout<<"The average number of letters is : "<<average<<endl;
}
//Function will calculate the numbers of words 
void numWords(char str[]){
    //Declare variables
    int words=0;
    //Loop to count the number of words in particular string
    for(int i=0;i<str[i];i++){
        if(str[i]==' '){
            words++;
        }
    }
    //Show User the Results
    cout<<"There are : "<<(words+1)<<" words in the string entered. "<<endl;

}
