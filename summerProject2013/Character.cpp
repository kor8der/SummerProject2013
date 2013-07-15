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

	sightRadius = perception/2;

	characterItems = NULL;

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
	sightRadius = temp->getSightRadius();


	

	return tempChar;
}

int Character::getStr() const
{
	return strength;
}
int Character::getTou() const
{
	return toughness;
}
int Character::getAgi() const
{
	return agility;
}
int Character::getInt() const
{
	return intelligence;
}
int Character::getPer() const
{
	return perception;
}
int Character::getWill() const
{
	return will;
}
facingDirection Character::getFacing() const
{
	return facing;
}

int Character::getSightRadius() const
{
	return sightRadius;
}

