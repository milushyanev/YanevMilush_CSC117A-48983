#include <iostream>
#include<string>
#include "Creator.h"
using namespace std;

Creator::Creator()
{
	day = 0;
	level = 0;
}
Creator::~Creator()
{
}
void Creator::setDay(int d)
{
	day = d;
}
void Creator::setLevel(int l)
{
	level = l;
}
int Creator::getDay()
{
	return day;
}
int Creator::getLevel()
{
	return level;
}