
#include"includes.h"

MapObject::MapObject()
{
}

MapObject::MapObject(bool block, bool rest, int posX, int posY)
{
	blocking = block;
	restrictive = rest;
	mapX = posX;
	mapY = posY;
	screenX = 32*mapX;
	screenY = 32*mapY;
	sizeX = 32;
	sizeY = 32;


	if (blocking)
	{
		loadTexture("img/wallSquare.png");
		//loadTexture("img/testImg.gif");
	}
	else if (restrictive)
	{
		loadTexture("img/restrictiveSquare.png");
	}
	else 
	{
		loadTexture("img/floorSquare.png");
		//loadTexture("img/testImg.gif");
	}
}


bool MapObject::setScreenPosition(int xOffset, int yOffset)
{
	screenX = (mapX-xOffset)*32;
	screenY = (mapY-yOffset)*32;
	objectSprite.setPosition(screenX, screenY);
	return true;
}

bool MapObject::getBlocking()
{
	return blocking;
}
bool MapObject::getRestrictive()
{
	return restrictive;
}

