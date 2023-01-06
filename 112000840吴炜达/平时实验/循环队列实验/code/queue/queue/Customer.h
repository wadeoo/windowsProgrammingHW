#pragma once
#ifndef Customer_h
#define Customer_h
#include <stdio.h>
#include <iostream>
#include<cstdlib>
using namespace std;
class Customer
{
private:
	//ʱ��ȫ��Ϊ����֮��Ķ��ٷ���
	int id;//�˿�id
	//int win;//���Ǹ����ڰ���
	int arrive_time;//����ʱ��
	int leave_time;//�뿪ʱ��
	int wait_time;//�ȴ�ʱ��
	int start_time;//��ʼ����ҵ��ʱ��
	int process_time;//����ҵ�����ʱ��
	int total_time;//�����д���ʱ��
public:
	//Customer(int num, int time1, int time2) :id(num), arrive_time(time1), process_time(time2)
	//{

	//};
	Customer(int num, int time1) :id(num), arrive_time(time1)//���̰߳汾 ҵ��ʱ�䲻�ż�����
	{

	};

	Customer(){};

	inline int get_id()
	{
		return id;
	}

	//����ʱ��
	inline void set_arrive_time(int time)
	{
		arrive_time = time;
	}
	inline int get_arrive_time()
	{
		return arrive_time;
	}
	//�뿪ʱ��
	inline int get_leave_time()
	{
		leave_time = start_time + process_time;
		return leave_time;
	}
	//ҵ��ʼʱ��
	inline int get_start_time()
	{
		return start_time;
	}
	//�ȴ�ʱ��
	inline void set_wait_time(int time)//�����Ǵ�����һ���û�����ʱ��
	{
		if (arrive_time >= time)//���õȴ�
		{
			wait_time = 0;
		}
		else
		{
			wait_time = time - arrive_time;
		}
		start_time = arrive_time + wait_time;
	}
	inline int get_wait_time()
	{
		return wait_time;
	}
	//ҵ��ʱ��
	inline void set_process_time(int time)
	{
		process_time = time;
	}

	inline int get_process_time()
	{
		return process_time;
	}
	//��ʱ��
	inline int get_total_time()
	{
		return leave_time - arrive_time;
	}

};
#endif /* Customer_h */