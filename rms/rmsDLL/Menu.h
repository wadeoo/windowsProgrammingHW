#pragma once
#ifndef MENU_H
#define MENU_H
#include <string>
using namespace std;

#ifdef DLL_FILE
class _declspec(dllexport) Menu //导出类
#else
class _declspec(dllimport) Menu //导入类
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
