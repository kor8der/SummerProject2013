#include "includes.h"

GameWorld::GameWorld()
{
//	malloc(sizeof(new DungeonLevel()));

	player = new Character();
	
	dungeons[0] = DungeonLevel(player);

	//malloc(sizeof(new Character()));
	
	

}

bool GameWorld::inputHandler(sf::RenderWindow * screen)
{
	sf::Event event;

	while (screen->pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			{
				screen->close();
				return true;
			}
		else if (event.type == sf::Event::KeyPressed)
		{

		}
	}

	return false;
}

int GameWorld::gameLoop(sf::RenderWindow * screen)
{
	while (screen->isOpen())
	{
		inputHandler(screen);
		
		drawDungeon(screen);

		player->drawSelf(screen);


	}
	return 1;
}

void GameWorld::drawDungeon(sf::RenderWindow * screen)
{
	dungeons[0].drawDungeon(screen);
}