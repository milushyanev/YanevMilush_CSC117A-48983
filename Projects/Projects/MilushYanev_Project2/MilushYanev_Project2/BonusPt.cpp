#include<iostream>
#include <ctime>
#include<cstdlib>
#include "BonusPt.h"

using namespace std;

//overloading constructor
Bonus::Bonus()
	{
		number = 0;
		chance = 8;
		mBonus = 15;
	
	}
//call destructor
Bonus::~Bonus()
{
	
}
int Bonus::BonH(){

	int BonScore;
	Bonus info;
	//need a menu to validate choice is in the right range
	cout << "What number do you choose between 1-100? :>";
	//call function to declare a variable
	info.setNumber();
	//randomization to check with number entered
	srand((unsigned)time(0));

	//number must be from 0-100
	int move = (rand() % 100) + 1;

	//show number
	cout << move;
	// call function with number selected, 
	//if == to choice, call big bonus points
	if (move == info.getNumber()){

		BonScore = info.getMBonus();
		cout << "\nBonus health you have earned is: " << BonScore << endl;

	}
	//else if statement to determine the amount of bonus
	else if (move > 20 && move<50){
		BonScore = info.getBonus() * 4;
		cout << "\nBonus health you have earned is: " << BonScore << endl;
	}
	else if (move>50 && move < 80){
		BonScore = info.getBonus() * 5;
		cout << "\nBonus health you have earned is: " << BonScore << endl;
	}
	else if (move>80 && move < 100){
		BonScore = info.getBonus() * 6;
		cout << "\nBonus health you have earned is: " << BonScore << endl;
	}

	else if (move>0 && move < 20){
		BonScore = info.getBonus() * 7;
		cout << "\nBonus health you have earned is: " << BonScore << endl;
	}
	//return BonScore
	return BonScore;
}