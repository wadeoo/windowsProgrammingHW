#pragma	once
#ifndef CPU_H
#define CPU_H
#include<iostream>


enum enum_cpu_model
{
	i1, i2, i3, i4
};
#ifdef DLL_FILE
class _declspec(dllexport)Cpu 
#else
class _declspec(dllimport)Cpu 
#endif
{
private:
	enum_cpu_model cpuModel;
public:
	Cpu();
	Cpu(enum_cpu_model);
	~Cpu();

	void cpuRun();
	void cpuStop();
};



#endif // !1

