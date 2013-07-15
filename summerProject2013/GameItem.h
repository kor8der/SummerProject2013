#ifndef GAME_ITEM_H

#define GAME_ITEM_H

#include "includes.h"

class GameItem : public GameObject
{
protected:
	bool equipable;
	int charges; 
	int weight; //the weight of the item in kilograms	
	int value; //the value of the item in gold peices 

public:
	GameItem();


};

#endif