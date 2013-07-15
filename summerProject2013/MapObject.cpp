
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

	items = NULL;

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