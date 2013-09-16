#ifndef GAME_ITEM_H

#define GAME_ITEM_H

#include "includes.h"

class GameItem //:public GameObject//removed for testing
{
protected:
	int charges; 
	int weight; //the weight of the item in Hectograms	
	int value; //the value of the item in gold peices 
	int minDamage;
	int maxDamage;
	int critMultiplier;

public:
	GameItem();


};

#endif