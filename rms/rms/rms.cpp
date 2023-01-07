// rms.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include<iostream>
#include <windows.h>
#include <process.h>
#include <conio.h>
#pragma comment(lib, "..\\Debug\\rmsDLL.lib")
#include "..\rmsDLL\Ado.h"��
#include "..\rmsDLL\Menu.h"��
#include "..\rmsDLL\Employee.h"��
#include "..\rmsDLL\menuAction.h"��
#include "..\rmsDLL\EmployeeAction.h"��


using namespace std;


void mainHandling();
void searchHandle();
void managementHandle();
void managementMenuHandle();
void managementEmployeeHandle();
void start();
void threadHandle();


ADO ado(3);//ѡ�� access
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
	//cout << (result ? "�ɹ��������ݿ�" : "���ݿ�����ʧ��") << endl;

	start();


}


//�����ѯ
void searchHandle(){
	char choice;
	system("cls");
	cout << "��ѡ���ѯ���󣺲˵���A��Ա����B��" << endl;
	cin >> choice;
	if (choice == 'a' || choice == 'A'){
		cout << endl << "�˵������б�:" << endl;
		mAction.showMenu();
		cout << endl;
		char foodName[50];
		cout << "������Ҫ��ѯ�Ĳ�Ʒ�����ƣ�";
		cin >> foodName;
		system("cls");
		cout << "��ѯ���:";
		mAction.searchFood(foodName);
		start();
	}
	else if (choice == 'b' || choice == 'B'){
		cout << endl << "Ա�������б�:" << endl;
		eAction.showAllEmployee();
		cout << endl;
		char name[50];
		cout << "������Ҫ��ѯ��Ա����������";
		cin >> name;
		system("cls");
		cout << "��ѯ���:";
		eAction.searchEmployee(name);
		start();
	}
}

//�������
void managementHandle(){
	system("cls");
	char choice;
	cout << "��ѡ�������󣺲˵���A��Ա����B��" << endl;
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

//����˵�����
void managementMenuHandle(){

	char choice;

	cout << "*****************************�˵�����****************************" << endl << endl;
	//չʾ�˵���
	cout << "�����˵��б�:" << endl;
	mAction.showMenu();;
	cout << endl;

	cout << "��ѡ�����������ͣ� ���ӣ�A��ɾ����B���޸ģ�C��" << endl;
	cin >> choice;


	if (choice == 'a' || choice == 'A'){
		char foodName[50], foodPrice[10];
		cout << "�������²�Ʒ���ƣ�";
		cin >> foodName;
		cout << "�������²�Ʒ�۸�";
		cin >> foodPrice;
		mAction.addFood(foodName, foodPrice);

		system("cls");
		//չʾ�˵���
		cout << "��Ӻ������˵��б�:" << endl;
		mAction.showMenu();
		start();
	}
	else if (choice == 'b' || choice == 'B'){
		char id[10];
		cout << "������Ҫɾ���Ĳ�Ʒ��id:";
		cin >> id;
		mAction.deleteFood(id);
		system("cls");
		//չʾ�˵���
		cout << "ɾ���������˵��б�:" << endl;
		mAction.showMenu();
		start();
	}
	else if (choice == 'c' || choice == 'C'){
		char id[10];
		char foodName[50], foodPrice[20];

		cout << "������Ҫ�޸ĵĲ�Ʒ��id:";
		cin >> id;
		cout << "�������Ʒ��������:";
		cin >> foodName;
		cout << "�������Ʒ���¼۸�:";
		cin >> foodPrice;

		mAction.updateFood(id, foodName, foodPrice);
		system("cls");
		//չʾ�˵���
		cout << "�޸ĺ������˵��б�:" << endl;
		mAction.showMenu();
		start();
	}
}

//����Ա������
void managementEmployeeHandle(){
	char choice;

	cout << "*****************************Ա������****************************" << endl << endl;

	//չʾԱ����
	eAction.showAllEmployee();
	cout << endl;

	cout << "��ѡ�����������ͣ� ���ӣ�A��ɾ����B���޸ģ�C��" << endl;
	cin >> choice;


	if (choice == 'a' || choice == 'A'){
		char name[50], role[10];
		cout << "��������Ա��������";
		cin >> name;
		cout << "��������Ա��ְλ��";
		cin >> role;
		eAction.addEmployee(name, role);
		system("cls");
		cout << "��Ӻ�����Ա����" << endl;
		//չʾԱ����
		eAction.showAllEmployee();;
		start();
	}
	else if (choice == 'b' || choice == 'B'){
		char id[10];
		cout << "������Ҫɾ����Ա����id:";
		cin >> id;
		eAction.deleteEmployee(id);
		system("cls");
		cout << "ɾ��������Ա����" << endl;
		//չʾԱ����
		eAction.showAllEmployee();
		start();
	}
	else if (choice == 'c' || choice == 'C'){
		char id[10];
		char name[50], role[20];

		cout << "������Ҫ�޸ĵ�Ա����id:";
		cin >> id;
		cout << "������Ա����������:";
		cin >> name;
		cout << "������Ա������ְλ:";
		cin >> role;

		eAction.updateEmployee(id, name, role);
		system("cls");
		cout << "�޸ĺ�����Ա����" << endl;
		//չʾԱ����
		eAction.showAllEmployee();
		start();
	}
}

void start(){
	char choice;

	cout << endl;
	cout << "----------------------------- �ָ��� ----------------------------" << endl;
	cout << endl;
	cout << "*****************************************************************" << endl;
	cout << "*****************************************************************" << endl;
	cout << "*****************************************************************" << endl;
	cout << "*************************�⻪��������ϵͳ************************" << endl;
	cout << "*****************************************************************" << endl;
	cout << "*****************************************************************" << endl;
	cout << "*****************************************************************" << endl << endl << endl << endl;

	cout << "��ѡ��������ͣ� ���ģ�S) ����M����Esc����ʱ�˳�" << endl;
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