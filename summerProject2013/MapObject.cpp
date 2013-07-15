
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

	numberOfItems = 0;

}


bool MapObject::setScreenPosition(int xOffset, int yOffset)
{
	screenX = (mapX-xOffset)*32;
	screenY = (mapY-yOffset)*32;
	objectSprite.setPosition(screenX, screenY);
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
	