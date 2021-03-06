
/*
 * GameItem.cpp
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

GameItem::GameItem()
{
	charges = -1;
	weight = 2;
	value = 1;
	minDamage = 1;
	maxDamage = 2;
	critMultiplier = 130;

	loadTexture("img/daggerMap.png"); //needs a better solution

	screenX = 16;
	screenY = 16;

}

bool GameItem::adjustPosition(int newScreenX, int newScreenY)
{
	
	screenX = newScreenX;
	screenY = newScreenY;
	objectSprite.setPosition(screenX, screenY);
	return true;
}