

#include "includes.h"

DungeonLevel::DungeonLevel()
{
	srand(time(NULL));
	

	for (int i = 0; i<MAPSIZE; i++)
	{
		for (int j = 0; j<MAPSIZE; j++)
		{
			map [j][i] = new MapObject(rand()%2, rand()%2, 0, j, i);
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
			map [j][i] = new MapObject(rand()%2, rand()%2, 0, i, j);
		}
	}

	
}

void DungeonLevel::drawDungeon(sf::RenderWindow * target)
{
	adjustMap();

	//std::cout << "Screen adress sent to map [j][i]->drawSelf: " << &target<< '\n';
	int leftEdge;
	int rightEdge;
	int bottomEdge;
	int topEdge;
	
	leftEdge = playerChar->getXPosition()-10;
	if(leftEdge < 0)
	{
		leftEdge = 0;
	}


	rightEdge = playerChar->getXPosition()+11;
	if(rightEdge > MAPSIZE)
	{
		rightEdge = MAPSIZE;
	}
	
	bottomEdge = playerChar->getYPosition()+11;
	if(bottomEdge > MAPSIZE)
	{
		bottomEdge = MAPSIZE;
	}


	topEdge = playerChar->getYPosition()-10;
	if (topEdge < 0)
	{
		topEdge = 0;
	}

	for (int i = leftEdge; i<rightEdge; i++)
		{
			for (int j = topEdge; j<bottomEdge; j++)
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
				map [j][i]->setScreenPosition(playerChar->getXPosition()-playerChar->getScreenX()/32, playerChar->getYPosition()-playerChar->getScreenY()/32);
			}
		}	
}

MapObject *DungeonLevel::getSquare(int xPos, int yPos)
{
	return map[yPos][xPos];
}