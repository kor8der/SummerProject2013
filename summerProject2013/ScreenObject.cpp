#include"includes.h"

ScreenObject::ScreenObject()
{

}

ScreenObject::ScreenObject(int screenPosX, int screenPosY, int textSizeX, int textSizeY)
{
	screenX = screenPosX;
	screenY = screenPosY;
	sizeX = textSizeX;
	sizeY = textSizeY;
	loadTexture("img/testjpg.jpg");
}

ScreenObject::ScreenObject(int screenPosX, int screenPosY, int textSizeX, int textSizeY, std::string location)
{
	screenX = screenPosX;
	screenY = screenPosY;
	sizeX = textSizeX;
	sizeY = textSizeY;
	loadTexture(location);
}

int ScreenObject::getScreenX()
{
	return screenX;
}

int ScreenObject::getScreenY()
{
	return screenY;
}


bool ScreenObject::loadTexture(std::string location)
{
	if(!objectTexture.loadFromFile(location))
	{
		std::cout << "COULD NOT LOAD TEXTURE: " << location << '\n';
		return false;
	}
	objectSprite.setTexture(objectTexture);
	objectSprite.setPosition(screenX, screenY);
	
	return true;
}

bool ScreenObject::drawSelf(sf::RenderWindow *target)
{
	target->draw(objectSprite);
	return true;
}