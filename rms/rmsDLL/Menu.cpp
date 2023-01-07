#ifndef DLL_FILE
#define DLL_FILE
#endif
#include "Menu.h"


Menu::Menu()
{
	
}

Menu::Menu(string foodName, double foodPrice){
	this->foodName = foodName;
	this->foodPrice = foodPrice;
}


Menu::~Menu()
{
}

