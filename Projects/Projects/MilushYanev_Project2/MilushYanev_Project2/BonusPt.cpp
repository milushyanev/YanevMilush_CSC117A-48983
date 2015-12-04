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
	cout << "Enter a number and if you guess it right, ";
	cout << "you will get MegaBonus, else you will earn ";
	cout << "some bonus points for participating..." << endl;
	cout << "\nWhat number do you choose between 1-100? :>";
	//call function to declare a variable
	info.setNumber();
	//randomization to check with number entered
	srand((unsigned)time(0));

	//number must be from 0-100
	int move = (rand() % 100) + 1;

	//show number
	cout << "\nThe random number was " << move << endl;
	// call function with number selected, 
	//if == to choice, call big bonus points
	if (move == info.getNumber()){

		BonScore = info.getMBonus();
		cout << "AMAZING!!! You have earned Mega Bonus" << endl;
		cout << "\nBonus health you have earned is: " << BonScore << endl;
	}
	//else if statement to determine the amount of bonus
	else if (move > 20 && move<50){
		BonScore = info.getBonus() * 4;
		cout << "\nBonus health you have earned is: " << BonScore << "\n" << endl;
	}
	else if (move>50 && move < 80){
		BonScore = info.getBonus() * 5;
		cout << "\nBonus health you have earned is: " << BonScore << "\n" << endl;
	}
	else if (move>80 && move < 100){
		BonScore = info.getBonus() * 6;
		cout << "\nBonus health you have earned is: " << BonScore << "\n" << endl;
	}

	else if (move>0 && move < 20){
		BonScore = info.getBonus() * 7;
		cout << "\nBonus health you have earned is: " << BonScore << "\n" << endl;
	}
	//return BonScore
	return BonScore;
}
int Bonus::AI_Bns()
{
	int BonScore;
	Bonus info;

	//declare two variables, to compare later on
	int move1, move;
	//call randomization to generate number
	srand((unsigned)time(0));
	{
		//find out first random variable
		move1 = (rand() % 100) + 1;
		cout << "\nRandom number 1 for AI is:> " << move1 << endl;
	}
	//find out second value, to determine bonus points
	move = (rand() % 100) + 1;
	cout << "\nRandom number 2 for AI is:> " << move << endl;

	//if num1=num2 give MegaBonus
	if (move1 == move){

		//score is called from getMBonus()
		BonScore = info.getMBonus();
		cout << "AMAZING!!! AI have earned Mega Bonus" << endl;
		cout << "\nBonus health AI have earned is: " << BonScore << endl;
	}
	//else determine Bonus score upon num2
	else if (move > 20 && move<50){
		BonScore = info.getBonus() * 4;
		cout << "\nBonus health AI have earned is: " << BonScore << "\n" << endl;
	}
	else if (move>50 && move < 80){
		BonScore = info.getBonus() * 5;
		cout << "\nBonus health AI have earned is: " << BonScore << "\n" << endl;
	}
	else if (move>80 && move < 100){
		BonScore = info.getBonus() * 6;
		cout << "\nBonus health AI have earned is: " << BonScore << "\n" << endl;
	}

	else if (move>0 && move < 20){
		BonScore = info.getBonus() * 7;
		cout << "\nBonus health AI have earned is: " << BonScore << "\n" << endl;
	}
	//return BonScore
	return BonScore;
}