#ifndef CHARACTER_H

#define CHARACTER_H

#include "includes.h"

class Character: protected ScreenObject
{
protected:
	int mapX;
	int mapY;
	int strength;
	int toughness;
	int agility;
	int intelligence;
	int perception;
	int will;
	float damageModifier;
	int hitPoints;
	float dodgeChance;
	float hitChance;
	
public:
	Character();
	Character(int str, int tou, int agil, int intel, int per, int wil);
	bool updateSecondary();
	bool calculateCarryingCapacity();
	bool updateDamageModifier();
	bool updateHitPoints();
	bool updateDodgeChance();
	bool updateHitChance();
	

};


#endif