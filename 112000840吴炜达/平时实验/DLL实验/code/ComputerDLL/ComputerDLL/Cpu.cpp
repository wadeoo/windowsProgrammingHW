#ifndef DLL_FILE
#define DLL_FILE
#endif
#include "Cpu.h"


Cpu::Cpu() {};

Cpu::Cpu(enum_cpu_model cModel) {
	cpuModel = cModel;
}

Cpu::~Cpu() {};

void Cpu::cpuRun() {
	std::cout << "���봦��Ԫ ������"<<std::endl;
}


void Cpu::cpuStop() {
	std::cout << "���봦��Ԫ ֹͣ��"<<std::endl;
}


