// rms.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include<iostream>
#pragma comment(lib, "..\\Debug\\rmsDLL.lib")
#include "..\rmsDLL\Ado.h"��
#include "..\rmsDLL\Menu.h"��
#include "..\rmsDLL\Employee.h"��


using namespace std;


void mainHandling();
void searchHandle();
void managementHandle();
void managementMenuHandle();
void managementEmployeeHandle();


ADO ado(3);//ѡ�� access

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
	cout << "��ѡ�����������ͣ� ���ӣ�A��ɾ����B���޸ģ�C��"<< endl;
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

//����Ա������
void managementEmployeeHandle(){

}