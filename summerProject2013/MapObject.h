#ifndef MAP_OBJECT_H

#define MAP_OBJECT_H

#include "includes.h"

class MapObject: public GameObject
{
protected:
	bool blocking;
	bool restrictive;

public:
	MapObject();
	MapObject(bool block, bool rest, int posX, int posY);


};



#endif