int up(build& a, int n)  //控制电梯上升的函数，传给它一个数，就能上升到这一楼层
{
	a.eleva.set_status(1);
	for (int i = a.eleva.get_now() + 1; i <= n; i++)
	{
		if (_kbhit())    //监听键盘，上升过程中可以随时插入新的消息
		{
			int t = 1;
			a.eleva.outoperate();
			for (int y = a.eleva.get_now(); y < n; y++)   //判断插入的新信息是否需要替换原来的信息
				if (a.eleva.get_out(y) == 1 || a.eleva.get_out(y) == 3)  //1代表外部有人按了上，3代表外部上下都按了
				{
					t = 0;
					n = y;
					break;
				}
			if (t)
			{
				if (a.eleva.get_out(n) == 2)  //如果目标楼层是有人按下
				{
					int t = 1;
					for (int y = a.eleva.get_now(); y <= a.maxf; y++)  //判断插入的是否有按上的，如果有就得先上,因为电梯上升状态，上的优先级比下高
					{
						if (a.eleva.get_out(y) == 1)
						{
							t = 0;
							n = y;
							break;
						}
					}
					if (t)
					{
						for (int y = n + 1; y <= a.maxf; y++)  //如果插入的没有按上的，就得判断插入的有没有更高的下
						{
							if (a.eleva.get_out(y) == 2)
							{
								n = y;
								break;
							}
						}
					}
				}
			}
		}
		if (1)
		{
			Sleep(1000);
			system("cls");
			a.eleva.set_now(i);
			a.printout(i);
			a.printin();
			if (a.eleva.numbers != 0) //打印电梯中具体人的情况
			{
				cout << "\t================\n";
				for (auto i : a.eleva.p)
					cout << "\t" << i.id << ":" << i.from << "-->" << i.to << endl;
				cout << "\t当前电梯有" << a.eleva.numbers << "人" << endl;
				cout << "\t================\n";
			}
		}
	}
	cout << "电梯已经到了第" << a.eleva.get_now() << "层";
	return a.eleva.get_now();
}
int down(build& a, int n)     //控制电梯下降的函数，传给它一个数，就能下降到这一楼层
{
	a.eleva.set_status(2);
	for (int i = a.eleva.get_now() - 1; i >= n; i--)
	{
		if (_kbhit())                          //监听键盘，下降过程中可以随时插入新的消息
		{
			int t = 1;
			a.eleva.outoperate();
			for (int y = a.eleva.get_now(); y >= n; y--)
				if (a.eleva.get_out(y) == 2 || a.eleva.get_out(y) == 3) //2代表外部有人按了上，3代表外部上下都按了
				{
					t = 0;
					n = y;
					break;
				}
			if (t)
			{
				if (a.eleva.get_out(n) == 1)  //如果目标楼层是有人按上
				{
					int t = 1;
					for (int y = a.eleva.get_now(); y >= 1; y--)  //判断插入的是否有按下的，如果有就得先下,因为电梯下降状态，下的优先级比上高
					{
						if (a.eleva.get_out(y) == 2)
						{
							t = 0;
							n = y;
							break;
						}
					}
					if (t)
					{
						for (int y = n - 1; y >= 1; y--)  //如果插入的没有按下的，就得判断插入的有没有更低的上
						{
							if (a.eleva.get_out(y) == 2)
							{
								n = y;
								break;
							}
						}
					}
				}
			}


		}
		if (1)
		{
			Sleep(1000);
			system("cls");
			a.eleva.set_now(i);
			a.printout(i);
			a.printin();
			if (a.eleva.numbers != 0)  //打印电梯中具体人的情况
			{
				cout << "\t================\n";
				for (auto i : a.eleva.p)
					cout << "\t" << i.id << ":" << i.from << "-->" << i.to << endl;
				cout << "\t当前电梯有" << a.eleva.numbers << "人" << endl;
				cout << "\t================\n";
			}
		}
	}
	cout << "电梯已经到了第" << a.eleva.get_now() << "层";
	return a.eleva.get_now();
}
void chaozai(build& a)  //处理超载的函数
{
	if (a.eleva.numbers > 4)
	{
		for (int i = 0; i < 3; i++)
			Beep(5000, 500);
		cout << "人数超载,请输入下电梯,结束请按0:";
		while (1)  //删除掉电梯中超载的人
		{

			int f;
			cin >> f;
			if (f == 0)
				break;
			else
			{
				auto y = a.eleva.p.begin();
				while (y != a.eleva.p.end())
				{
					if (y->id == f)
					{
						a.eleva.set_in(y->to, 0);
						a.eleva.set_button(y->to, 0);
						y = a.eleva.p.erase(y);
						a.eleva.numbers--;
					}
					else y++;
				}
			}
		}
	}
}