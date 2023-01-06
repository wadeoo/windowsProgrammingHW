#pragma once
#ifndef Bank_h
#define Bank_h

#include <stdio.h>
#include <iostream>
#include <queue>
#include <cstdlib>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <chrono>
#include "Customer.h"
#include "Queue.h"
#include "Win.h"

class Bank
{
private:
	bool exit;//�Ƿ����������߳�
	std::mutex mutex_t;
	std::condition_variable cond;//���пյ���������
	//std::condition_variable conds;//ÿ�����ڷ�æ����������
	std::vector<std::thread> wins_thread;//�̴߳��� ÿ���̶߳�Ӧ�±���ͬ�Ĵ���


	int open_time;//����ʱ�� ������� ���Ǽ���
	int close_time;//����ʱ�� ������� ���Ǽ���
	int close_time2;//����ʱ�� ���ź����
	int last;//  ת���ɿ��ź�ķ��� �������ȡ�ŵ�ʱ��
	int arr_time;//( ��һ���˿�����ʱ��) ͨ��������������˿�˳����
	int num_customer;//�˿�����
	int num_win;//��������
	std::vector<Win> win_v;//��������
	//std::queue<Customer> que;//�˿Ͷ���
	Queue queue;

public:
	Bank(int t1, int t2, int num) :open_time(t1), close_time(t2), num_win(num)
	{
		close_time2 = (close_time - open_time) * 60;
		last = (close_time - open_time) * 60 - 20;//��ǰ��ʮ���Ӳ���ȡ��
		arr_time = 0;
		num_customer = 0;
		for (int i = 0; i<num_win; i++)
		{
			Win w;
			w.set_num(i);
			win_v.emplace_back(w);
		}
	};
	~Bank() { Del_thread(); };
	void Create_Customer_thread();//���̰߳汾 �����û�������� ��Ҫһ���������߳�
	void Create_thread();//�����߳�
	void Del_thread(); //��ֹ�߳�
	void Customer_into_thread(int i);//�˿ʹ����� i�����±�
	void Win_Customer_thread(int pos, Customer c);
	void Main_thread();

	//void Main();
	//void Create_Customer();//�����û��������
	//void Customer_into();//�˿ʹ�����
	//void Win_Customer(int pos, Customer);//�˿Ͱ���ҵ��
	void print_time(int time);//��ӡʱ��Ϊʱ��������
	void print_cust(Customer c);//�˿��뿪 ��ӡ�˿���Ϣ

};
#endif /* Bank_h */