#include <string.h>
#pragma comment(lib, "..\\Debug\\ComputerDll.lib")
#include "..\ComputerDll\Computer.h"����//����������ͷ�ļ�
int main() {
	std::string compModel="laptop";
	Computer computer(compModel,i1,DDR2,B);

	computer.computerRun();
	computer.computerStop();

	std::cout << computer.getBrand() << std::endl;
	computer.advertising();

}