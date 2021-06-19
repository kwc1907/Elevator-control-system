using namespace std;
#include<vector>
class people  //电梯中的人
{
public:
	people() = default;
	people(double i, int f, int t) :id(i), from(f), to(t) {}
	double id;
	int from;
	int to;
};
class elevator
{
public:
	elevator(int f);
	void set_status(int i);         //设置电梯状态
	void set_now(int flag);        //设置电梯所在楼层
	void set_in(int i, int flag);  //设置电梯内部按钮
	void set_out(int i, int flag);  //设置电梯外部按钮
	void set_button(int i, int flag); //设置电梯内部灯的亮暗
	int get_in(int i);          //获得内部按钮的值    
	int get_out(int i);         //获得外部按钮的值  
	int get_button(int i);      //获得电梯内部按钮的亮暗
	int get_status();           //获得电梯状态
	int get_now();              //获得电梯所在楼层
	void inoperate(int i);      //设置内部人按的按键
	void outoperate();          //设置外部人按的按键
	int numbers;                //乘客人数
	vector<people>p;            //乘客信息
private:
	int maxf;
	int run_status;   //1上2下
	int curf;         //当前楼层          
	vector<int>button;  //装灯的信息，1亮0不亮
	vector<int>in;     //装内部按钮的信息
	vector<int>out;    //装外部按钮的信息，1有人按了上，2有人按了下，3即有人按了上，又有人按了下
	static double u;   //乘客编号
};

