

#include "includes.h"

DungeonLevel::DungeonLevel()
{
	srand(time(NULL));

	for (int i = 0; i<50; i++)
	{
		for (int j = 0; j<50; j++)
		{
			map [i][j] = new MapObject(rand()%2, 0, i, j);
		}
	}

	playerChar = NULL;
}

DungeonLevel::DungeonLevel(Character * tempChar)
{
	playerChar = tempChar;
	
	srand(time(NULL));

	for (int i = 0; i<50; i++)
	{
		for (int j = 0; j<50; j++)
		{
			map [i][j] = new MapObject(rand()%2, 0, i, j);
		}
	}

	
}

void DungeonLevel::drawDungeon(sf::RenderWindow * target)
{
	adjustMap();

	for (int i = 0; i<50; i++)
		{
			for (int j = 0; j<50; j++)
			{
				map [i][j]->drawSelf(target);
			}
		}
}

void DungeonLevel::adjustMap()
{
	for (int i = 0; i<50; i++)
		{
			for (int j = 0; j<50; j++)
			{
				map [i][j]->setScreenPosition(8-playerChar->getXPosition(), 8-playerChar->getYPosition());
			}
		}
	
	
	
}