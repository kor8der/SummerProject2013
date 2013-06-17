#include"includes.h"


//default parameters for testing only
Character::Character()
{
	strength = 10;
	toughness = 10;
	agility = 10;
	intelligence = 10;
	perception = 10;
	will = 10;	
	facing = NORTH;
	//remove these later
	mapX = 8;
	mapY = 8; 
	//
	screenX = 32*mapX;
	screenY = 32*mapY;
	sizeX = 32;
	sizeY = 32;

	loadTexture("img/playerFacingNorth.png");


}

