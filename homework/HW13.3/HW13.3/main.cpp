/*
Milush Yanev
Chapter13, PRoblem3 
*/

#include <iostream>
#include<string>
using namespace std;

class Car{
private:
	int year, speed;
	std::string make;
public:
	Car();
	int getyear(){ return year; };
	int getspeed(){ return speed; };
	std::string getmake(){ return make; };
	void accelerate(){ speed = speed + 5; };
	void brake(){ speed = speed - 5; };
};

int main(int argc, char** argv) {
	Car info;
	cout << endl << "Car: " << info.getyear() << " " << info.getmake() << endl;
	cout << "Accerlating..." << endl;
	for (int i = 0; i<5; i++){
		info.accelerate();
		cout << info.getspeed() << endl;
	}
	cout << "Braking..." << endl;
	for (int i = 0; i<5; i++){
		info.brake();
		cout << info.getspeed() << endl;
	}
	return 0;
}

Car::Car(){
	speed = 0;
	cout << "Enter the year model of your car." << endl;
	cin >> year;
	cin.ignore();
	cout << "Enter the make of your car." << endl;
	getline(cin, make);
}