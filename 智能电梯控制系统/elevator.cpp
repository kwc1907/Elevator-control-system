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
void elevator::set_now(int flag)  //设置电梯所在楼层
{
	curf = flag;
}
void elevator::set_status(int i)  //设置电梯状态
{
	run_status = i;
}
void elevator::set_button(int i, int flag)   //设置电梯内部灯的亮暗
{
	button[i] = flag;
}
void elevator::set_in(int i, int flag)  //设置电梯内部按钮
{
	in[i] = flag;
}
void elevator::inoperate(int i)  //设置内部人按的按键
{
	int f, before = 0;
	cout << "请进入电梯的乘客按下所要到达的楼层" << endl;
	cout << "多个楼层之间用空格隔开,结束请按0:";
	while (1)
	{
		cin >> f;
		if (f == 0)
			break;
		else if (f > maxf || f < 1)
		{
			cout << "输入有误，超出楼层范围的将不予理会\n";
			continue;
		}
		else if (before == f)  //判断上一次和这一次是否相等
		{
			numbers--;
			set_button(f, 0);
			set_in(f, 0);
			p.erase(p.end() - 1);
			u--;
			before = 0;
		}
		else          //正常将乘客信息填入
		{
			numbers++;
			p.emplace_back(++u, i, f);
			set_button(f, 1);
			set_in(f, 1);
			before = f;
		}
	}
}
void elevator::set_out(int i, int flag)   //设置电梯外部按钮
{
	out[i] = flag;
}
int elevator::get_out(int i)  //获得外部按钮的值  
{
	return out[i];
}
int elevator::get_status()  //获得电梯状态
{
	return run_status;
}
int elevator::get_in(int i)  //获得内部按钮的值  
{
	return in[i];
}
int elevator::get_button(int i)   //获得电梯内部按钮的亮暗
{
	return button[i];
}
int elevator::get_now()  //获得电梯所在楼层
{
	return curf;
}
void elevator::outoperate()   //设置外部人按的按键
{
	int f, before = 0, m;
	cout << "请输入哪个楼层上楼(多个楼层用空格隔开,结束输入请按0):";
	while (1)
	{
		cin >> f;
		if (f == 0)
			break;
		else if (f >= maxf || f < 1)
		{
			cout << "输入有误，超出楼层范围的将不予理会\n";
			continue;
		}
		else if (before == f)  //判断上一次和这一次是否相等
		{
			set_out(f, m);
			before = 0;
			continue;
		}
		else if (get_out(f) == 2)  //如果电梯之前有人按了下，就变为上下都有
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
	cout << "请输入哪个楼层下楼(多个楼层用空格隔开,结束输入请按0):";
	while (1)
	{
		cin >> f;
		if (f == 0)
			break;
		else if (f <= 1 || f > maxf)
		{
			cout << "输入有误，超出楼层范围的将不予理会\n";
			continue;
		}
		else if (before == f)   //判断上一次和这一次是否相等
		{
			set_out(f, m);
			before = 0;
			continue;
		}
		else if (get_out(f) == 1) ////如果电梯之前有人按了上，就变为上下都有
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