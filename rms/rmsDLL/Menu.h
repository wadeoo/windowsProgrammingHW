#pragma once
#ifndef MENU_H
#define MENU_H
#include <string>
using namespace std;

#ifdef DLL_FILE
class _declspec(dllexport) Menu //������
#else
class _declspec(dllimport) Menu //������
#endif
{
public:
	Menu();
	Menu(string foodName, double foodPrice);
	~Menu();
private:
	string  foodName;
	double  foodPrice;
	
};

#endif
