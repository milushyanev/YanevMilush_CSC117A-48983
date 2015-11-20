#ifndef ACTOR_H
#define	ACTOR_H

struct Actor
{
	int attack;
	int health;
	string fullName;
	string classSelected;
	int energy;
	
};
Actor ** load();
void startMenu();
void gameManager();
void startOption(string &fullName, string &classSelected, int &health, int &attack);
void save(string fullName, string classSelected, int health, int attack);
void playerAttack(Actor &target, Actor &player);
void enemyAttack(Actor &player, Actor &enemy);
void heal(Actor &player);
void smack(Actor &player);
bool block(Actor &player);
bool battle(Actor &player, Actor &enemy);

#endif 
