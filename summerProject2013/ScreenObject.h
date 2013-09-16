
/*
 * ScreenObject.h
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

#ifndef SCREEN_OBJECT_H

#define SCREEN_OBJECT_H

#include "includes.h"

class ScreenObject
{
protected:
	int screenX;
	int screenY;
	int sizeX;
	int sizeY;
	sf::Texture objectTexture;
	sf::Sprite objectSprite;


public:

	ScreenObject();
	ScreenObject(int screenPosX, int screenPosY, int textSizeX, int textSizeY);
	ScreenObject(int screenPosX, int screenPosY, int textSizeX, int textSizeY, std::string location);
	
	int getScreenX();
	int getScreenY();

	bool loadTexture(std::string location);
	bool drawSelf(sf::RenderWindow *target);
};


#endif