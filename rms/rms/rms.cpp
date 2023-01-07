// rms.cpp : 定义控制台应用程序的入口点。
//

#include<iostream>
#include <windows.h>
#include <process.h>
#include <conio.h>
#pragma comment(lib, "..\\Debug\\rmsDLL.lib")
#include "..\rmsDLL\Ado.h"　
#include "..\rmsDLL\Menu.h"　
#include "..\rmsDLL\Employee.h"　
#include "..\rmsDLL\menuAction.h"　
#include "..\rmsDLL\EmployeeAction.h"　


using namespace std;


void mainHandling();
void searchHandle();
void managementHandle();
void managementMenuHandle();
void managementEmployeeHandle();
void start();
void threadHandle();


ADO ado(3);//选择 access
menuAction mAction;
EmployeeAction eAction;

UINT uId1, uId2;

UINT __stdcall ThreadProc(LPVOID);
UINT __stdcall ThreadProc2(LPVOID);



int _tmain(int argc, _TCHAR* argv[])
{
	threadHandle();
	return 0;
}

void mainHandling(){


	int result = ado.InitConn("", "", "rms.mdb");
	//cout << (result ? "成功连接数据库" : "数据库连接失败") << endl;

	start();


}


//负责查询
void searchHandle(){
	char choice;
	system("cls");
	cout << "请选择查询对象：菜单（A）员工（B）" << endl;
	cin >> choice;
	if (choice == 'a' || choice == 'A'){
		cout << endl << "菜单完整列表:" << endl;
		mAction.showMenu();
		cout << endl;
		char foodName[50];
		cout << "请输入要查询的菜品的名称：";
		cin >> foodName;
		system("cls");
		cout << "查询结果:";
		mAction.searchFood(foodName);
		start();
	}
	else if (choice == 'b' || choice == 'B'){
		cout << endl << "员工完整列表:" << endl;
		eAction.showAllEmployee();
		cout << endl;
		char name[50];
		cout << "请输入要查询的员工的姓名：";
		cin >> name;
		system("cls");
		cout << "查询结果:";
		eAction.searchEmployee(name);
		start();
	}
}

//负责管理
void managementHandle(){
	system("cls");
	char choice;
	cout << "请选择管理对象：菜单（A）员工（B）" << endl;
	cin >> choice;
	if (choice == 'a' || choice == 'A'){
		system("cls");
		managementMenuHandle();
	}
	else if (choice == 'b' || choice == 'B'){
		system("cls");
		managementEmployeeHandle();
	}

}

//负责菜单管理
void managementMenuHandle(){

	char choice;

	cout << "*****************************菜单管理****************************" << endl << endl;
	//展示菜单表
	cout << "完整菜单列表:" << endl;
	mAction.showMenu();;
	cout << endl;

	cout << "请选择具体操作类型： 增加（A）删除（B）修改（C）" << endl;
	cin >> choice;


	if (choice == 'a' || choice == 'A'){
		char foodName[50], foodPrice[10];
		cout << "请输入新菜品名称：";
		cin >> foodName;
		cout << "请输入新菜品价格：";
		cin >> foodPrice;
		mAction.addFood(foodName, foodPrice);

		system("cls");
		//展示菜单表
		cout << "添加后完整菜单列表:" << endl;
		mAction.showMenu();
		start();
	}
	else if (choice == 'b' || choice == 'B'){
		char id[10];
		cout << "请输入要删除的菜品的id:";
		cin >> id;
		mAction.deleteFood(id);
		system("cls");
		//展示菜单表
		cout << "删除后完整菜单列表:" << endl;
		mAction.showMenu();
		start();
	}
	else if (choice == 'c' || choice == 'C'){
		char id[10];
		char foodName[50], foodPrice[20];

		cout << "请输入要修改的菜品的id:";
		cin >> id;
		cout << "请输入菜品的新名称:";
		cin >> foodName;
		cout << "请输入菜品的新价格:";
		cin >> foodPrice;

		mAction.updateFood(id, foodName, foodPrice);
		system("cls");
		//展示菜单表
		cout << "修改后完整菜单列表:" << endl;
		mAction.showMenu();
		start();
	}
}

//负责员工管理
void managementEmployeeHandle(){
	char choice;

	cout << "*****************************员工管理****************************" << endl << endl;

	//展示员工表
	eAction.showAllEmployee();
	cout << endl;

	cout << "请选择具体操作类型： 增加（A）删除（B）修改（C）" << endl;
	cin >> choice;


	if (choice == 'a' || choice == 'A'){
		char name[50], role[10];
		cout << "请输入新员工姓名：";
		cin >> name;
		cout << "请输入新员工职位：";
		cin >> role;
		eAction.addEmployee(name, role);
		system("cls");
		cout << "添加后完整员工表" << endl;
		//展示员工表
		eAction.showAllEmployee();;
		start();
	}
	else if (choice == 'b' || choice == 'B'){
		char id[10];
		cout << "请输入要删除的员工的id:";
		cin >> id;
		eAction.deleteEmployee(id);
		system("cls");
		cout << "删除后完整员工表" << endl;
		//展示员工表
		eAction.showAllEmployee();
		start();
	}
	else if (choice == 'c' || choice == 'C'){
		char id[10];
		char name[50], role[20];

		cout << "请输入要修改的员工的id:";
		cin >> id;
		cout << "请输入员工的新姓名:";
		cin >> name;
		cout << "请输入员工的新职位:";
		cin >> role;

		eAction.updateEmployee(id, name, role);
		system("cls");
		cout << "修改后完整员工表" << endl;
		//展示员工表
		eAction.showAllEmployee();
		start();
	}
}

void start(){
	char choice;

	cout << endl;
	cout << "----------------------------- 分割线 ----------------------------" << endl;
	cout << endl;
	cout << "*****************************************************************" << endl;
	cout << "*****************************************************************" << endl;
	cout << "*****************************************************************" << endl;
	cout << "*************************光华餐厅管理系统************************" << endl;
	cout << "*****************************************************************" << endl;
	cout << "*****************************************************************" << endl;
	cout << "*****************************************************************" << endl << endl << endl << endl;

	cout << "请选择操作类型： 查阅（S) 管理（M）按Esc键随时退出" << endl;
	cin >> choice;

	if (choice == 's' || choice == 'S'){
		searchHandle();
	}
	else if (choice == 'm' || choice == 'M'){
		managementHandle();
	}
}

void threadHandle(){
	HANDLE h[2];


	h[0] = (HANDLE)::_beginthreadex(NULL, 0, ThreadProc, NULL, 0, &uId1);
	h[1] = (HANDLE)::_beginthreadex(NULL, 0, ThreadProc2, NULL, 0, &uId2);


	::WaitForMultipleObjects(2, h, TRUE, INFINITE);
	::CloseHandle(h[0]);
	::CloseHandle(h[1]);

}

UINT __stdcall ThreadProc(LPVOID)
{
	while (1){
		if (GetKeyState(VK_ESCAPE) & 0x8000)
		{
			break;
		}
	}
	exit(0);
	return 0;

}

UINT __stdcall ThreadProc2(LPVOID){

	mainHandling();
	return 0;
}