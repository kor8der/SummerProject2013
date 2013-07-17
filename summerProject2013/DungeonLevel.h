
/*
 * DungeonLevel.h
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
#ifndef DUNGEON_LEVEL_H

#define DUNGEON_LEVEL_H

#include "includes.h"

class DungeonLevel
{
protected:
	static const int MAPSIZE = 50;
	MapObject* map[MAPSIZE][MAPSIZE];
	Character * playerChar;
	int octantMultipliers[4][8];
public:
	DungeonLevel();
	DungeonLevel(Character * tempChar);
	void drawDungeon(sf::RenderWindow *target);
	void adjustMap();
	MapObject *getSquare(int xPos, int yPos);
	bool shadowCasting(int startRow, int radius, double startAngle, double endAngle, int octant, sf::RenderWindow * target);
};

#endif