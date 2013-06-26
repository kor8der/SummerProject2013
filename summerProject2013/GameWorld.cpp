#include "includes.h"

GameWorld::GameWorld()
{
//	malloc(sizeof(new DungeonLevel()));

	std::cout <<"before player is created: \n"  <<"&player is: " << &player << '\n' << "&dungeons[0] is: " << &dungeons[0] <<'\n';

	player = new Character();
	
	std::cout <<"after player is created: \n" << "&player is: " << &player << '\n' << "&dungeons[0] is: " << &dungeons[0] <<'\n';

	dungeons = new DungeonLevel(player);

	std::cout <<"end of world creation: \n" << "&player is: " << &player << '\n' << "&dungeons[0] is: " << &dungeons[0] <<'\n';



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
	}
	return 1;
}

void GameWorld::drawDungeon(sf::RenderWindow * screen)
{
	screen->clear();
	dungeons[0].drawDungeon(screen);
	player->drawSelf(screen);
	screen->display();
}