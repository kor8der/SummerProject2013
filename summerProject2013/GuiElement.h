#ifndef GUI_ELEMENT_H

#define GUI_ELEMENT_H

#include "includes.h"

class GuiElement: public ScreenObject
{
	
public:
	GuiElement();
	GuiElement(int screenPosX, int screenPosY, int textSizeX, int textSizeY, std::string location);

};

#endif