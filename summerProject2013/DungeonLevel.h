#ifndef DUNGEON:LEVEL_H

#define DUNGEON_LEVEL_H

#include "includes.h"

class DungeonLevel
{
protected:
	MapObject  * map [50][50];
	Character * player;

public:
	DungeonLevel();
	void drawDungeon(sf::RenderWindow *target);
	void adjustMap();
};

#endif