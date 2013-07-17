
/*
 * main.cpp
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

	ScreenObject guiFrame(550, 0, 250, 600);
	guiFrame.loadTexture("img/sideGuiBackground.gif");

	music.openFromFile("music/Minima.ogg"); //From incompetech
	music.setLoop(true);
	//music.play();
	
	//DungeonLevel testLevel;

	GameWorld * game;
	std::cout << "&game is: " << &game << '\n';
	game = new GameWorld();
	//update loop
	MapObject testSquare;
	testSquare = MapObject(1,1,0,0,0);
	/*while (true)
	{
		screen.clear();
		testSquare.drawSelf(&screen);
		screen.display();
	}*/

	int code;
	
	std::cout << "Screen adress in main: " << &screen << '\n';
	
	code = game->gameLoop(&screen);

	if (1 == code)
	{
		std::cout << "successful exit";
	}
		

	//	testLevel.drawDungeon(&screen);

	//	screen.draw(sprite);

	//	screen.draw(text);

		
	
	return 0;

}