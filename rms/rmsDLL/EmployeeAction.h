#pragma once
#ifndef EMPLOYEEACTION_H
#define EMPLOYEEACTION_H
#include "Menu.h"
#include"Ado.h"

#ifdef DLL_FILE
class _declspec(dllexport) EmployeeAction //������
#else
class _declspec(dllimport) EmployeeAction //������
#endif
{
public:
	EmployeeAction();
	~EmployeeAction();

	void showAllEmployee();

	void searchEmployee(char* name);

	void addEmployee(char* name, char* role);
	void deleteEmployee(char* id);
	void updateEmployee(char* id, char* name, char* role);

private:
	ADO ado;
};
#endif

