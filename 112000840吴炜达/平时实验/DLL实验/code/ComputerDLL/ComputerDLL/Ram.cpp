#ifndef DLL_FILE
#define DLL_FILE
#endif
#include "Ram.h"

Ram::Ram()
{
}

Ram::Ram(enum_ram_model rModel)
{
	ramModel = rModel;
}

Ram::~Ram()
{
}

void Ram::ramRun()
{
	std::cout << "�ڴ����� ������"<<std::endl;
}

void Ram::ramStop()
{
	std::cout << "�ڴ����� ֹͣ��" << std::endl;
}
