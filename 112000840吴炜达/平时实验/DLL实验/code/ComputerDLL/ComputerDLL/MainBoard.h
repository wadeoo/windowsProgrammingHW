#pragma once
#ifndef MAINBOARD_H
#define MAINBOARD_H
#include<iostream>


enum enum_mainBoard_model
{
	A,B,C,D
};
#ifdef DLL_FILE
class _declspec(dllexport)MainBoard 
#else
class _declspec(dllimport)MainBoard 
#endif
{
private:
	enum_mainBoard_model mainBoardModel;
public:
	MainBoard();
	MainBoard(enum_mainBoard_model);

	~MainBoard();

	void MainBoardRun();
	void MainBoardStop();

};


#endif // !MAIN_BOARD

