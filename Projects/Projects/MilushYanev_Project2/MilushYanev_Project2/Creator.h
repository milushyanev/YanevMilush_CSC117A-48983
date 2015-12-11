#ifndef CREATOR_H
#define CREATOR_H
#include <string>
#include "Developer.h"
using namespace std;

class Creator :public Developer

{
private:
	int day;
	int level;
public:
	Creator();
	~Creator();
	void setDay(int);
	void setLevel(int);
	int getDay();
	int getLevel();
};
#endif