#pragma once
#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <string>
using namespace std;

#ifdef DLL_FILE
class _declspec(dllexport) Employee //������
#else
class _declspec(dllimport) Employee //������
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
