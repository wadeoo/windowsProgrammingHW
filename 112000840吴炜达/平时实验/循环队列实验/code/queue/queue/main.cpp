#include "Queue.h"
#include <iostream>
#include <string>
#include "Bank.h"
static std::string  getCurrentTimeStr()
{
	time_t t = time(NULL);
	char ch[64] = { 0 };
	strftime(ch, sizeof(ch)-1, "%Y-%m-%d %H:%M:%S", localtime(&t));     //��-��-�� ʱ-��-��
	return ch;
}

int main(int argc, const char * argv[])
{
	 int win_num = 4;
	//std::cout <<   getCurrentTimeStr()<<"\n";
	int time1, time2;
	std::cout << "======================��ӭ���ٴ�����======================" << std::endl;
	std::cout << "���������п��ź͹���ʱ�䣬9:00-12:00��������9 12" << "\n";
	cin >> time1 >> time2;
	std::cout << "��������:" <<  std::endl;
	cin >> win_num;
	Bank b(time1, time2, win_num);
	b.Main_thread();
	return 0;
}