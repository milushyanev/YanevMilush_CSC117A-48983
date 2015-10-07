/******************************************************************************/
/******************************  Homework 12.11 ********************************
********************************************************************************
00000000011111111112222222222333333333344444444445555555555666666666677777777778
12345678901234567890123456789012345678901234567890123456789012345678901234567890
/******************************************************************************/

#include <iostream>
#include <iomanip>
using namespace std;

//User Libraries

//Global Constants
void getQ(int);
struct CorpData {
        float Quarter[4], total, average;
        string Division;

        CorpData(string a){
        Division = a;
    }

        int setQ(int qtr, float f) {
            if (f > 0)
                        {
                Quarter[qtr] = f;
                return 1;
            }
        return 0;
    }
void getQ(int qtr){
//using double because total is not define and it will probably be more than 7 digits
                double total=0.0;

                for(int m = 0; m < 4; m++){
                        total = total + Quarter[m];
                        average = total / 4;
                }
                cout << "Annual Total : " << total << endl;
                cout << "Annual Average : " << average << endl;
        }
};
//main function
int main (int argc, char * const argv[])
{
    CorpData **Datapoint;
    Datapoint = new CorpData *[4];
    double num;
		//string for Q4
        string Division_name[4] = {"North","South","East","West"};

    for (int i = 0; i < 4; i++)
        {
        cout << endl;
		//creating a dynamic array to hold data
                Datapoint[i] = new CorpData(Division_name[i]);
				//for loop for numbers in four quarters
                for (int q = 0; q < 4; q++)
                {
            do
                        {
                cout << "Division: "<< Datapoint[i]->Division << endl << "Enter sales for quarter: "<< q+1 << ": ";
                cin >> num;
            } while (!Datapoint[i]->setQ(q,num));
        }
    }cout << endl;
		//for loop to determine numbers
        for (int j = 0; j < 4; j++){
                cout << Datapoint[j]->Division << endl;
                Datapoint[j]->getQ(j);
        }


        cout << endl;
    return 0;
}
