using namespace std;
void color(int a)  //������ɫ����
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), a);
}
class build
{
public:
	build(int m = 0) :maxf(m), eleva(m) {}
	elevator eleva;
	void printout(int t)  //��ӡ�������ݣ����Ѿ���ĳһ����ɫ
	{
		if (t == 0)
		{
			cout << "\t ***************\n\t  ���ܵ���ϵͳ\n\t ***************\n";
			for (int i = 1; i <= maxf; i++)
				print(i);
		}
		else
		{
			int i = 1;
			cout << "\t ***************\n\t  ���ܵ���ϵͳ\n\t ***************\n";
			for (; i <= maxf - t; i++)
			{
				print(i);
			}
			color(4);
			cout << "\t=================\n\t|******����*****|\n";
			color(7);
			cout << t;
			color(4);
			cout << "\t|***************|\n\t=================\n";
			color(7);
			for (i = i + 1; i <= maxf; i++)
			{
				print(i);
			}
		}
	}
	void printout_light(int t) //��ӡ�������ݣ����Ѿ���ĳһ�����Ϊ��
	{
		int i = 1;
		cout << "\t ***************\n\t  ���ܵ���ϵͳ\n\t ***************\n";
		for (; i <= maxf - t; i++)
		{
			print(i);
		}
		color(244);
		cout << "\t=================\n\t|******����*****|\n";
		color(7);
		cout << t;
		color(244);
		cout << "\t|***************|\n\t=================\n";
		color(7);
		for (i = i + 1; i <= maxf; i++)
		{
			print(i);
		}
	}
	void printin() //��ӡ�����ڲ���ť
	{
		cout << "\n\t===�����ڰ�ť===";
		if (eleva.get_status() == 1)
		{
			color(4);
			cout << "��";
			color(7);
		}
		else
			cout << " ��";
		for (int i = maxf; i != 0; i--)
		{
			if (i % 3 == 0)
				cout << "\n\t";
			if (eleva.get_button(i) == 1)
			{
				color(4);
				cout << i << "     ";
				color(7);
			}
			else
				cout << i << "     ";
		}
		cout << "\n\t================";
		if (eleva.get_status() == 2)
		{
			color(4);
			cout << " ��\n";
			color(7);
		}
		else
			cout << " ��\n";
	}
	int maxf;
private:
	void print(int i)  //��ӡ����ĳһ��
	{
		cout << "\t=================\n\t|\t  \t|\n" << maxf + 1 - i << "\t|\t  \t|\n\t=================\n";
	}
};


