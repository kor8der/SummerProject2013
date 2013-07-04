#include "includes.h"

GameWorld::GameWorld()
{
//	malloc(sizeof(new DungeonLevel()));

	std::cout <<"before player is created: \n"  <<"&player is: " << &player << '\n' << "&dungeons[0] is: " << &dungeons[0] <<'\n';

	player = new Character();
	
	std::cout <<"after player is created: \n" << "&player is: " << &player << '\n' << "&dungeons[0] is: " << &dungeons[0] <<'\n';

	dungeons = new DungeonLevel(player);

	std::cout <<"end of world creation: \n" << "&player is: " << &player << '\n' << "&dungeons[0] is: " << &dungeons[0] <<'\n';

	sideBar = new GuiElement(550,0,250,600, "img/sideGuiBackground.png");

	background = new GuiElement(0,0,800,600, "img/background.png");

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
			if (event.key.code == sf::Keyboard::Left || event.key.code == sf::Keyboard::A)
			{
				movePlayer(-1, 0);
			}
			if (event.key.code == sf::Keyboard::Up || event.key.code == sf::Keyboard::W)
			{
				movePlayer(0, -1);
			}
			if (event.key.code == sf::Keyboard::Right || event.key.code == sf::Keyboard::D)
			{
				movePlayer(1, 0);
			}
			if (event.key.code == sf::Keyboard::Down || event.key.code == sf::Keyboard::S)
			{
				movePlayer(0, 1);
			}
		}
	}

	return false;
}

int GameWorld::gameLoop(sf::RenderWindow * screen)
{
	while (screen->isOpen())
	{
		inputHandler(screen);
		//std::cout << "Screen adress from game loop to draw function: " << &screen << '\n';
	
		drawDungeon(screen);
		
	}
	return 1;
}

void GameWorld::drawDungeon(sf::RenderWindow * screen)
{

	screen->clear();
	background->drawSelf(screen);
	//std::cout << "Screen adress pre sending: " << &screen << '\n';
	dungeons[0].drawDungeon(screen);
	player->drawSelf(screen);
	//std::cout << "Screen adress sent to player->drawSelf: " << &screen << '\n';
	sideBar->drawSelf(screen);
	screen->display();
}

bool GameWorld::movePlayer(int deltaX, int deltaY)
{
	MapObject *destination;

	destination = dungeons[0].getSquare(player->getXPosition()+deltaX,player->getYPosition()+deltaY);
	
	if(!destination->getMovementBlocking())
	{
		player->setPosition(player->getXPosition()+deltaX,player->getYPosition()+deltaY);
		return true;
	}

	return false;
}
