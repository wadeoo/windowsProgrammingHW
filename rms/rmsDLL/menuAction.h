#pragma once
#ifndef MENUACTION_H
#define MENUACTION_H
#include "Menu.h"
#include"Ado.h"

#ifdef DLL_FILE
class _declspec(dllexport) menuAction //������
#else
class _declspec(dllimport) menuAction //������
#endif
{
public:
	menuAction();
	~menuAction();

	void showMenu();

	void addFood(char* foodName, char* foodPrice);
	void deleteFood(char* id);
	void updateFood(char* id,char* foodName,char* foodPrice);
private:
	ADO ado;



};
#endif
