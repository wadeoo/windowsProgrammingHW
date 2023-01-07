//#pragma once
#ifndef ADO_H
#define ADO_H
#include <stdio.h>
#include <tchar.h>
#import "C:\\Program Files\\Common Files\\System\\ado\\msado15.dll" no_namespace rename("EOF", "adoEOF")

//���ݿ�����
enum dbType_enum{
	SqlServer,
	MySql,
	Access
};

#ifdef DLL_FILE
class _declspec(dllexport) ADO //������
#else
class _declspec(dllimport) ADO //������
#endif
{
public:
	ADO(int t = 3); //Ĭ������access���ݿ�
	~ADO();
public:
	::_ConnectionPtr m_pConnection;//����API
	::_RecordsetPtr m_pRecordset;//���ݼ�����

	////ѡ�����ݿ��ѡ��δ����
	//const static int type_SqlSever = 1;
	//const static int type_MySql = 2;
	//const static int type_Access = 3;

public:
	int InitConn(char* username, char* password, char* database);
	int Exit();//�ر�����

	void ShowCurrentRS(bool bWithName);//��ʾ��ǰ�����ݼ�
	void ShowColumnNames(char* table);

	int GetTableInfo(char* table);//������ű����Ϣ
	int Query(char* table, char* pCondition);
	int Add(char *table, char** pContent, int Cnum);//��ӱ����Ϣ,���������ݿ�˳����е����ݣ��е�����
	int Delete(char* table, char* pConditon);//ɾ�������Ϣ
	bool Update(char* table, char* pContent, char* pCondition);

	//��ȡ���ȫ������
	int GetColNum(char* table);
	//��ȡĳ�ű�ȫ����¼������
	int GetRSNum(char* table);

	//ִ��sql���
	int QuerySQL(char* sql);
	int ExcuteSQL(char* sql);


private:
	int generateConnString(_bstr_t database);
	dbType_enum m_dbType;
	_bstr_t m_username;
	_bstr_t m_password;
};

#endif