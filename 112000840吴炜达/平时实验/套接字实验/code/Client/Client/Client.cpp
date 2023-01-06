// Client.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"

#include "stdio.h"
#include "winsock2.h"
#include "stdlib.h"

#pragma comment(lib,"ws2_32")


//���ܷ������㲥����Ϣ
DWORD WINAPI ProcessRecvServerResponse(LPVOID lpParam)
{
	SOCKET* serverSocket = (SOCKET*)lpParam;
	while (TRUE)
	{
		char buffer1[MAXBYTE] = { 0 };
		recv(*serverSocket, buffer1, MAXBYTE, NULL);
		printf("\n������: %s\n", buffer1);
	}
	return 0;
}

void main()
{
	WSADATA wsaData;
	WSAStartup(MAKEWORD(2, 2), &wsaData);

	HANDLE threadForRecvingServer;//���߳��������Ͻ��շ�������Ϣ

	SOCKET s = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
	sockaddr_in sockaddr;
	sockaddr.sin_family = PF_INET;
	sockaddr.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");
	sockaddr.sin_port = htons(9000);

	connect(s, (SOCKADDR*)&sockaddr, sizeof(SOCKADDR));

	printf("***�ͻ���***\n");
	char buffer[MAXBYTE] = { 0 };
	recv(s, buffer, MAXBYTE, NULL);
	printf("������: %s", buffer);
		
	threadForRecvingServer = CreateThread(NULL, 0, &ProcessRecvServerResponse, &s, 0, NULL);

	while (TRUE)
	{
		//�ͻ����������������Ϣ
		getchar();
		char* mymsg = new char[10000];
		printf("��������Ϣ\n ->");
		gets(mymsg);
		send(s, mymsg, strlen(mymsg) + sizeof(char), NULL);


		//���ͻ��˷���"�˳�"ʱ����
		if (strcmp(mymsg, "�˳�") == 0){
			char* buffer2 = new char[1000];
			recv(s, buffer2, MAXBYTE, NULL);
			printf("��������: %s\n", buffer2);
			if (strcmp(buffer2, "�ټ�") == 0)
			{
				break;
			}
			break;
		}
	}

	WaitForMultipleObjects(1, &threadForRecvingServer, TRUE, INFINITE);
	CloseHandle(threadForRecvingServer);

	closesocket(s);
	WSACleanup();
	getchar();
	exit(0);

}