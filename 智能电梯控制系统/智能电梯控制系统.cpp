#include "pch.h"
#include <iostream>
#include<string>
#include<vector>
#include<windows.h>
#include<conio.h>
#include"elevator.h"
#include"build.h"
#include"control.h"
using namespace std;
int main()
{
	build a(9);
	int e = 9;
	a.printout(1);
	a.printin();
	a.eleva.outoperate();
	a.eleva.set_status(1);
	while (1)
	{
		if (a.eleva.get_status() == 1)    //���ݴ�������״̬
		{
			for (int i = a.eleva.get_now(); i <= e; i++)
			{
				if (a.eleva.get_in(i) == 1 && a.eleva.get_out(i) != 0)  //�ڲ��˰��ĵ��ݵ��ˣ����ⲿ�˰��˵���
				{
					if (a.eleva.get_now() != i)
						i = up(a, i);
					Sleep(2000);
					system("cls");
					a.eleva.set_button(i, 0);
					a.eleva.set_in(i, 0);
					a.printout_light(i);
					a.printin();
					cout << "�������ѿ���\n";
					auto y = a.eleva.p.begin();
					while (y != a.eleva.p.end()) //�˿��µ��ݺ�ɾ��������Ϣ
					{
						if (y->to == i)
						{
							cout << "��" << y->id << "�ų˿��µ���\n";
							y = a.eleva.p.erase(y);
							a.eleva.numbers--;
						}
						else y++;
					}
					if (a.eleva.get_out(i) == 2)    //2�����ⲿ���˰����£��ж��Ƿ�Ӧ������ͣ����������Ϸ����˰��ϣ������д�������״̬�����Ͳ������������
					{
						int flag = 0;
						for (int t = i; t <= e; t++)
						{
							if (a.eleva.get_out(t) == 1 || a.eleva.get_out(t) == 3 || a.eleva.get_in(t) == 1)
							{
								flag = 1;
								break;
							}
						}
						if (flag == 1)
							continue;
						int y = 0;
						for (int t = i + 1; t <= e; t++)   //������λ�����ϻ����˰����£����Ͳ��ù�����µ�
						{
							if (a.eleva.get_out(t) == 2)
							{
								y = 1;
								break;
							}
						}
						if (y == 1)
							continue;
					}
					if (a.eleva.get_out(i) == 1 || a.eleva.get_out(i) == 2)
						a.eleva.set_out(i, 0);
					else a.eleva.set_out(i, 2);
					a.eleva.inoperate(i);
					chaozai(a);
					Sleep(2000);
					system("cls");
					a.printout(i);
					a.printin();
					cout << "�������ѹر�\n";
				}
				else if (a.eleva.get_in(i) == 1)//�ڲ��˰��ĵ��ݵ���
				{
					int t = i;
					i = up(a, i);
					if (t != i)
					{
						i--;
						continue;
					}
					Sleep(2000);
					system("cls");
					a.eleva.set_button(i, 0);
					a.eleva.set_in(i, 0);
					a.printout_light(i);
					a.printin();
					cout << "�������ѿ���\n";
					auto y = a.eleva.p.begin();
					while (y != a.eleva.p.end()) //�˿��µ��ݺ�ɾ��������Ϣ
					{
						if (y->to == i)
						{
							cout << "��" << y->id << "�ų˿��µ���\n";
							y = a.eleva.p.erase(y);
							a.eleva.numbers--;
						}
						else y++;
					}
					Sleep(2000);
					system("cls");
					a.printout(i);
					a.printin();
					cout << "�������ѹر�\n";
				}
				else if (a.eleva.get_out(i) != 0)   //�ⲿ���˰����ϵ���
				{
					if (a.eleva.get_out(i) == 2)  //�ж��Ƿ�Ӧ������ͣ����������Ϸ����˰��ϣ������д�������״̬�����Ͳ������������
					{
						int flag = 0;
						for (int t = i; t <= e; t++)
						{
							if (a.eleva.get_out(t) == 1 || a.eleva.get_out(t) == 3 || a.eleva.get_in(t) == 1)
							{
								flag = 1;
								break;
							}
						}
						if (flag == 1)
							continue;
						int y = 0;
						for (int t = i + 1; t <= e; t++)   //������λ�����ϻ����˰����£����Ͳ��ù�����µ�
						{
							if (a.eleva.get_out(t) == 2)
							{
								y = 1;
								break;
							}
						}
						if (y == 1)
							continue;
					}

					if (a.eleva.get_now() != i)
						i = up(a, i);
					Sleep(2000);
					system("cls");
					a.printout_light(i);
					a.printin();
					if (a.eleva.get_out(i) == 1 || a.eleva.get_out(i) == 2)
						a.eleva.set_out(i, 0);
					else
						a.eleva.set_out(i, 2);
					cout << "�������Ѵ�,��˿ͽ���\n";
					a.eleva.inoperate(i);
					chaozai(a);
					Sleep(2000);
					system("cls");
					a.printout(i);
					a.printin();
					cout << "�������ѹر�\n";

				}
			}
			int flag = 1;
			for (int i = 1; i <= e; i++)  //�ж�����¥�Ƿ����˰��˰���������ﻹ����
				if (a.eleva.get_out(i) != 0 || a.eleva.get_in(i) != 0)
				{
					flag = 0;
					break;
				}
			if (flag)
				a.eleva.set_status(0);
			else a.eleva.set_status(2);
		}
		else if (a.eleva.get_status() == 2)  //���ݴ����½�״̬
		{
			for (int i = a.eleva.get_now(); i >= 1; i--)
			{
				if (a.eleva.get_in(i) == 1 && a.eleva.get_out(i) != 0)//�ڲ��˰��ĵ��ݵ��ˣ����ⲿ�˰��˵���
				{
					if (a.eleva.get_now() != i)
						i = down(a, i);
					Sleep(2000);
					system("cls");
					a.eleva.set_button(i, 0);
					a.eleva.set_in(i, 0);
					a.printout_light(i);
					a.printin();
					cout << "�������ѿ���\n";
					auto y = a.eleva.p.begin();
					while (y != a.eleva.p.end())  //�˿��µ��ݺ�ɾ��������Ϣ
					{
						if (y->to == i)
						{
							cout << "��" << y->id << "�ų˿��µ���\n";
							y = a.eleva.p.erase(y);
							a.eleva.numbers--;
						}
						else y++;
					}
					if (a.eleva.get_out(i) == 1)  //�ж��Ƿ�Ӧ������ͣ����������·����˰��£������д����½�״̬�����Ͳ�����������ϵ�
					{
						int flag = 0;
						for (int t = a.eleva.get_now(); t >= 1; t--)
						{
							if (a.eleva.get_out(t) == 2 || a.eleva.get_out(t) == 3 || a.eleva.get_in(t) == 1)
							{
								flag = 1;
								break;
							}
						}
						if (flag == 1)
						{
							continue;
						}
						int y = 0;
						for (int t = i - 1; t >= 1; t--)   //������λ�����»����˰����ϣ����Ͳ��ù�����ϵ�
						{
							if (a.eleva.get_out(t) == 1)
							{
								y = 1;
								break;
							}
						}
						if (y == 1)
							continue;
					}
					a.eleva.inoperate(i);
					if (a.eleva.get_out(i) == 2 || a.eleva.get_out(i) == 1)
						a.eleva.set_out(i, 0);
					else a.eleva.set_out(i, 1);
					chaozai(a);
					Sleep(2000);
					system("cls");
					a.printout(i);
					a.printin();
					cout << "�������ѹر�\n";
				}
				else if (a.eleva.get_in(i) == 1)//�ڲ��˰��ĵ��ݵ���
				{
					int t = i;
					i = down(a, i);
					if (t != i)
					{
						i++;
						continue;
					}
					Sleep(2000);
					system("cls");
					a.eleva.set_button(i, 0);
					a.eleva.set_in(i, 0);
					a.printout_light(i);
					a.printin();
					cout << "�������ѿ���\n";
					auto y = a.eleva.p.begin();
					while (y != a.eleva.p.end())  //�˿��µ��ݺ�ɾ��������Ϣ
					{
						if (y->to == i)
						{
							cout << "��" << y->id << "�ų˿��µ���\n";
							y = a.eleva.p.erase(y);
							a.eleva.numbers--;
						}
						else y++;
					}
					Sleep(2000);
					system("cls");
					a.printout(i);
					a.printin();
					cout << "�������ѹر�\n";
				}
				else if (a.eleva.get_out(i) != 0)//֤���ⲿ���˰��˵���
				{
					if (a.eleva.get_out(i) == 1)  //�ж��Ƿ�Ӧ������ͣ����������·����˰��£������д����½�״̬�����Ͳ�����������ϵ�
					{
						int flag = 0;
						for (int t = a.eleva.get_now(); t >= 1; t--)
						{
							if (a.eleva.get_out(t) == 2 || a.eleva.get_out(t) == 3 || a.eleva.get_in(t) == 1)
							{
								flag = 1;
								break;
							}
						}
						if (flag == 1)
						{
							continue;
						}
						int y = 0;
						for (int t = i - 1; t >= 1; t--)   //������λ�����»����˰����ϣ����Ͳ��ù�����ϵ�
						{
							if (a.eleva.get_out(t) == 1)
							{
								y = 1;
								break;
							}
						}
						if (y == 1)
							continue;
					}
					if (a.eleva.get_now() != i)
						i = down(a, i);
					Sleep(2000);
					system("cls");
					a.printout_light(i);
					a.printin();
					if (a.eleva.get_out(i) == 2 || a.eleva.get_out(i) == 1)
						a.eleva.set_out(i, 0);
					else a.eleva.set_out(i, 1);
					cout << "�������Ѵ�,��˿ͽ���\n";
					a.eleva.inoperate(i);
					chaozai(a);
					Sleep(2000);
					system("cls");
					a.printout(i);
					a.printin();
					cout << "�������ѹر�\n";
				}

			}
			int flag = 1;
			for (int i = 1; i <= e; i++) //�ж�����¥�Ƿ����˰��˰���������ﻹ����
				if (a.eleva.get_out(i) != 0 || a.eleva.get_in(i) != 0)
				{
					flag = 0;
					break;
				}
			if (flag)
				a.eleva.set_status(0);
			else a.eleva.set_status(1);
		}
		else if (a.eleva.get_status() == 0)  //���ݴ��ھ�ֹ״̬
		{
			int f = 1;
			for (int i = 0; i < 10; i++)   //ʮ�������˰����ݣ������Զ���һ¥�������˰�����������
			{
				if (_kbhit())
				{
					f = 0;
					a.eleva.outoperate();
					a.eleva.set_status(1);
					break;
				}
				if (1)
					Sleep(1000);
			}
			if (f)
			{
				down(a, 1);
				break;
			}
		}
	}
	a.eleva.set_status(0);
	system("cls");
	a.printout(1);
	a.printin();
}
