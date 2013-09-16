
/*
 * MapObject.cpp
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

#include"includes.h"

MapObject::MapObject()
{
	
}

MapObject::MapObject(bool block, bool visBlock, bool rest, int posX, int posY)
{
	movementBlocking = block;
	movementHampering = rest;
	visionBlocking = visBlock; 
	mapX = posX;
	mapY = posY;
	screenX = 32*mapX;
	screenY = 32*mapY;
	sizeX = 32;
	sizeY = 32;


	if (movementBlocking)
	{
		if (visionBlocking)
		{
			loadTexture("img/wallSquare.png");
		}

		else if (!visionBlocking)
		{
			loadTexture("img/glassWallSquare.png");
		}

		//loadTexture("img/testImg.gif");
	}

	else if (movementHampering)
	{
		loadTexture("img/restrictiveSquare.png");
	}

	else
	{
		if (visionBlocking)
		{
			loadTexture("img/doorSquare.png");
		}

		else if(!visionBlocking)
		{
			loadTexture("img/floorSquare.png");
		}
		//loadTexture("img/testImg.gif");
	}

	numberOfItems = 10;

	items[numberOfItems].setPosition(mapX, mapY);

}


bool MapObject::setScreenPosition(int xOffset, int yOffset)
{
	screenX = (mapX-xOffset)*32;
	screenY = (mapY-yOffset)*32;
	objectSprite.setPosition(screenX, screenY);

	for (int i; i<=numberOfItems; i++)
	{
		items[i].adjustPosition((mapX-xOffset)*32, (mapY-yOffset)*32);
	}

	return true;
}

bool MapObject::getMovementBlocking()
{
	return movementBlocking;
}
bool MapObject::getMovementHampering()
{
	return movementHampering;
}

/*this function will be expanded to include every way it could block line of sight on, including objects on the tile*/
bool MapObject::getIsSeeThrough()
{
	if (visionBlocking)
	{
		return false;
	}
	else 
	{
		return true;
	}
}

bool MapObject::getHasItems()
{
	return numberOfItems;
}

GameItem * MapObject::removeItem()
{
	numberOfItems--;
	return &items[numberOfItems+1];
}

bool MapObject::getIsFull()
{
	if (numberOfItems >= MAXITEMS)
	{
		return true;
	}
	
	return false;
}

GameItem *MapObject::addItem(GameItem newItem)
{
	if (numberOfItems >= MAXITEMS-1)
	{
		GameItem tempItem;
		srand(time(NULL));
		int shift = rand()%numberOfItems;
		tempItem = items[shift];
		items[shift] = newItem;

		return &tempItem;
	}
	else 
	{
		numberOfItems++;
		items[numberOfItems];
		return NULL;
	}
}

bool MapObject::drawSelf(sf::RenderWindow *target)
{
	target->draw(objectSprite);
	
	items[numberOfItems].drawSelf(target);

	return true;
}