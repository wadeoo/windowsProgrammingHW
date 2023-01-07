// rms.cpp : 定义控制台应用程序的入口点。
//

#include<iostream>
#pragma comment(lib, "..\\Debug\\rmsDLL.lib")
#include "..\rmsDLL\Ado.h"　
#include "..\rmsDLL\Menu.h"　
#include "..\rmsDLL\Employee.h"　


using namespace std;


void mainHandling();


ADO ado(3);

int _tmain(int argc, _TCHAR* argv[])
{
	mainHandling();
	return 0;
}

void mainHandling(){
	int result = ado.InitConn("", "", "rms.mdb");
	cout << (result ? "yes" : "no") << endl;
}

