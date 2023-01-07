#ifndef DLL_FILE
#define DLL_FILE
#endif
#include "menuAction.h"


menuAction::menuAction()
{
	ado = ADO(3);
	ado.InitConn("", "", "rms.mdb");
}


menuAction::~menuAction()
{
}


void menuAction::showMenu(){
	ado.GetTableInfo("menu");
	ado.ShowCurrentRS(true);
}


void menuAction::addFood(char* foodName, char* foodPrice){
	ado.ExcuteSQL((_bstr_t)"INSERT INTO " + "menu" + " (foodName, foodPrice) VALUES ('" + foodName + "', " + "'" + foodPrice + "'" ")");
}
