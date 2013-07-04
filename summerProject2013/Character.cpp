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
	mapX = 9;
	mapY = 9; 
	//
	screenX = 32*mapX;
	screenY = 32*mapY;
	sizeX = 32;
	sizeY = 32;

	loadTexture("img/playerFacingNorth.png");


}

Character Character::operator = (Character * temp)
{
	Character tempChar;
	tempChar = Character();
	
	strength = temp->getStr();
	toughness = temp->getTou();
	agility = temp->getAgi();
	intelligence = temp->getInt();
	perception = temp->getPer();
	will = temp->getWill();	
	facing = temp->getFacing();
	return tempChar;
}

int Character::getStr()
{
	return strength;
}
int Character::getTou()
{
	return toughness;
}
int Character::getAgi()
{
	return agility;
}
int Character::getInt()
{
	return intelligence;
}
int Character::getPer()
{
	return perception;
}
int Character::getWill()
{
	return will;
}
facingDirection Character::getFacing()
{
	return facing;
}

