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
	numberOfItems = 0;
}

//Character Character::operator = (Character * temp)
//{
//	Character tempChar;
//	tempChar = Character();
//	
//	strength = temp->getStr();
//	toughness = temp->getTou();
//	agility = temp->getAgi();
//	intelligence = temp->getInt();
//	perception = temp->getPer();
//	will = temp->getWill();	
//	facing = temp->getFacing();
//	sightRadius = temp->getSightRadius();
//
//
//	
//
//	return tempChar;
//}

bool Character::setFacing(facingDirection newFacing)
{
	facing = newFacing;

	if (facing == WEST)
	{
		loadTexture("img/playerFacingWest.png");
	}

	else if (facing == NORTH)
	{
		loadTexture("img/playerFacingNorth.png");
	}
	else if (facing == EAST)
	{
		loadTexture("img/playerFacingEast.png");
	}
	else if (facing == SOUTH)
	{
		loadTexture("img/playerFacingSouth.png");
	}

	return true;
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

bool Character::addItem(GameItem *newItem)
{
	if (numberOfItems >= MAXITEMS)
	{
		return false;
	}
	characterItems[numberOfItems] = *newItem;
	
	numberOfItems++;
	
	return true;
}


bool Character::inventoryIsFull()
{
	if (numberOfItems >= MAXITEMS)
	{
		return true;
	}
	return false;
}

bool Character::getHasItems()
{
	return numberOfItems;
}

GameItem Character::removeItem()
{
	numberOfItems--;
	return characterItems[numberOfItems+1];
}


