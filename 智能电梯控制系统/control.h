int up(build& a, int n)  //���Ƶ��������ĺ�����������һ������������������һ¥��
{
	a.eleva.set_status(1);
	for (int i = a.eleva.get_now() + 1; i <= n; i++)
	{
		if (_kbhit())    //�������̣����������п�����ʱ�����µ���Ϣ
		{
			int t = 1;
			a.eleva.outoperate();
			for (int y = a.eleva.get_now(); y < n; y++)   //�жϲ��������Ϣ�Ƿ���Ҫ�滻ԭ������Ϣ
				if (a.eleva.get_out(y) == 1 || a.eleva.get_out(y) == 3)  //1�����ⲿ���˰����ϣ�3�����ⲿ���¶�����
				{
					t = 0;
					n = y;
					break;
				}
			if (t)
			{
				if (a.eleva.get_out(n) == 2)  //���Ŀ��¥�������˰���
				{
					int t = 1;
					for (int y = a.eleva.get_now(); y <= a.maxf; y++)  //�жϲ�����Ƿ��а��ϵģ�����о͵�����,��Ϊ��������״̬���ϵ����ȼ����¸�
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
						for (int y = n + 1; y <= a.maxf; y++)  //��������û�а��ϵģ��͵��жϲ������û�и��ߵ���
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
			if (a.eleva.numbers != 0) //��ӡ�����о����˵����
			{
				cout << "\t================\n";
				for (auto i : a.eleva.p)
					cout << "\t" << i.id << ":" << i.from << "-->" << i.to << endl;
				cout << "\t��ǰ������" << a.eleva.numbers << "��" << endl;
				cout << "\t================\n";
			}
		}
	}
	cout << "�����Ѿ����˵�" << a.eleva.get_now() << "��";
	return a.eleva.get_now();
}
int down(build& a, int n)     //���Ƶ����½��ĺ�����������һ�����������½�����һ¥��
{
	a.eleva.set_status(2);
	for (int i = a.eleva.get_now() - 1; i >= n; i--)
	{
		if (_kbhit())                          //�������̣��½������п�����ʱ�����µ���Ϣ
		{
			int t = 1;
			a.eleva.outoperate();
			for (int y = a.eleva.get_now(); y >= n; y--)
				if (a.eleva.get_out(y) == 2 || a.eleva.get_out(y) == 3) //2�����ⲿ���˰����ϣ�3�����ⲿ���¶�����
				{
					t = 0;
					n = y;
					break;
				}
			if (t)
			{
				if (a.eleva.get_out(n) == 1)  //���Ŀ��¥�������˰���
				{
					int t = 1;
					for (int y = a.eleva.get_now(); y >= 1; y--)  //�жϲ�����Ƿ��а��µģ�����о͵�����,��Ϊ�����½�״̬���µ����ȼ����ϸ�
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
						for (int y = n - 1; y >= 1; y--)  //��������û�а��µģ��͵��жϲ������û�и��͵���
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
			if (a.eleva.numbers != 0)  //��ӡ�����о����˵����
			{
				cout << "\t================\n";
				for (auto i : a.eleva.p)
					cout << "\t" << i.id << ":" << i.from << "-->" << i.to << endl;
				cout << "\t��ǰ������" << a.eleva.numbers << "��" << endl;
				cout << "\t================\n";
			}
		}
	}
	cout << "�����Ѿ����˵�" << a.eleva.get_now() << "��";
	return a.eleva.get_now();
}
void chaozai(build& a)  //�����صĺ���
{
	if (a.eleva.numbers > 4)
	{
		for (int i = 0; i < 3; i++)
			Beep(5000, 500);
		cout << "��������,�������µ���,�����밴0:";
		while (1)  //ɾ���������г��ص���
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