// ServerMT.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "stdio.h"
#include "winsock2.h"
#include "stdlib.h"
#define MAXCLIENTS 2

#pragma comment(lib,"ws2_32")
/*
���߳�
SOCKET
*/

DWORD WINAPI ProcessRecvClientResponse(LPVOID lpParam)
{
	SOCKET* clientsocket = (SOCKET*)lpParam;
	char* msg = "���ѳɹ�������������\r\n";
	send(*clientsocket, msg, strlen(msg) + sizeof(char), NULL);
	while (TRUE)
	{
		char buffer[MAXBYTE] = { 0 };
		recv(*clientsocket, buffer, MAXBYTE, NULL);
		if (strcmp(buffer, "�˳�") == 0)
		{
			char* exit_msg = "�ټ� \r\n";
			send(*clientsocket, exit_msg, strlen(exit_msg) + sizeof(char), NULL);
			printf("һ���ͻ������˳�\n");
			break;
		}
		printf("\n�ͻ���: %s\n", buffer);
	}
	closesocket(*clientsocket);
	return 0;
}

DWORD WINAPI ProcessSendServerResponse(LPVOID lpParam)
{
	SOCKET* clientsocket = (SOCKET*)lpParam;
	while (TRUE)
	{
		getchar();
		char* mymsg = new char[10000];
		printf("��������Ϣ\n ->");
		gets(mymsg);
		send(*clientsocket, mymsg, strlen(mymsg) + sizeof(char), NULL);
	}
	closesocket(*clientsocket);
	return 0;
}


int main()
{
	WSADATA wsaData;
	WSAStartup(MAKEWORD(2, 2), &wsaData);


	SOCKET s = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);

	sockaddr_in sockaddr;
	sockaddr.sin_family = PF_INET;
	sockaddr.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");
	sockaddr.sin_port = htons(9000);

	bind(s, (SOCKADDR*)&sockaddr, sizeof(SOCKADDR));

	listen(s, 1);

	printf("***��������***\n");
	printf("���ڼ����˿�[%d].\n", 9000);

	char* msg = new char[1000];

	HANDLE threads[MAXCLIENTS];    //�̴߳�� ����
	HANDLE threads2;
	int CountClient = 0;
	while (TRUE)
	{
		SOCKADDR clientAddr;
		int size = sizeof(SOCKADDR);
		SOCKET clientsocket;
		clientsocket = accept(s, &clientAddr, &size);        //����ģʽ ֱ�����µ�Tcp ����
		if (CountClient < MAXCLIENTS)                        //�������߳�
		{
			threads[CountClient++] = CreateThread(NULL, 0, &ProcessRecvClientResponse, &clientsocket, 0, NULL);
			threads2= CreateThread(NULL, 0, &ProcessSendServerResponse, &clientsocket, 0, NULL);
		}
		else                                                //�߳������� �ܾ�����
		{
			char *msg = "����������,�Ѿܾ�����!.\r\n";
			send(clientsocket, msg, strlen(msg) + sizeof(char), NULL);
			printf("�µĿͻ��˳�������,�����������ܾ�.\n");
			closesocket(clientsocket);
			break;
		}
		printf("�µĿͻ��������� id: %d .\n", CountClient);            //
	}

	printf("�ͻ��������Ѵﵽ���ֵ: %d.\r\n", MAXCLIENTS);
	WaitForMultipleObjects(MAXCLIENTS, threads, TRUE, INFINITE);
	WaitForMultipleObjects(1, &threads2, TRUE, INFINITE);

	closesocket(s); //�ر�socket

	for (int i = 0; i < MAXCLIENTS; i++)
	{
		CloseHandle(threads[i]);
	}
	CloseHandle(threads2);

	WSACleanup();
	getchar();
	exit(0);
	return 0;
}