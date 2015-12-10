#ifndef GameDate_H
#define GameDate_H

class GameDate
{
private:

	//initialize variables
	//*day as pointer to create copy constructor
	int day,
		month,
		year;

public:

	//constructor
	GameDate();

	//copy constructor
	GameDate(const GameDate &obj);

	//desctructor
	~GameDate();

	//create class functions
	void setMonth(int);
	void setDay(int);
	void setYear(int);

	//using static members
	static void MDY(GameDate *);

	//functuions to get data and print
	int getDay();
	int getMonth();
	int getYear();
	void print();

};


#endif  