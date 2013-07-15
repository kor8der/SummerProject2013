#ifndef GAME_ITEM_H

#define GAME_ITEM_H

#include "includes.h"

class GameItem : public GameObject
{
protected:
	bool equipable;
	int charges;

public:
	GameItem();


};

#endif