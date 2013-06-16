
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
	texture.loadFromFile("img/testImg.gif");
	sf::Sprite sprite(texture);


	sf::Font font;
	font.loadFromFile("font/Amano.ttf");
	sf::Text text("holy shit", font, 50);
	text.setPosition(0,40);

	while (screen.isOpen())
	{
		//update loop

		screen.clear();

		screen.draw(sprite);

		screen.draw(text);

		screen.display();
	}
	
	return 0;

}