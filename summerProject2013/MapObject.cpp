
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

bool MapObject::getMovementBlocking()
{
	return movementBlocking;
}
bool MapObject::getMovementHampering()
{
	return movementHampering;
}

