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

	characterImage = new GuiElement(558,8,64,64, "img/characterPortrait.png");


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
				player->setFacing(WEST);
				movePlayer(-1, 0);				
			}
			if (event.key.code == sf::Keyboard::Up || event.key.code == sf::Keyboard::W)
			{
				player->setFacing(NORTH);
				movePlayer(0, -1);
			}
			if (event.key.code == sf::Keyboard::Right || event.key.code == sf::Keyboard::D)
			{
				
				player->setFacing(EAST);
				movePlayer(1, 0);
			}
			if (event.key.code == sf::Keyboard::Down || event.key.code == sf::Keyboard::S)
			{
				player->setFacing(SOUTH);
				movePlayer(0, 1);
			}
			if (event.key.code == sf::Keyboard::Escape)
			{
				screen->close();
				return true;
			}
			if (event.key.code == sf::Keyboard::P)
			{
				pickUp();
			}
			if (event.key.code == sf::Keyboard::Q)
			{
				putDown();
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
	characterImage->drawSelf(screen);
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

bool GameWorld::pickUp()
{
	MapObject *destination;
	destination = dungeons[0].getSquare(player->getXPosition(), player->getYPosition());
	
	if (destination->getHasItems() && !player->inventoryIsFull())
	{
		player->addItem(destination->removeItem());

		return true;
	}
	
	return false;
}

bool GameWorld::putDown()
{
	MapObject *destination;
	destination = dungeons[0].getSquare(player->getXPosition(), player->getYPosition());
	
	if (!destination->getIsFull() && player->getHasItems())
	{
		GameItem *temp;
		*temp = player->removeItem();
		srand(time(NULL));
		do{
			temp = destination->addItem(*temp);
			if (temp)
			{
				
				int direction = rand()%4;

				if (direction == 0)
				{
					destination = dungeons[0].getSquare(destination->getXPosition(), destination->getYPosition());
				}
				else if (direction == 1)
				{
					destination = dungeons[0].getSquare(destination->getXPosition(), destination->getYPosition());
				}
				else if (direction == 2)
				{
					destination = dungeons[0].getSquare(destination->getXPosition(), destination->getYPosition());
				}
				else if (direction == 3)
				{
					destination = dungeons[0].getSquare(destination->getXPosition(), destination->getYPosition());
				}
			}
		} while (temp != NULL);
	}
	return true;
}