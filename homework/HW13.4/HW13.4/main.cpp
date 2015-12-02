/*
Milush Yanev
Chapter 13, Problem 4

*/

#include <iostream>
#include<string>
using namespace std;

class Info{
private:
	std::string name, address;
	long long int age, number; //Reason for long long int is to be able to hold 10 digits
public:
	void getinfo();
	std::string getname(){ return name; };
	std::string getaddress(){ return address; };
	int getage(){ return age; };
	int getnumber(){ return number; };
};

int main(int argc, char** argv) {
	Info mystuff, friend1, friend2;
	int choice = 1;
	cout << "Hello!" << endl;
	cout << "Who's info do you want to store?" << endl;
	while (choice>0 && choice<4){
		cout << "1. You\n2. Friend 1\n3. Friend 2" << endl;
		cin >> choice;
		cin.ignore();
		switch (choice){
		case 1:
			mystuff.getinfo();
			break;
		case 2:
			friend1.getinfo();
			break;
		case 3:
			friend2.getinfo();
			break;
		default:
			choice = 4;
			break;
		}
		cout << "Who's information do you want to enter next?" << endl;
		cout << "If done, enter anything other than 1,2, or 3." << endl;
	}
	cout << endl << "Here you are:" << endl;
	cout << "\tName: " << mystuff.getname() << endl << "\tAddress: " << mystuff.getaddress() << endl;
	cout << "\tAge: " << mystuff.getage() << endl << "\tPhone Number: " << mystuff.getnumber() << endl;
	cout << endl << "Here is Friend 1:" << endl;
	cout << "\tName: " << friend1.getname() << endl << "\tAddress: " << friend1.getaddress() << endl;
	cout << "\tAge: " << friend1.getage() << endl << "\tPhone Number: " << friend1.getnumber() << endl;
	cout << endl << "Here is Friend 2:" << endl;
	cout << "\tName: " << friend2.getname() << endl << "\tAddress: " << friend2.getaddress() << endl;
	cout << "\tAge: " << friend2.getage() << endl << "\tPhone Number: " << friend2.getnumber() << endl;
	return 0;
}

void Info::getinfo(){
	cout << "Enter name." << endl;
	getline(cin, name);
	cout << "Enter age." << endl;
	cin >> age;
	cin.ignore();
	cout << "Enter address." << endl;
	getline(cin, address);
	cout << "Enter phone number." << endl;
	cin >> number;
}