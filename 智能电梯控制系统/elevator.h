using namespace std;
#include<vector>
class people  //�����е���
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
	void set_status(int i);         //���õ���״̬
	void set_now(int flag);        //���õ�������¥��
	void set_in(int i, int flag);  //���õ����ڲ���ť
	void set_out(int i, int flag);  //���õ����ⲿ��ť
	void set_button(int i, int flag); //���õ����ڲ��Ƶ�����
	int get_in(int i);          //����ڲ���ť��ֵ    
	int get_out(int i);         //����ⲿ��ť��ֵ  
	int get_button(int i);      //��õ����ڲ���ť������
	int get_status();           //��õ���״̬
	int get_now();              //��õ�������¥��
	void inoperate(int i);      //�����ڲ��˰��İ���
	void outoperate();          //�����ⲿ�˰��İ���
	int numbers;                //�˿�����
	vector<people>p;            //�˿���Ϣ
private:
	int maxf;
	int run_status;   //1��2��
	int curf;         //��ǰ¥��          
	vector<int>button;  //װ�Ƶ���Ϣ��1��0����
	vector<int>in;     //װ�ڲ���ť����Ϣ
	vector<int>out;    //װ�ⲿ��ť����Ϣ��1���˰����ϣ�2���˰����£�3�����˰����ϣ������˰�����
	static double u;   //�˿ͱ��
};

