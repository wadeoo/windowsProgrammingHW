#ifndef DLL_FILE
#define DLL_FILE
#endif
#include "Employee.h"


Employee::Employee()
{
}

Employee::Employee(string name, string role){
	this->name = name;
	this->role = role;
}


Employee::~Employee()
{
}
