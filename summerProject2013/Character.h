
/*
 * FILENAME.cpp
 *
 * 
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 *
 */
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