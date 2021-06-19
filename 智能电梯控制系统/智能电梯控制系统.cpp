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
		if (a.eleva.get_status() == 1)    //电梯处于上升状态
		{
			for (int i = a.eleva.get_now(); i <= e; i++)
			{
				if (a.eleva.get_in(i) == 1 && a.eleva.get_out(i) != 0)  //内部人按的电梯到了，和外部人按了电梯
				{
					if (a.eleva.get_now() != i)
						i = up(a, i);
					Sleep(2000);
					system("cls");
					a.eleva.set_button(i, 0);
					a.eleva.set_in(i, 0);
					a.printout_light(i);
					a.printin();
					cout << "电梯门已开启\n";
					auto y = a.eleva.p.begin();
					while (y != a.eleva.p.end()) //乘客下电梯后，删掉他的信息
					{
						if (y->to == i)
						{
							cout << "请" << y->id << "号乘客下电梯\n";
							y = a.eleva.p.erase(y);
							a.eleva.numbers--;
						}
						else y++;
					}
					if (a.eleva.get_out(i) == 2)    //2代表外部有人按了下，判断是否应该在这停，如果电梯上方有人按上，电梯有处于上升状态，它就不该理这个按下
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
						for (int t = i + 1; t <= e; t++)   //如果这个位置以上还有人按了下，它就不该管这个下的
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
					cout << "电梯门已关闭\n";
				}
				else if (a.eleva.get_in(i) == 1)//内部人按的电梯到了
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
					cout << "电梯门已开启\n";
					auto y = a.eleva.p.begin();
					while (y != a.eleva.p.end()) //乘客下电梯后，删掉他的信息
					{
						if (y->to == i)
						{
							cout << "请" << y->id << "号乘客下电梯\n";
							y = a.eleva.p.erase(y);
							a.eleva.numbers--;
						}
						else y++;
					}
					Sleep(2000);
					system("cls");
					a.printout(i);
					a.printin();
					cout << "电梯门已关闭\n";
				}
				else if (a.eleva.get_out(i) != 0)   //外部有人按了上电梯
				{
					if (a.eleva.get_out(i) == 2)  //判断是否应该在这停，如果电梯上方有人按上，电梯有处于上升状态，它就不该理这个按下
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
						for (int t = i + 1; t <= e; t++)   //如果这个位置以上还有人按了下，它就不该管这个下的
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
					cout << "电梯门已打开,请乘客进入\n";
					a.eleva.inoperate(i);
					chaozai(a);
					Sleep(2000);
					system("cls");
					a.printout(i);
					a.printin();
					cout << "电梯门已关闭\n";

				}
			}
			int flag = 1;
			for (int i = 1; i <= e; i++)  //判断整栋楼是否还有人按了按键或电梯里还有人
				if (a.eleva.get_out(i) != 0 || a.eleva.get_in(i) != 0)
				{
					flag = 0;
					break;
				}
			if (flag)
				a.eleva.set_status(0);
			else a.eleva.set_status(2);
		}
		else if (a.eleva.get_status() == 2)  //电梯处于下降状态
		{
			for (int i = a.eleva.get_now(); i >= 1; i--)
			{
				if (a.eleva.get_in(i) == 1 && a.eleva.get_out(i) != 0)//内部人按的电梯到了，和外部人按了电梯
				{
					if (a.eleva.get_now() != i)
						i = down(a, i);
					Sleep(2000);
					system("cls");
					a.eleva.set_button(i, 0);
					a.eleva.set_in(i, 0);
					a.printout_light(i);
					a.printin();
					cout << "电梯门已开启\n";
					auto y = a.eleva.p.begin();
					while (y != a.eleva.p.end())  //乘客下电梯后，删掉他的信息
					{
						if (y->to == i)
						{
							cout << "请" << y->id << "号乘客下电梯\n";
							y = a.eleva.p.erase(y);
							a.eleva.numbers--;
						}
						else y++;
					}
					if (a.eleva.get_out(i) == 1)  //判断是否应该在这停，如果电梯下方有人按下，电梯有处于下降状态，它就不该理这个按上的
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
						for (int t = i - 1; t >= 1; t--)   //如果这个位置以下还有人按了上，它就不该管这个上的
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
					cout << "电梯门已关闭\n";
				}
				else if (a.eleva.get_in(i) == 1)//内部人按的电梯到了
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
					cout << "电梯门已开启\n";
					auto y = a.eleva.p.begin();
					while (y != a.eleva.p.end())  //乘客下电梯后，删掉他的信息
					{
						if (y->to == i)
						{
							cout << "请" << y->id << "号乘客下电梯\n";
							y = a.eleva.p.erase(y);
							a.eleva.numbers--;
						}
						else y++;
					}
					Sleep(2000);
					system("cls");
					a.printout(i);
					a.printin();
					cout << "电梯门已关闭\n";
				}
				else if (a.eleva.get_out(i) != 0)//证明外部有人按了电梯
				{
					if (a.eleva.get_out(i) == 1)  //判断是否应该在这停，如果电梯下方有人按下，电梯有处于下降状态，它就不该理这个按上的
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
						for (int t = i - 1; t >= 1; t--)   //如果这个位置以下还有人按了上，它就不该管这个上的
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
					cout << "电梯门已打开,请乘客进入\n";
					a.eleva.inoperate(i);
					chaozai(a);
					Sleep(2000);
					system("cls");
					a.printout(i);
					a.printin();
					cout << "电梯门已关闭\n";
				}

			}
			int flag = 1;
			for (int i = 1; i <= e; i++) //判断整栋楼是否还有人按了按键或电梯里还有人
				if (a.eleva.get_out(i) != 0 || a.eleva.get_in(i) != 0)
				{
					flag = 0;
					break;
				}
			if (flag)
				a.eleva.set_status(0);
			else a.eleva.set_status(1);
		}
		else if (a.eleva.get_status() == 0)  //电梯处于静止状态
		{
			int f = 1;
			for (int i = 0; i < 10; i++)   //十秒内无人按电梯，电梯自动回一楼，如有人按，继续运行
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
