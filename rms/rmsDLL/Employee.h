#pragma once
#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <string>
using namespace std;

#ifdef DLL_FILE
class _declspec(dllexport) Employee //导出类
#else
class _declspec(dllimport) Employee //导入类
#endif
{
public:
	Employee();
	~Employee();
	Employee(string name, string role);
private:
	string name;
	string role;
};

#endif
