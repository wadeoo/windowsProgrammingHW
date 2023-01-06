#pragma once
#ifndef Win_h
#define Win_h

#include <stdio.h>
class Win
{
private:
	int num;//���ں���
	bool isbusy;
	int last_time;//��һ���ս�����ʱ�� 
public:
	Win()
	{
		isbusy = false;
		last_time = 0;
	};
	void set_num(int n)
	{
		num = n;
	}

	void set_busy()
	{
		isbusy = true;
	}
	void set_nobusy()
	{
		isbusy = false;
	}
	void set_last_time(int time)
	{
		last_time = time;
	}
	inline int get_last_time()
	{
		return last_time;
	}
	inline int get_num()
	{
		return num;
	}
	inline bool is_busy()
	{
		return isbusy;
	}
};
#endif /* Win_h */