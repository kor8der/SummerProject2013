

#include "includes.h"

DungeonLevel::DungeonLevel()
{
	srand(time(NULL));

	for (int i = 0; i<50; i++)
	{
		for (int j = 0; j<50; j++)
		{
			map [j][i] = MapObject(rand()%2, 0, i, j);
		}
	}

	playerChar = NULL;
}

DungeonLevel::DungeonLevel(Character * tempChar)
{
	playerChar = new Character();
	//*playerChar = tempChar;
	playerChar = tempChar;
	//tempChar, should use tempChar here, but somehow that does not work, not that this does
	std:: cout << "DungeonLevel(Character * tempChar, after playerChar is assigned: \n"
		<< "tempChar : " << tempChar << '\n'
		<< "playerChar: " << playerChar << '\n';
	srand(time(NULL));

	for (int i = 0; i<50; i++)
	{
		for (int j = 0; j<50; j++)
		{
			map [j][i] = MapObject(rand()%2, 0, i, j);
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
				map [j][i].drawSelf(target);
			}
		}
}

void DungeonLevel::adjustMap()
{
	for (int i = 0; i<50; i++)
		{
			for (int j = 0; j<50; j++)
			{
				map [j][i].setScreenPosition(8-playerChar->getXPosition(), 8-playerChar->getYPosition());
			}
		}
	
	
	
}