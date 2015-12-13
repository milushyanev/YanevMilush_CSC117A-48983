#ifndef ACTOR_H
#define	ACTOR_H

#include "BonusPt.h"
#include "GameDate.h"

struct Actor
{
	int attack;
	int health;
	string fullName;
	string classSelected;
	int energy;
};
void load(GameDate &date,Actor &player, Actor &enemy);
void startMenu();
void gameManager();
void startOption(string &fullName, string &classSelected, int &health, int &attack);
void save(GameDate &date, string fullName, string classSelected, int health, int attack);
void playerAttack(Actor &target, Actor &player);
void enemyAttack(Actor &player, Actor &enemy);
void heal(Actor &player);
void smack(Actor &player);
bool block(Actor &player);
bool battle(Actor &player, Actor &enemy);
void CRTR();

#endif 