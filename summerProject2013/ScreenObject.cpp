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
}

ScreenObject::ScreenObject(int screenPosX, int screenPosY, int textSizeX, int textSizeY, std::string location)
{
	screenX = screenPosX;
	screenY = screenPosY;
	sizeX = textSizeX;
	sizeY = textSizeY;
	loadTexture(location);
}

bool ScreenObject::loadTexture(std::string location)
{
	objectTexture.loadFromFile(location);
	objectSprite.setTexture(objectTexture);
	objectSprite.setPosition(screenX, screenY);
	return true;
}

bool ScreenObject::drawSelf(sf::RenderWindow *target)
{
	target->draw(objectSprite);
	return true;
}