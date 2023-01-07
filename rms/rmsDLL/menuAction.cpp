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

void menuAction::searchFood(char* foodName){
	char* condition = new char[100];
	strcpy(condition, "foodName= '");
	strcat(condition, foodName);
	strcat(condition, "'");;
	ado.Query("menu", condition);
		ado.ShowCurrentRS(true);
}


void menuAction::addFood(char* foodName, char* foodPrice){
	ado.ExcuteSQL((_bstr_t)"INSERT INTO " + "menu" + " (foodName, foodPrice) VALUES ('" + foodName + "', " + "'" + foodPrice + "'" ")");
}

void menuAction::deleteFood(char* id){
	char* condition = new char[100];
	strcpy(condition, "id= ");
	strcat(condition, id);
	ado.Delete("menu", condition);
}

void menuAction::updateFood(char* id,char* foodName,char* foodPrice){
	char* content = new char[100];
	strcpy(content, "foodName= '");
	strcat(content, foodName);
	strcat(content, "', foodPrice= '");
	strcat(content, foodPrice);
	strcat(content, "'");

	char* condition = new char[100];
	strcpy(condition, "id= ");
	strcat(condition, id);
	
	ado.Update("menu", content,condition);
}