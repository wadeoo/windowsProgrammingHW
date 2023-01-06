#pragma once
#ifndef RAM_H
#define RAM_H
#include<iostream>


enum enum_ram_model
{
	DDR1,DDR2,DDR3,DDR4
};

#ifdef DLL_FILE
class _declspec(dllexport)Ram 
#else
class _declspec(dllimport)Ram 
#endif
{
private:
	enum_ram_model	ramModel;
public:

	Ram();

	Ram(enum_ram_model);
	~Ram();

	void ramRun();
	void ramStop();
};


#endif // !RAM

