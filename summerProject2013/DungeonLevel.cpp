
/*
 * FILENAME.cpp
 *
 * 
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 *
 */


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
	//srand(1);//for testing
	for (int i = 0; i<MAPSIZE; i++)
	{
		for (int j = 0; j<MAPSIZE; j++)
		{
			
			if (j==MAPSIZE || i==MAPSIZE || j==0 || i==0)
			{
				map [j][i] = new MapObject(true, true, 0, i, j);
			}
			else
			{
				map [j][i] = new MapObject(rand()%2, rand()%2, 0, i, j);
			}
		}
	}

	octantMultipliers[0][0] = 1;
	octantMultipliers[0][1] = 0;
	octantMultipliers[0][2] = 0;
	octantMultipliers[0][3] = -1;
	octantMultipliers[0][4] = -1;
	octantMultipliers[0][5] = 0;
	octantMultipliers[0][6] = 0;
	octantMultipliers[0][7] = 1;
	
	octantMultipliers[1][0] = 0;
	octantMultipliers[1][1] = 1;
	octantMultipliers[1][2] = -1;
	octantMultipliers[1][3] = 0;
	octantMultipliers[1][4] = 0;
	octantMultipliers[1][5] = -1;
	octantMultipliers[1][6] = -1;
	octantMultipliers[1][7] = 0;

octantMultipliers[2][0] = 0;
octantMultipliers[2][1] = 1;
octantMultipliers[2][2] = 1;
octantMultipliers[2][3] = 0;
octantMultipliers[2][4] = 0;
octantMultipliers[2][5] = -1;
octantMultipliers[2][6] = -1;
octantMultipliers[2][7] = 0;


octantMultipliers[3][0] = 1;
octantMultipliers[3][1] = 0;
octantMultipliers[3][2] = 0;
octantMultipliers[3][3] = 1;
octantMultipliers[3][4] = -1;
octantMultipliers[3][5] = 0;
octantMultipliers[3][6] = 0;
octantMultipliers[3][7] = -1;

	//{
	//	{1,0,0,-1,-1,0,0,1},
	//	{0,1,-1,0,0,-1,1,0},
	//	{0,1,1,0,0,-1,-1,0},
	//	{1,0,0,1,-1,0,0,-1}
	//}
	
}

void DungeonLevel::drawDungeon(sf::RenderWindow * target)
{
	adjustMap();

	
	for (int octant = 0; octant<8; octant++)
	{
		shadowCasting(0, playerChar->getSightRadius(), 1, 0, octant, target);
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


bool DungeonLevel::shadowCasting(int startRow, int radius, double startAngle, double endAngle, int octant, sf::RenderWindow * target)
{
	if (startAngle < endAngle)
		{
			return false;
		}
	int radiusSquared = radius*radius;
	int deltaX;
	int deltaY;
	bool blocked;
	
	for(int row = startRow; row<=radius; row++)
	{

		deltaX = -row-1;//is incremented immediately!
		deltaY = -row;
		blocked = false;
		while (deltaX <= 0)
		{
			deltaX += 1;
			/** This is where the deltaX and deltaY coordinates are transformed into map coordinates**/
			int x = playerChar->getXPosition()+deltaX*octantMultipliers[0][octant]+deltaY*octantMultipliers[1][octant];
			int y = playerChar->getYPosition()+deltaX*octantMultipliers[2][octant]+deltaY*octantMultipliers[3][octant];
			/**rSlope and lSlope store the slopes of the left and right extremities of the square we're considering**/
			double rSlope;
			double lSlope;
			int newStart;
				
			rSlope = (deltaX+0.5)/(deltaY-0.5);
			lSlope = (deltaX-0.5)/(deltaY+0.5);
				
			if (startAngle < rSlope)
			{
				continue;
			}
			else if (endAngle >  lSlope)
			{
				break;
			}
			else
			{
				/** this means that the beam is touching this square and that we should light it **/ 
				if (deltaX*deltaX + deltaY*deltaY <= radiusSquared)//creates a circle, man
				{
					map[y][x]->drawSelf(target);
				}
				if (blocked)
				{
					/** we're scanning a row of blocked squares **/
					if (!map[y][x]->getIsSeeThrough())
					{
						newStart = rSlope;
						continue; /**change this**/
					}
					else
					{
						blocked = false;
						startAngle = newStart;
					}
				}
				else
				{	//first blocking square
					if (!map[y][x]->getIsSeeThrough() && row<radius)
					{
						/** this is a blocking square, start a child scan **/
						blocked = true;
						shadowCasting (row+1, radius, startAngle, lSlope, octant, target);
						newStart = rSlope;
							
					}
				}
			}
		}
		/** row is scanned, do next row unless last square was blocked **/
		if (blocked)
		{
			break;
		}
	}
			

	return true;
}