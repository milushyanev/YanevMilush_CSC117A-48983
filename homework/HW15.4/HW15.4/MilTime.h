#ifndef MILTIME_H
#define MILTIME_H

#include "Time.h"
#include <string>

class MilTime : public Time
{
public:
	MilTime();
	~MilTime();
	void setTime(int, int);
	string getStandHr() const;
	int getHour() const { return milHours; }

private:
	int milHours;
	int milSeconds;
};

#endif