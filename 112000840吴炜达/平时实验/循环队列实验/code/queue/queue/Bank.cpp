#include "Bank.h"

using namespace std;
void Bank::Create_Customer_thread()//;//���̰߳汾 �����û�������� ��Ҫһ���������߳�
{
	while (1)
	{
		int arrive = rand() % 8 + 1 + arr_time;//�������һ���û�������� 1-8����һ��
		std::this_thread::sleep_for(std::chrono::milliseconds(arrive - arr_time + 500));
		//std::this_thread::sleep_for(std::chrono::seconds(arrive- arr_time));
		if (arrive > close_time2)
		{
			print_time(arrive);
			cout << "�Ѿ������� ��������" << endl;
			exit = true;
			break;
		}

		arr_time = arrive;
		//bool empty = que.empty();//�ж�֮ǰ�Ƿ�Ϊ��
		std::unique_lock<std::mutex> lk(mutex_t);//��ס
		Customer cust(num_customer, arrive);//���̰߳汾 ����ҵ��ʱ�����̺߳���������
		//que.push(cust);
		queue.PushQueue(cust);
		num_customer++;
		cond.notify_one();

	}
}
void Bank::Create_thread()
{
	for (int i = 0; i < num_win; i++)
	{
		printf("����%d����\n", i + 1);
		wins_thread.emplace_back(std::thread(&Bank::Customer_into_thread, this, i));
		std::condition_variable temp;
		//conds.push_back(temp);
	}
};
void Bank::Del_thread() //��ֹ�߳�
{
	for (int i = 0; i < wins_thread.size(); i++)
	{
		wins_thread[i].join();

	}
}
void Bank::Customer_into_thread(int i)//;//�˿ʹ����� i�����±�
{
	while (1)
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
		std::unique_lock<std::mutex> lk(mutex_t);//������ ��ס

		//��ʵ�����ڲ����æ
		//while (que.empty() || win_v[i].is_busy())//������пջ��ߴ��ں�æ �ȴ�
		while (queue.IsQueueEmpty() || win_v[i].is_busy())//������пջ��ߴ��ں�æ �ȴ�
		{
			//if(win_v[i].is_busy())printf("����%d��æ\n",i+1);
			//if(que.empty())printf("���п� ����%d����\n",i+1);
			cond.wait(lk);
		}

		//if (que.empty() && exit)
		if (queue.IsQueueEmpty() && exit)
		{
			cond.notify_all();
			break;//�����°���
		}
		//��æ�Ҷ��в���
		Customer c = queue.GetHead();
		//Customer c = que.front();
		//que.pop();
		queue.PopQueue();
		//lk.unlock();
		if (c.get_arrive_time() > last)
		{
			cout << c.get_id() << "�� ����:";
			print_time(c.get_arrive_time());
			cout << "׼�������� ��������" << endl;
			cond.notify_all();
		}
		else
		{
			int process = rand() % 20 + 1 + 5;//ҵ�����ʱ��  5-25min
			c.set_process_time(process);
			Win_Customer_thread(i, c);
		}

	}
	//Del_thread();
}

void Bank::Win_Customer_thread(int pos, Customer c)//�˿Ͱ���ҵ��  ���w���봫ʵ�� ��Ϊ���ڻ���
{
	win_v[pos].set_busy();
	c.set_wait_time(win_v[pos].get_last_time());
	cout << "����:" << win_v[pos].get_num() + 1 << " ";
	print_cust(c);
	win_v[pos].set_last_time(c.get_leave_time());//���ڸ���ʱ��
	cout << endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(c.get_process_time()));
	win_v[pos].set_nobusy();
}


void Bank::Main_thread()//;
{
	Create_thread();
	Create_Customer_thread();
	//Create_thread();
}

// void Bank::Main()
// {

//     Create_Customer();
//     Customer_into();
// }

void Bank::print_time(int time)//time�Ƿ���
{
	int hour = time / 60 + open_time;
	int min = time % 60;
	cout << hour << ":" << min << " ";
};

void Bank::print_cust(Customer c)
{
	cout << c.get_id() << "�� ����:";
	print_time(c.get_arrive_time());
	cout << " �뿪:";
	print_time(c.get_leave_time());
	cout << " �ȴ�:" << c.get_wait_time();

	//print_time(c.get_wait_time());
	cout << " ��ʼ����:";
	print_time(c.get_start_time());
	cout << " ҵ��ʱ��:" << c.get_process_time();
	//print_time(c.get_process_time());
	cout << " ��ʱ��:" << c.get_total_time()<<endl;
	cout << c.get_id()<<" �ſͻ������," << c.get_id()+1<<"�ſͻ����Խ���ҵ�����"<<endl;
	//print_time(c.get_total_time());
}