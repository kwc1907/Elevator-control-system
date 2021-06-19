using namespace std;
void color(int a)  //设置颜色函数
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), a);
}
class build
{
public:
	build(int m = 0) :maxf(m), eleva(m) {}
	elevator eleva;
	void printout(int t)  //打印整个电梯，并把具体某一层变红色
	{
		if (t == 0)
		{
			cout << "\t ***************\n\t  智能电梯系统\n\t ***************\n";
			for (int i = 1; i <= maxf; i++)
				print(i);
		}
		else
		{
			int i = 1;
			cout << "\t ***************\n\t  智能电梯系统\n\t ***************\n";
			for (; i <= maxf - t; i++)
			{
				print(i);
			}
			color(4);
			cout << "\t=================\n\t|******电梯*****|\n";
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
	void printout_light(int t) //打印整个电梯，并把具体某一层填充为白
	{
		int i = 1;
		cout << "\t ***************\n\t  智能电梯系统\n\t ***************\n";
		for (; i <= maxf - t; i++)
		{
			print(i);
		}
		color(244);
		cout << "\t=================\n\t|******电梯*****|\n";
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
	void printin() //打印电梯内部按钮
	{
		cout << "\n\t===电梯内按钮===";
		if (eleva.get_status() == 1)
		{
			color(4);
			cout << "上";
			color(7);
		}
		else
			cout << " 上";
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
			cout << " 下\n";
			color(7);
		}
		else
			cout << " 下\n";
	}
	int maxf;
private:
	void print(int i)  //打印具体某一层
	{
		cout << "\t=================\n\t|\t  \t|\n" << maxf + 1 - i << "\t|\t  \t|\n\t=================\n";
	}
};


