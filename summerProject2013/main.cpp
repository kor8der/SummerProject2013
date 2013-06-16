
#include "includes.h"


int main ()
{


	struct
	{
		int screenWidth;
		int screenHeight;
		bool fullScreen;

	} screenSettings;

	screenSettings.screenWidth = 800;
	screenSettings.screenHeight = 600;
	screenSettings.fullScreen = false;

	sf::RenderWindow screen;
	sf::Music music;

	if (screenSettings.fullScreen)
	{
		screen.create(sf::VideoMode(screenSettings.screenWidth, screenSettings.screenHeight, 32), "Test Window", sf::Style::Fullscreen);
	}
	else
	{
		screen.create(sf::VideoMode(screenSettings.screenWidth, screenSettings.screenHeight, 32), "Test Fullscreen Window");
	}
	screen.setFramerateLimit(30);

	sf::Texture texture;
	texture.loadFromFile("img/testjpg.jpg");
	sf::Sprite sprite(texture);


	sf::Font font;
	font.loadFromFile("font/Amano.ttf");
	sf::Text text("holy shit, text!", font, 50);
	text.setPosition(0,400);

	std::string argument;
	ScreenObject guiFrame(550, 0, 250, 600);
	guiFrame.loadTexture("img/sideGuiBackground.gif");

	while (screen.isOpen())
	{
		//update loop

		sf::Event event;

		while (screen.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				screen.close();
			}
		}

		screen.clear();

		screen.draw(sprite);

		screen.draw(text);

		guiFrame.drawSelf(&screen);

		screen.display();
	}
	
	return 0;

}