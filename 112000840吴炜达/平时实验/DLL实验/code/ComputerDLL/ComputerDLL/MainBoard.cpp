#ifndef DLL_FILE
#define DLL_FILE
#endif
#include "MainBoard.h"

MainBoard::MainBoard()
{
}

MainBoard::MainBoard(enum_mainBoard_model mModel)
{
	mainBoardModel = mModel;
}

MainBoard::~MainBoard()
{
}

void MainBoard::MainBoardRun()
{
	std::cout << "Ö÷°å Æô¶¯£¡" << std::endl;
}

void MainBoard::MainBoardStop()
{
	std::cout << "Ö÷°å Í£Ö¹£¡" << std::endl;
}
