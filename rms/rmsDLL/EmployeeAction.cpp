#ifndef DLL_FILE
#define DLL_FILE
#endif
#include "EmployeeAction.h"


EmployeeAction::EmployeeAction()
{
	ado = ADO(3);
	ado.InitConn("", "", "rms.mdb");
}


EmployeeAction::~EmployeeAction()
{
}

void EmployeeAction::showAllEmployee(){
	ado.GetTableInfo("employee");
	ado.ShowCurrentRS(true);
}

void  EmployeeAction::searchEmployee(char* name){
	char* condition = new char[100];
	strcpy(condition, "name= '");
	strcat(condition, name);
	strcat(condition, "'");;
	ado.Query("employee", condition);
		ado.ShowCurrentRS(true);
}

void EmployeeAction::addEmployee(char* name, char* role){
	ado.ExcuteSQL((_bstr_t)"INSERT INTO " + "employee" + " (name, role) VALUES ('" + name + "', " + "'" + role + "'" ")");
}

void EmployeeAction::deleteEmployee(char* id){
	char* condition = new char[100];
	strcpy(condition, "id= ");
	strcat(condition, id);
	ado.Delete("employee", condition);
}

void EmployeeAction::updateEmployee(char* id, char* name, char* role){
	char* content = new char[100];
	strcpy(content, "name= '");
	strcat(content, name);
	strcat(content, "', role= '");
	strcat(content, role);
	strcat(content, "'");

	char* condition = new char[100];
	strcpy(condition, "id= ");
	strcat(condition, id);

	ado.Update("employee", content, condition);
}