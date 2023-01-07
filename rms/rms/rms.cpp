// rms.cpp : 定义控制台应用程序的入口点。
//

#include<iostream>
#pragma comment(lib, "..\\Debug\\rmsDLL.lib")
#include "..\rmsDLL\Ado.h"　
#include "..\rmsDLL\Menu.h"　
#include "..\rmsDLL\Employee.h"　


using namespace std;


void mainHandling();
void searchHandle();
void managementHandle();
void managementMenuHandle();
void managementEmployeeHandle();


ADO ado(3);//选择 access

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
	cout << "请选择具体操作类型： 增加（A）删除（B）修改（C）"<< endl;
	cin >> choice;
	if (choice == 'a' || choice == 'A'){
		managementMenuHandle();
	}
	else if (choice == 'b' || choice == 'B'){
		managementEmployeeHandle();
	}
	else if (choice == 'c' || choice == 'C'){
		managementEmployeeHandle();
	}
}

//负责员工管理
void managementEmployeeHandle(){

}