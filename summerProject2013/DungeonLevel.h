#ifndef DUNGEON:LEVEL_H

#define DUNGEON_LEVEL_H

#include "includes.h"

class DungeonLevel
{
protected:
	MapObject *** map;
	Character * playerChar;

public:
	DungeonLevel();
	DungeonLevel(Character * tempChar);
	void drawDungeon(sf::RenderWindow *target);
	void adjustMap();
};

#endif