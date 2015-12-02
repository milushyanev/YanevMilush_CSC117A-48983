/*
Milush Yanev
Chapter 13, Problem 8
*/

#include <iostream>
using namespace std;

class Circle{
private:
	float radius, pi;
public:
	Circle(){ radius = 0.0, pi = 3.14159; };
	void setRadius(){ cin >> radius; };
	float getRadius()const{ return radius; };
	float getArea()const{ return pi*radius*radius; };
	float getDiameter()const{ return radius * 2; };
	float getCircum()const{ return 2 * pi*radius; };
};

int main(int argc, char** argv) {
	Circle info;
	cout << "What is the radius of your circle?" << endl;
	info.setRadius();
	cout << endl << "Circle:\n\tRadius: " << info.getRadius() << endl;
	cout << "\tDiameter: " << info.getDiameter() << "\n\tCircumference: " << info.getCircum() << endl;
	cout << "\tArea: " << info.getArea() << endl;
	return 0;
}