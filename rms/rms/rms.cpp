// rms.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include<iostream>
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


ADO ado(3);//ѡ�� access
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
	cout << "**************************�⻪��������ϵͳ***********************" << endl;
	cout << "*****************************************************************" << endl;
	cout << "*****************************************************************" << endl;
	cout << "*****************************************************************" << endl;

	cout << "��ѡ��������ͣ� ���ģ�S) ����M����Q����ʱ�˳�" << endl;
	cin >> choice;

	if (choice == 's' || choice == 'S'){
		searchHandle();
	}
	else if (choice == 'm' || choice == 'M'){
		managementHandle();
	}




	system("pause");
}


//�����ѯ
void searchHandle(){

}

//�������
void managementHandle(){
	//system("cls");
	//
	char choice;
	cout << "��ѡ�������󣺲˵���A��Ա����B��" << endl;
	cin >> choice;
	if (choice == 'a' || choice == 'A'){
		managementMenuHandle();
	}
	else if (choice == 'b' || choice == 'B'){
		managementEmployeeHandle();
	}

}

//����˵�����
void managementMenuHandle(){
	
	char choice;

	cout << "*******�˵�����*******" << endl;

	//չʾ�˵���
	mAction.showMenu();;

	cout << "��ѡ�����������ͣ� ���ӣ�A��ɾ����B���޸ģ�C��"<< endl;
	cin >> choice;

	
	if (choice == 'a' || choice == 'A'){
		char foodName[50], foodPrice[10];
		cout << "�������²�Ʒ���ƣ�";
		cin >> foodName;
		cout << "�������²�Ʒ�۸�";
		cin >> foodPrice;
		mAction.addFood(foodName, foodPrice);
		//չʾ�˵���
		mAction.showMenu();
	}
	else if (choice == 'b' || choice == 'B'){
		char id[10];
		cout << "������Ҫɾ���Ĳ�Ʒ��id:";
		cin >> id;
		mAction.deleteFood(id);
		//չʾ�˵���
		mAction.showMenu();
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

		mAction.updateFood(id,foodName,foodPrice);
		//չʾ�˵���
		mAction.showMenu();
	}
}

//����Ա������
void managementEmployeeHandle(){
	char choice;

	cout << "*******Ա������*******" << endl;

	//չʾԱ����
	eAction.showAllEmployee();

	cout << "��ѡ�����������ͣ� ���ӣ�A��ɾ����B���޸ģ�C��" << endl;
	cin >> choice;


	if (choice == 'a' || choice == 'A'){
		char name[50], role[10];
		cout << "��������Ա��������";
		cin >> name;
		cout << "��������Ա��ְλ��";
		cin >> role;
		eAction.addEmployee(name, role);
		//չʾԱ����
		eAction.showAllEmployee();;
	}
	else if (choice == 'b' || choice == 'B'){
		char id[10];
		cout << "������Ҫɾ����Ա����id:";
		cin >> id;
		eAction.deleteEmployee(id);
		//չʾԱ����
		eAction.showAllEmployee();
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
		//չʾԱ����
		eAction.showAllEmployee();
	}
}