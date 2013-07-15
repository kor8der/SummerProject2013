#ifndef MAP_OBJECT_H

#define MAP_OBJECT_H

#include "includes.h"

class MapObject: public GameObject
{
protected:
	static const int MAXITEMS = 25;
	bool movementBlocking;
	bool visionBlocking;
	bool movementHampering;
	GameItem items[MAXITEMS];
	int numberOfItems;
public:
	MapObject();
	MapObject(bool block, bool visBlock, bool rest, int posX, int posY);
	bool setScreenPosition(int xOffset, int yOffset);
	bool getMovementBlocking();
	bool getMovementHampering();
	bool getIsSeeThrough();
	bool getHasItems();
	GameItem* removeItem();
	bool getIsFull();
	GameItem *addItem(GameItem newItem);
};



#endif