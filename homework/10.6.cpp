/******************************************************************************/
/******************************  Homework 10.6 *********************************
********************************************************************************
00000000011111111112222222222333333333344444444445555555555666666666677777777778
12345678901234567890123456789012345678901234567890123456789012345678901234567890
/******************************************************************************/


#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <cstring>
#include <string>
using namespace std;

//function prototypes
int vowels(char *);
int consonant(char *);

int main(int argc, char** argv) {
    //declaring variables
    int SIZE=51;
    char arr[SIZE];
    //creating of string
    cout<<" Enter a string to display the vowels and consonants of "<<endl;
    cout<<"The string must not be more than"<<(SIZE-1)<<" characters"<<endl;
    cin.getline(arr,SIZE);
    //Display Results
    vowels(arr);
    consonant(arr);


    return 0;
}
//consonants counting
int consonant(char *a){
    //Declare variables
    int count=0;
    //Loop to count consonants
    for(int i=0;i<a[i];i++){
        a[i]=toupper(a[i]);
        switch(a[i]){
            case 'A':
            case 'E':
            case 'I':
            case 'O':
            case 'U':
            case ' ':
            case '.':
            case ',':
            case '?':
            case '!':
            case '-':
                break;
            default:
                count++;
                cout<<endl;
                break;
        }
    }
    //outcome of function, consonants counting
    cout<<"There are "<<(count)<<" consonants the string you've entered."<<endl;
    //return consonants
    return count;
}
//count vowels
int vowels(char *a){
    //Declare Variables
    int count=0;
    //loop to find vowels
    for(int i=0;i<a[i];i++){
        if(a[i]=='a'
           || a[i]=='e'
           || a[i]=='i'
           || a[i]=='o'
           || a[i]=='u'
           || a[i]=='A'
           || a[i]=='E'
           || a[i]=='I'
           || a[i]=='O'
           || a[i]=='U')count++;

    }
    //outcome of function, vowels counting
    cout<<"There are "<<(count)<<" vowels in the string you've entered"<<endl;
    //Exit
    return count;
}
