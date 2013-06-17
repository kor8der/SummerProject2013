

#include "includes.h"

DungeonLevel::DungeonLevel()
{
	srand(time(NULL));

	for (int i = 0; i<=50; i++)
	{
		for (int j = 0; j<=50; j++)
		{
			map [i][j] = new MapObject (rand()%2, 0, i, j);
		}
	}
}

void DungeonLevel::drawDungeon(sf::RenderWindow *target)
{
	for (int i = 0; i<=50; i++)
		{
			for (int j = 0; j<=50; j++)
			{
				map [i][j]->drawSelf(target);
			}
		}
}

void DungeonLevel::adjustMap()
{
	player->getXPosition(), player->getYPosition()
	
}