#ifndef GAME_WORLD_H

#define GAME_WORLD_H

#include "includes.h"

class GameWorld
{
protected:
	Character * player;
	DungeonLevel * dungeons;
	GuiElement * sideBar;
	
public:
	GameWorld();
	int gameLoop(sf::RenderWindow * screen);
	void drawDungeon(sf::RenderWindow * screen);
	bool inputHandler(sf::RenderWindow * screen);
	bool movePlayer(int deltaX, int deltaY);
	
};

#endif