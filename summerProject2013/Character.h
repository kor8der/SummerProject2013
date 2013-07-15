#ifndef CHARACTER_H

#define CHARACTER_H

#include "includes.h"

class Character: public GameObject
{
protected:
	static const int MAXITEMS = 5;
	int strength;
	int toughness;
	int agility;
	int intelligence;
	int perception;
	int will;
	float damageModifier;
	float dodgeChance;
	float hitChance;
	facingDirection facing;
	int sightRadius;
	GameItem characterItems[MAXITEMS];
	int numberOfItems;

public:
	Character();
	Character(int str, int tou, int agil, int intel, int per, int wil);
	bool updateSecondary();
	bool calculateCarryingCapacity();
	bool updateDamageModifier();
	bool updateHitPoints();
	bool updateDodgeChance();
	bool updateHitChance();
	bool addItem(GameItem* newItem);
	bool inventoryIsFull();
	bool getHasItems();
	GameItem removeItem();
	
	//Character operator = (Character * temp);

	bool setFacing(facingDirection newFacing);
	int getStr() const;
	int getTou() const;
	int getAgi() const;
	int getInt() const;
	int getPer() const;
	int getWill() const;
	facingDirection getFacing()const;
	int getSightRadius() const;
	
	
};


#endif