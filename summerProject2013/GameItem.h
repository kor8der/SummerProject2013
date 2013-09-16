
/*
 * GameItem.h
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
#ifndef GAME_ITEM_H

#define GAME_ITEM_H

#include "includes.h"

class GameItem :public GameObject
{
protected:
	int charges; 
	int weight; //the weight of the item in Hectograms	
	int value; //the value of the item in gold peices 
	int minDamage;
	int maxDamage;
	int critMultiplier;

public:
	GameItem();
	bool adjustPosition(int newScreenX, int newScreenY);
};

#endif