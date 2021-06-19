#include"pch.h"
#include"elevator.h"
#include<iostream>
using namespace std;
double elevator::u = 0;
elevator::elevator(int f = 0)
{
	int t = 0;
	maxf = f;
	for (int i = 0; i <= f; i++)
	{
		button.push_back(t);
		in.push_back(t);
		out.push_back(t);
	}
	numbers = 0;
	curf = 1;
	run_status = 0;
}
void elevator::set_now(int flag)  //���õ�������¥��
{
	curf = flag;
}
void elevator::set_status(int i)  //���õ���״̬
{
	run_status = i;
}
void elevator::set_button(int i, int flag)   //���õ����ڲ��Ƶ�����
{
	button[i] = flag;
}
void elevator::set_in(int i, int flag)  //���õ����ڲ���ť
{
	in[i] = flag;
}
void elevator::inoperate(int i)  //�����ڲ��˰��İ���
{
	int f, before = 0;
	cout << "�������ݵĳ˿Ͱ�����Ҫ�����¥��" << endl;
	cout << "���¥��֮���ÿո����,�����밴0:";
	while (1)
	{
		cin >> f;
		if (f == 0)
			break;
		else if (f > maxf || f < 1)
		{
			cout << "�������󣬳���¥�㷶Χ�Ľ��������\n";
			continue;
		}
		else if (before == f)  //�ж���һ�κ���һ���Ƿ����
		{
			numbers--;
			set_button(f, 0);
			set_in(f, 0);
			p.erase(p.end() - 1);
			u--;
			before = 0;
		}
		else          //�������˿���Ϣ����
		{
			numbers++;
			p.emplace_back(++u, i, f);
			set_button(f, 1);
			set_in(f, 1);
			before = f;
		}
	}
}
void elevator::set_out(int i, int flag)   //���õ����ⲿ��ť
{
	out[i] = flag;
}
int elevator::get_out(int i)  //����ⲿ��ť��ֵ  
{
	return out[i];
}
int elevator::get_status()  //��õ���״̬
{
	return run_status;
}
int elevator::get_in(int i)  //����ڲ���ť��ֵ  
{
	return in[i];
}
int elevator::get_button(int i)   //��õ����ڲ���ť������
{
	return button[i];
}
int elevator::get_now()  //��õ�������¥��
{
	return curf;
}
void elevator::outoperate()   //�����ⲿ�˰��İ���
{
	int f, before = 0, m;
	cout << "�������ĸ�¥����¥(���¥���ÿո����,���������밴0):";
	while (1)
	{
		cin >> f;
		if (f == 0)
			break;
		else if (f >= maxf || f < 1)
		{
			cout << "�������󣬳���¥�㷶Χ�Ľ��������\n";
			continue;
		}
		else if (before == f)  //�ж���һ�κ���һ���Ƿ����
		{
			set_out(f, m);
			before = 0;
			continue;
		}
		else if (get_out(f) == 2)  //�������֮ǰ���˰����£��ͱ�Ϊ���¶���
		{
			m = get_out(f);
			set_out(f, 3);
			before = f;
		}
		else {
			m = get_out(f);
			set_out(f, 1);
			before = f;
		}
	}
	before = 0, m = 0;
	cout << "�������ĸ�¥����¥(���¥���ÿո����,���������밴0):";
	while (1)
	{
		cin >> f;
		if (f == 0)
			break;
		else if (f <= 1 || f > maxf)
		{
			cout << "�������󣬳���¥�㷶Χ�Ľ��������\n";
			continue;
		}
		else if (before == f)   //�ж���һ�κ���һ���Ƿ����
		{
			set_out(f, m);
			before = 0;
			continue;
		}
		else if (get_out(f) == 1) ////�������֮ǰ���˰����ϣ��ͱ�Ϊ���¶���
		{
			m = get_out(f);
			set_out(f, 3);
			before = f;
		}
		else
		{
			m = get_out(f);
			set_out(f, 2);
			before = f;
		}
	}
}