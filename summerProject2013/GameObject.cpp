#include "includes.h"

GameObject::GameObject()
{

}

int GameObject::getXPosition()
{
	return mapX;
}

int GameObject::getYPosition()
{
	return mapY;
}

bool GameObject::setPosition(int xPos, int yPos)
{
	mapX = xPos;
	mapY = yPos;
	return true;
}