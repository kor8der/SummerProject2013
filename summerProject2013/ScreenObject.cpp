
/*
 * ScreenObject.cpp
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

bool ScreenObject::setScreenPos(int newX, int newY)
{
	screenX=newX;
	screenY=newY;
	return true;
}
