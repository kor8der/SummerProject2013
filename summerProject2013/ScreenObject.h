
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
	
	bool loadTexture(std::string location);
	
	bool drawSelf(sf::RenderWindow *target);
};


#endif