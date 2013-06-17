#include "includes.h"

GameWorld::GameWorld()
{
	dungeons[0] = new DungeonLevel();

	player = new Character();

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

	}

	return false;
}

int GameWorld::gameLoop(sf::RenderWindow * screen)
{
	while (screen->isOpen())
	{
		inputHandler(screen);
		



	}
	return 1;
}