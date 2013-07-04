

#include "includes.h"

DungeonLevel::DungeonLevel()
{
	srand(time(NULL));
	

	for (int i = 0; i<MAPSIZE; i++)
	{
		for (int j = 0; j<MAPSIZE; j++)
		{
			map [j][i] = new MapObject(rand()%2, 0, j, i);
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

	for (int i = 0; i<MAPSIZE; i++)
	{
		for (int j = 0; j<MAPSIZE; j++)
		{
			map [j][i] = new MapObject(rand()%2, 0, i, j);
		}
	}

	
}

void DungeonLevel::drawDungeon(sf::RenderWindow * target)
{
	adjustMap();

	//std::cout << "Screen adress sent to map [j][i]->drawSelf: " << &target<< '\n';
	

	for (int i = 0; i<MAPSIZE; i++)
		{
			for (int j = 0; j<MAPSIZE; j++)
			{
				map [j][i]->drawSelf(target);
			}
		}
}

void DungeonLevel::adjustMap()
{
	for (int i = 0; i<MAPSIZE; i++)
		{
			for (int j = 0; j<MAPSIZE; j++)
			{
				map [j][i]->setScreenPosition(playerChar->getXPosition()-8, playerChar->getYPosition()-8);
			}
		}	
}

MapObject *DungeonLevel::getSquare(int xPos, int yPos)
{
	return map[yPos][xPos];
}