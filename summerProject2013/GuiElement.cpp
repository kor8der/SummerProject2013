#include "includes.h"

GuiElement::GuiElement(int screenPosX, int screenPosY, int textSizeX, int textSizeY, std::string location)
{
	screenX = screenPosX;
	screenY = screenPosY;
	sizeX = textSizeX;
	sizeY = textSizeY;
	loadTexture(location);
}