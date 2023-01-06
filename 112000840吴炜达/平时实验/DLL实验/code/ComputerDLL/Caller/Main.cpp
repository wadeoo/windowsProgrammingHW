#include <string.h>
#pragma comment(lib, "..\\Debug\\ComputerDll.lib")
#include "..\ComputerDll\Computer.h"　　//包含类声明头文件
int main() {
	std::string compModel="laptop";
	Computer computer(compModel,i1,DDR2,B);

	computer.computerRun();
	computer.computerStop();

	std::cout << computer.getBrand() << std::endl;
	computer.advertising();

}