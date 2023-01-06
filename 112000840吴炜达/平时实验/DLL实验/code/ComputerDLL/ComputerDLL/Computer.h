#pragma once
#ifndef COMPUTER_H
#define COMPUTER_H
#include<iostream>
#include<string>
#include"Cpu.h"
#include"Ram.h"
#include"MainBoard.h"

#ifdef DLL_FILE
class _declspec(dllexport) Computer //������Computer
#else
class _declspec(dllimport) Computer //������Computer
#endif
{
private:
    std::string computerModel;
    Cpu cpu;
    Ram ram;
    MainBoard mainBoard;

    const std::string computerBrand="����";
public:
    Computer();
    Computer(std::string,enum_cpu_model,enum_ram_model,enum_mainBoard_model);

    ~Computer();

    void computerRun();
    void computerStop();

    const  std::string getBrand();

    void advertising();
};



#define COMPUTER
#endif // !COMPUTER

