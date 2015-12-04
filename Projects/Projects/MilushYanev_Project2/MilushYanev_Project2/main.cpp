/******************************************************************************/
/**********************Project number two.Continue PJ one **********************
********************************************************************************
00000000011111111112222222222333333333344444444445555555555666666666677777777778
12345678901234567890123456789012345678901234567890123456789012345678901234567890
/******************************************************************************/

#include <iostream>
#include <fstream>
#include <ctime>
#include<string>
#include <Windows.h>

using namespace std;

#include "Actor.h"
#include "BonusPt.h"

int main()
{	
	
	//Function startMenu will exist only in main().
	startMenu();

	return 0;
}
void startMenu()
{
	cout << "----------------------------------------------------" << endl;
	cout << "                   War of Machines                  " << endl;
	cout << "----------------------------------------------------" << endl;

	cout << "1. Start New Game " << endl;
	cout << "2. Quit" << endl;
	
	//call gameManager() function.
	gameManager();

}
void gameManager()
{
	//Initialize variables and character.
	Actor  **result;
	string classSelected = " ",
		   fullName = " ";
	int    health=0,
		   attack=0;
	char   n,
		   j;

	cin >> n;
	//While loop to make sure that entered choice is correct.
	while (n != '1' && n != '2')
	{
		cout << "Invalid entry. Please enter either '1' or '2': ";
		cin >> n;
	}
	if (n == '1')
	{
		cout << "If you choose to continue,";
		cout << "any previous game will be overwrite!";
		cout << "Press 1 to start a new game";
		cout << "or 2 to continue with previous saved game" << endl;
		cin >> j;
		//While loop to make sure that entered choice is correct.
		while (j != '1' && j != '2' )
		{
			cout << "Invalid entry. Please enter either '1' or '2': ";
			cin >> j;
		}
		if (j == '1')
		{
			//Call startOption menu to pick up character.
			startOption(fullName, classSelected, health, attack);

		}
		if (j == '1' || j == '2') {
			
			//Load function if player choose to continue with saved game.
			result = load();

			Actor &player = *result[0];
			Actor &enemy = *result[1];
			cout << player.fullName << " " << player.classSelected << " ";
			cout<< player.health << " " << player.attack << endl;
			cout << enemy.fullName << " " << enemy.classSelected << " ";
			cout<< enemy.health << " " << enemy.attack << endl;

			// true = win
			if (battle(player, enemy))
				// Print an ending message indicating winner.
				cout << "\nCongratulations! You won!\n" << endl;
			else
				//Print an ending message indicating loser.
				cout << "\nSorry! Try again!\n" << endl;

			delete result[0];
			delete result[1];
			delete[] result;

			return;
		}
	} else if (n == '2') {
		//Print an ending message.
		cout << "\nGood Bye!\n" << endl;
	}
}
//Function startOption to determine character choice
void startOption(string &fullName, string &classSelected, int &health, int &attack)
{
	cout << "\nChoose a player" << endl;
	cout << "\n1. OptimusPrime ( 785 hp, 50 damage)" << endl;
	cout << "\n2. Megatrone    ( 697 hp, 77 damage)" << endl;
	cout << "\n3. Bumblebee    ( 615 hp, 55 damage)" << endl;
	cout << "\n4. Starscream   ( 615 hp, 55 damage)" << endl;
	cout << "\nChoice:> ";
	//Create integer to stand for character selection.
	char m;
	cin >> m;
	//While loop to make sure that entered choice is correct.
	while (m != '1' && m != '2' && m != '3' && m != '4')
	{
		cout << "Invalid entry. Please enter either '1' or '2' or '3' or '4': ";
		cin >> m;
	}

	if (m == '1')
	{
		//Character 1.
		cout << "\nCongratulations You Have Chosen  OptimusPrime" << endl;
		classSelected = "OptimusPrime";
		health = 785;
		attack = 63;


	}
	else if (m == '2')
	{
		//Character 2.
		cout << "\nCongratulations You Have Chosen Megatrone" << endl;
		classSelected = "Megatrone";
		health = 697;
		attack = 70;
	}
	else if (m == '3')
	{
		//Character 3.
		cout << "\nCongratulations You Have Chosen Bumblebee" << endl;
		classSelected = "Bumblebee";
		health = 715;
		attack = 57;
	}
	else if (m == '4')
	{
		//Character 4.
		cout << "\nCongratulations You Have Chosen Starscream" << endl;
		classSelected = "Starscream";
		health = 705;
		attack = 65;
	}
	cout << "\nWhat is your name? " << endl;
	//Ignore previous Entries.
	cin.ignore();
	
	//Enter the name you have chosen.
	cout << "\nName: "; getline(cin, fullName);
	//Print your name,hero with its stats.
	cout << "\nWelcome to War Of Machines, " << fullName << " ,you have chosen ";
	cout << classSelected << " with " << health << endl;
	cout<< " hp and damage " << attack;
	cout<< "!\n" << endl;
	//Call save function to save previous entries.
	save(fullName, classSelected, health, attack);
}
//Function save to save entries in the beginning of the game.
void save(string fullName, string classSelected, int health, int attack)
{
	char choice;
	//Write file.
	ofstream writeFile;
	cout << "Saving now will overwrite any previously saved data\n";
	cout<< "Do you want to save Y or N" << endl;
	cin >> choice;
	if (choice = 'Y' || 'y')
	{
		//Write file in playerInfo.bin, which will occur in folder of game.
		//Use binary save file.
		writeFile.open("playerInfo.bin", ofstream::binary);
		//Declare the length using characters,which reffer to strings.
		int length = fullName.length();
		//Find how many characters are in string (+1).
		writeFile.write((char *)&length, sizeof(int));
		//Write size of characters.
		writeFile.write(fullName.c_str(), length);

		length = classSelected.length();
		//Find how many characters are in string (+1).
		writeFile.write((char *)&length, sizeof(int));
		//Write size of characters.
		writeFile.write(classSelected.c_str(), length);
		
		//Write health and attack as character pointers, using size.
		writeFile.write((char *) & health, sizeof(health));
		writeFile.write((char *) & attack, sizeof(attack));

		//writeFile << fullName << classSelected << health << attack;
		cout << "The game has been saved\n";
		//Close writen file.
		writeFile.close();

	}
	else
	{
		//If enter is N, skip writing, end function.
		exit(0);
	}

}
//Function load to load previous save or external file.
//Pass Struct as an array of pointers.
Actor ** load()
{
	//Create an array of Struct and pass by pointer.
	Actor **result = new Actor *[2];
	//result[0] reffers to player stats.
	result[0] = new Actor;
	//result[1] refers to enemy stats.
	result[1] = new Actor;
	//Initialize pointers to references.
	Actor &player = *result[0];
	Actor &enemy = *result[1];

	ifstream readFile;
	int health;
	int attack;
	//Read playerInfo.bin from saved function.
	//You can also add you personal file to be read.
	readFile.open("playerInfo.bin", ifstream::binary);

	
	int length = 0;
	readFile.read((char *) &length, sizeof(int));
	
	//Create an array buffer as pointer. Must be +1,
	//Because it will count char(last char is 0).
	char *buffer = new char[length + 1];
	//for loop to make sure count will be length +1.
	for (int i = 0; i < length + 1; i++) 
	{ 
		buffer[i] = 0;
	}
	readFile.read(buffer, length);
	string fullName(buffer);
	//allocate memory
	delete [] buffer;

	
	readFile.read((char *)&length, sizeof(int));

	buffer = new char[length + 1];
	//for loop to make sure count will be length +1.
	for (int i = 0; i < length + 1; i++)
	{
		buffer[i] = 0;
	}
	readFile.read(buffer, length);
	string classSelected(buffer);
	//allocate memory.
	delete[] buffer;

	readFile.read((char *)& health, sizeof(int));
	readFile.read((char *)& attack, sizeof(int));
	
	player.fullName = fullName;
	player.classSelected = classSelected;
	player.health = health;
	player.attack = attack;
	player.energy = 0;
	
	//Print message.
	cout << "\nHello, " << player.fullName;
	cout<< "! You have chosen " << player.classSelected;
	cout << ", your health is " << player.health;
	cout<< ", your damage is  " << player.attack << endl;

	//Enemy is automatically set up.
	int move = ((unsigned)time(0) % 100) + 1;
	if (move <= 35)
	{
		enemy.fullName = "AI.Hard";
		enemy.attack = 60;
		enemy.health = 650;
		enemy.energy = 0;
	}
	else if (move > 35 && move <= 85)
	{
		enemy.fullName = "AI.Normal";
		enemy.attack = 50;
		enemy.health = 600;
		enemy.energy = 0;
	}
	else if (move > 85 && move <= 100)
	{
		enemy.fullName = "AI.Insane";
		enemy.attack = 70;
		enemy.health = 655;
		enemy.energy = 0;
	}
	cout << "\nYour enemy is " << enemy.fullName;
	cout<< ", with health  " << enemy.health;
	cout << ", energy is " << enemy.energy << " and damage  ";
	cout<< enemy.attack << endl;
	//Close file and continue.
	readFile.close();
	return result;
}
//Player attack. 
void playerAttack(Actor &target, Actor &player) 
{
	char choice = '0';
	int ultimateAttack;
	int move;

	cout<< "\nChoose 1 for base attack, 2 for special attack (costs 3 energy)";
	cout<<" ,3 for ultimate attack (costs 5 energy) and 4 to skip turn" << endl;
	//Use attack based from choice and do damage to target's health value.
	cin >> choice;
	//While loop to make sure that entered choice is correct.
	while (choice != '1' && choice != '2' && choice != '3' && choice != '4') 
	{
		cout << "Invalid entry. Please enter either '1' or '2' or '3' or '4': ";
		cin >> choice;
	}

	if (choice == '1')
	{
		//1 = base attack  - base attack value. 
		target.health -= player.attack;
	}
	else if (choice == '2' && player.energy >= 3)
	{
		//2 = special attack - costs 3 energy and will modify,
		//without storing the damage output i.e finalDmg = baseAttack + special.
		target.health -= (player.attack + 100);
		//Deduct energy amount per turn.
		player.energy -= 3;
	}
	else if (choice == '3' && player.energy == 5)
	{
		//3 = ultimate - Same method of modofying as above.
		//Gamble with 5 energy if this will do damage between 1-8 damage. 
		//Use rand() for this with a min and max range.
		srand((unsigned)time(0));
		move = (rand() % 8) + 1;

		if (move >= 2 && move <= 4)
		{
			ultimateAttack = 130;
		}

		else if (move == 8)
		{
			ultimateAttack = 150;

		}
		else
		{
			ultimateAttack = 100;
		}
		//Deal damage to target based from player's attack value.
		target.health -= (player.attack + ultimateAttack);
		//If successful check, deduct matching energy amount.
		player.energy -= 5;
	}
	//4 = end turn - hey, maybe you're out of energy.
	else if (choice == '4')
	{
		return;

	}
}
//Function for enemy attack moves.
void enemyAttack(Actor &target, Actor &enemy)
{	//Make the game interesting. Allow the enemy to randomly modify his damage.
	//Output each attack by allowing  baseAttack + random range from 1-5.
	int RandomAttack = 0;
	int move = ((unsigned)time(0) % 5) + 1;
	
	if (move == 1)
	{
		RandomAttack = 0;

	}
	else if (move > 1 && move <= 3 && enemy.energy >= 2)
	{
		RandomAttack = 70;
		//Deduct energy amount per turn.
		enemy.energy -= 2;
	}
	else if (move == 4 && enemy.energy == 5)
	{
		RandomAttack = 90;
		//Deduct energy amount per turn.
		enemy.energy -= 5;
	}
	else if (move == 5)
	{
		target.health = target.health;
	}
	//Deal damage to target based from enemy's attack value.
	target.health -= (enemy.attack + RandomAttack);
}
//Function to block enemy's attack.
bool block(Actor &player)
{
	if (player.classSelected == "Megatrone" || player.classSelected == "Starscream")
	{
		srand((unsigned)time(0));
		Sleep(100);
		//Return true or false based from a random chance between 1 - 10 odds.
		//You will need to choose one number as a constant in that range.
		int move = (rand() % 10) + 1; 
		//Compare the random number to that number.
		if (move == 5)
		{
			cout << "\nBlocked" << endl;
			return true;
		}
		else
		{
			return false;
		}
	}
}
void heal(Actor &player)
{	//If mage, he can have a chance to self heal at the start of the turn.
	if (player.classSelected == "OptimusPrime")
	{
		srand((unsigned)time(0));
		//The chance will be a random chance between 1 - 10 odds you will need 
		//to choose, one number as a constant in that range.
		int move = (rand() % 10) + 1;
		//Compare the random number to that number.
		if (move == 4)
		{
			cout << "\nYour character has been healed" << endl;
			//Choose an amount to heal your player and add that to his health.
			player.health += 79;
		}

	}
}
void smack(Actor &player)
{
	if (player.classSelected == "Bumblebee")
	{
		srand((unsigned)time(0));
		//The chance will be a random chance between 1 - 10 odds you will need 
		//to choose, one number as a constant in that range.
		int move = (rand() % 10) + 1;
		//Compare the random number to that number.
		if (move == 6 || move ==1)
		{
			cout << "\nYour character has gained power" << endl;
			//Choose an amount to heal your player and add that to his health.
			player.attack += 15;
			player.energy += 3;
		}
	}
}
//Function to determine Computer's turn.
void enemyTurn(Actor &target, Actor &source)
{

	//Add 1 energy per turn.
	source.energy++;
	if (source.energy < 0)
	{
		source.energy = 0;
	}

	srand((unsigned)time(0));

	//number must be from 1-10
	int move = (rand() % 10) + 1;
	if (move = 6)
	{
		source.health += Bonus::BonH();
	}

	// Randomly select an enemy action based on simple AI logic.
	//Randomize choice and use basic logic to make the game interesting.

	//If the function blocks, no need to use enemyAttack.
	if (!block(target)) // if not blocked
	{
		// Call attack function based on AI choice.
		enemyAttack(target, source);
	}
	//  - attack(actor &, actor, char ).
}
void playerTurn(Actor &target, Actor &source)
{
	//cout << "\nPLAYER ENERGY: " << source.energy << endl;
	//cout << "\nENEMY ENERGY: " << target.energy << endl;
	//energy++
	source.energy++;
	if (source.energy > 5)
	{
		source.energy = 5;
	}

	//If mage - chance to heal() at this start of turn if damaged.
	heal(source);
	srand((unsigned)time(0));

	//number must be from 1-10
	int move = (rand() % 10) + 1;
	if (move = 4)
	{
		source.health += Bonus::BonH();
	}


	

	//Grab input from player on attack choice from a menu of choices.
	//Call attack function based on player choice between 1-4.
	//Energy check, if invalid choice loop for another choice.
	playerAttack(target, source);

	// For example: attack() and pass as reference enemy as target,
	//and player as player as a read only argument.
}
//Function for battle, if true==win.
bool battle(Actor &player, Actor &enemy)
{
	int health = 0;
	int number;
	bool myTurn = false;
	//Battle starting text.
	cout << "\nLets the fun begin " << endl;
	//Coin toss to see who goes first.
	int heads = 0, tails = 0;
	//Use srand ((unsigned) time(0)); Requires <ctime>.
	srand((unsigned)time(0));
	//Use coinToss = rand() % 2.
	number = rand() % 2;
	//Heads (0) you, tails (1) enemy.
	if (number == 0)
		myTurn = true;
	else
		myTurn = false;

	//While loop that checks the enemy and player's health.
	//While it is greater than 0, keep playing. Both live.
	while (player.health > 0 && enemy.health > 0)	
	{
		//If else loop to determine player/computer(i.e.) moves.
		if (myTurn)
		{
			playerTurn(enemy, player);
			cout << "\n" << enemy.fullName << ", your health is ";
			cout<< enemy.health;
			cout<< ", and energy " << enemy.energy << endl;
		}
		else
		{
			enemyTurn(player, enemy);
			cout << "\n " << player.fullName << ", your health is ";
			cout<< player.health;
			cout<< ", and energy " << player.energy << endl;
		}
		//Turn attack system. Could be loop with iterating variable that counts 
		//from 0-1,and then resets after one.Just make sure each player gets a 
		//sequential turn.Alternate turn; if it was my turn, then it's his next.
		myTurn = (myTurn ? false : true);

	//Keep a running tally of the player and enemy's stats (i.e health& energy).
	}	
	cout << "\n " << player.fullName << ",who operates ";
	cout<< player.classSelected << ", your health is " << player.health;
	cout << ", your damage is  " << player.attack;
	cout<< ", and energy " << player.energy << endl;
	cout << "\n " << enemy.fullName << " " << ", your health is ";
	cout<< enemy.health << ", your damage is  ";
	cout<< enemy.attack << ", and energy " << enemy.energy << endl;
	// Print an ending message indicating winner.
	return (player.health >= enemy.health);
}