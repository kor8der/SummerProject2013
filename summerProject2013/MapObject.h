
/*
 * MapObject.h
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
#ifndef MAP_OBJECT_H

#define MAP_OBJECT_H

#include "includes.h"

class MapObject: public GameObject
{
protected:
	static const int MAXITEMS = 25;
	bool movementBlocking;
	bool visionBlocking;
	bool movementHampering;
	GameItem items[MAXITEMS];
	int numberOfItems;
public:
	MapObject();
	MapObject(bool block, bool visBlock, bool rest, int posX, int posY);
	bool setScreenPosition(int xOffset, int yOffset);
	bool getMovementBlocking();
	bool getMovementHampering();
	bool getIsSeeThrough();
	bool getHasItems();
	GameItem* removeItem();
	bool getIsFull();
	GameItem *addItem(GameItem newItem);
	bool	drawSelf(sf::RenderWindow *target);

};



#endif