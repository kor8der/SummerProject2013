
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
	sf::Image *objectImage;


public:

	ScreenObject();

};


#endif