#ifndef DUNGEON_LEVEL_H

#define DUNGEON_LEVEL_H

#include "includes.h"

class DungeonLevel
{
protected:
	static const int MAPSIZE = 50;
	MapObject* map[MAPSIZE][MAPSIZE];
	Character * playerChar;

public:
	DungeonLevel();
	DungeonLevel(Character * tempChar);
	void drawDungeon(sf::RenderWindow *target);
	void adjustMap();
	MapObject *getSquare(int xPos, int yPos);
};

#endif