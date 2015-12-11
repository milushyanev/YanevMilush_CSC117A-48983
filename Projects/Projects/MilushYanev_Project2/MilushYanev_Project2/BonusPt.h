#ifndef BONUSPT_H
#define	BONUSPT_H

#include<iostream>
using namespace std;

//declare class
class Bonus
{
private:
	int number, chance, mBonus;
public:
	//constructor
	Bonus();

	//desctructor
	~Bonus();

	//static member, chapter 14.1
	static int BonH();
	static int AI_Bns();
	void setNumber() { cin >> number; };
	int getNumber()const{ return number; };
	int getBonus()const{ return chance; };
	int getMBonus() const{ return chance*mBonus; };
};
#endif 
