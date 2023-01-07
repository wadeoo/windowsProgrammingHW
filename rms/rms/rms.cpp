// rms.cpp : 定义控制台应用程序的入口点。
//

#include<iostream>
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


ADO ado(3);//选择 access
menuAction mAction;
EmployeeAction eAction;

int _tmain(int argc, _TCHAR* argv[])
{
	mainHandling();
	return 0;
}

void mainHandling(){


	int result = ado.InitConn("", "", "rms.mdb");
	cout << (result ? "yes" : "no") << endl;


	//
	char choice;

	cout << endl;
	cout << "*****************************************************************" << endl;
	cout << "*****************************************************************" << endl;
	cout << "*****************************************************************" << endl;
	cout << "**************************光华餐厅管理系统***********************" << endl;
	cout << "*****************************************************************" << endl;
	cout << "*****************************************************************" << endl;
	cout << "*****************************************************************" << endl;

	cout << "请选择操作类型： 查阅（S) 管理（M）按Q键随时退出" << endl;
	cin >> choice;

	if (choice == 's' || choice == 'S'){
		searchHandle();
	}
	else if (choice == 'm' || choice == 'M'){
		managementHandle();
	}




	system("pause");
}


//负责查询
void searchHandle(){

}

//负责管理
void managementHandle(){
	//system("cls");
	//
	char choice;
	cout << "请选择管理对象：菜单（A）员工（B）" << endl;
	cin >> choice;
	if (choice == 'a' || choice == 'A'){
		managementMenuHandle();
	}
	else if (choice == 'b' || choice == 'B'){
		managementEmployeeHandle();
	}

}

//负责菜单管理
void managementMenuHandle(){
	
	char choice;

	cout << "*******菜单管理*******" << endl;

	//展示菜单表
	mAction.showMenu();;

	cout << "请选择具体操作类型： 增加（A）删除（B）修改（C）"<< endl;
	cin >> choice;

	
	if (choice == 'a' || choice == 'A'){
		char foodName[50], foodPrice[10];
		cout << "请输入新菜品名称：";
		cin >> foodName;
		cout << "请输入新菜品价格：";
		cin >> foodPrice;
		mAction.addFood(foodName, foodPrice);
		//展示菜单表
		mAction.showMenu();
	}
	else if (choice == 'b' || choice == 'B'){
		char id[10];
		cout << "请输入要删除的菜品的id:";
		cin >> id;
		mAction.deleteFood(id);
		//展示菜单表
		mAction.showMenu();
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

		mAction.updateFood(id,foodName,foodPrice);
		//展示菜单表
		mAction.showMenu();
	}
}

//负责员工管理
void managementEmployeeHandle(){
	char choice;

	cout << "*******员工管理*******" << endl;

	//展示员工表
	eAction.showAllEmployee();

	cout << "请选择具体操作类型： 增加（A）删除（B）修改（C）" << endl;
	cin >> choice;


	if (choice == 'a' || choice == 'A'){
		char name[50], role[10];
		cout << "请输入新员工姓名：";
		cin >> name;
		cout << "请输入新员工职位：";
		cin >> role;
		eAction.addEmployee(name, role);
		//展示员工表
		eAction.showAllEmployee();;
	}
	else if (choice == 'b' || choice == 'B'){
		char id[10];
		cout << "请输入要删除的员工的id:";
		cin >> id;
		eAction.deleteEmployee(id);
		//展示员工表
		eAction.showAllEmployee();
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
		//展示员工表
		eAction.showAllEmployee();
	}
}