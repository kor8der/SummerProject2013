#ifndef GAME_OBJECT_H

#define GAME_OBJECT_H


#include "includes.h"

class GameObject: public ScreenObject
{
protected:
	int mapX;
	int mapY;
	int hitPoints;
	int damageReduction;

public:
	GameObject();
	bool setPosition(int xPos, int yPos);
	int getXPosition();
	int getYPosition();
	
};

#endif