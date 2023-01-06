///////////////////////////////////////////////////////////////
// CriticalSection.cpp�ļ�

#include "stdafx.h"
#include <stdio.h>
#include <windows.h>
#include <process.h>
#include <iostream>
#include <string>

BOOL g_bContinue = TRUE;
int g_nCount = 0;
int c1 = 0, c2 = 0, c3 = 0;
int count4 = 0;

UINT uId1,uId2,uId3;
CRITICAL_SECTION g_cs; // �Դ���ͬ������Ĵ����ʹ���ٽ�������

UINT __stdcall ThreadFunc(LPVOID);

int main(int argc, char* argv[])
{

	HANDLE h[3];

	// ��ʼ���ٽ�������
	::InitializeCriticalSection(&g_cs);


	h[0] = (HANDLE)::_beginthreadex(NULL, 0, ThreadFunc, NULL, 0, &uId1);
	h[1] = (HANDLE)::_beginthreadex(NULL, 0, ThreadFunc, NULL, 0, &uId2);
	h[2] = (HANDLE)::_beginthreadex(NULL, 0, ThreadFunc, NULL, 0, &uId3);



	::WaitForMultipleObjects(3, h, TRUE, INFINITE);
	::CloseHandle(h[0]);
	::CloseHandle(h[1]);
	::CloseHandle(h[2]);

	// ɾ���ٽ�������
	::DeleteCriticalSection(&g_cs);

		std::cout << "Ʊ�Ѿ�����" << std::endl;
		std::cout << "1�Ŵ�������" << c1 << "Ʊ" << std::endl;
		std::cout << "2�Ŵ�������" << c2 << "Ʊ" << std::endl;
		std::cout << "3�Ŵ�������" << c3 << "Ʊ" << std::endl;
		std::cout << count4<<std::endl;
	



	system("pause");

	return 0;
}

UINT __stdcall ThreadFunc(LPVOID)
{
	while (g_bContinue)
	{
		::EnterCriticalSection(&g_cs);
		if (g_nCount < 60){

			UINT threadId = GetCurrentThreadId();

			if (threadId == uId1){
				g_nCount++;
				c1++;
				std::cout << "1�Ŵ��۳���"<<g_nCount<<"Ʊ" << std::endl;
			}
			else if (threadId == uId2){
				g_nCount++;
				c2++;
				std::cout << "2�Ŵ��۳���"<<g_nCount<<"Ʊ" << std::endl;
			}
			else if (threadId == uId3){
				g_nCount++;
				c3++;
				std::cout << "3�Ŵ��۳���"<<g_nCount<<"Ʊ" << std::endl;
			}
		}
		else
		{
			g_bContinue = false;
		}
		::Sleep(30);
		::LeaveCriticalSection(&g_cs);
	}

	return 0;
}



//
//// SellTickets.cpp : �������̨Ӧ�ó������ڵ㡣
////
//
//#include "stdafx.h"
//#include<process.h>
//#include<Windows.h>
//
//UINT __stdcall SellThread(LPVOID);
//CRITICAL_SECTION g_cs;
//int ticket = 1;
//BOOL bContinue = true;
//
//
//int _tmain(int argc, _TCHAR* argv[])
//{
//	UINT uId;
//	HANDLE h[3];
//
//	// ��ʼ���ٽ�������
//	::InitializeCriticalSection(&g_cs);
//
//	//������Ʊ����
//	h[0] = (HANDLE)::_beginthreadex(NULL, 0, SellThread, NULL, 0, &uId);
//	h[1] = (HANDLE)::_beginthreadex(NULL, 0, SellThread, NULL, 0, &uId);
//	h[2] = (HANDLE)::_beginthreadex(NULL, 0, SellThread, NULL, 0, &uId);
//	printf("%s", "������������Ʊ��ʼ��\n");
//
//
//	//�ȴ������߳�ִ�����
//	WaitForMultipleObjects(3, h, TRUE, INFINITE);
//
//	//Ʊ�����������Ʊ����
//	::CloseHandle(h[0]);
//	::CloseHandle(h[1]);
//	::CloseHandle(h[2]);
//
//	// ɾ���ٽ�������
//	::DeleteCriticalSection(&g_cs);
//
//	printf("%s", "������������Ʊ������\n");
//
//	system("pause");
//
//	return 0;
//}
//
//UINT __stdcall SellThread(LPVOID) {
//
//	while (bContinue) {
//		::EnterCriticalSection(&g_cs);
//		if (ticket<61)
//		printf("����%d ������%d��Ʊ,��ʣ%d��Ʊ\n", GetCurrentThreadId(), ticket++, 61 - ticket);
//		else
//		{
//			bContinue = false;
//		}
//		::LeaveCriticalSection(&g_cs);
//		Sleep(30);
//	}
//
//
//	return 0;
//}