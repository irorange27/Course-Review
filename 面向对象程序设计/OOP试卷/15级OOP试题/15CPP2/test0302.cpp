// test0302.cpp
#include <iostream>
using namespace std;

class Base
{
public:
	Base(int x=0) : a(x)
	{
		cout << "����������(" << a << ")\n";
	}
	Base(const Base &b) : a(b.a)
	{
		cout << "�����������Ķ���(" << a << ")\n";
	}
	virtual ~Base()
	{
		cout << "�����������(" << a << ")\n";
	}
protected:
	int a;
	static int num; 							// ��̬���ݳ�Ա
};

int Base::num = 0; 								// ��̬���ݳ�Ա���弰��ʼ��

class Derived : public Base
{
public:
	Derived(int x=0, int y=0): Base(x), b(y)
	{				// ���캯��������˶������[num]����԰����֮ǰ
		cout << "����������Ķ���["
			 << ++num << "](" << a << ", " << b << ")\n";
	}
	Derived(const Derived &d):Base(d), b(d.b)
	{				// �������캯��������˶������[num]����԰����֮ǰ
		cout << "��������������Ķ���["
			 << ++num << "](" << a << ", " << b << ")\n";
	}
	~Derived()
	{				// ��������������˶������[num]����԰����֮��
		cout << "����������Ķ���("
 			 << a << ", " << b << ")[" << --num << "]\n";
	}
	void Set(int x, int y)
	{
		a = x; b = y;
	}
	friend ostream &operator<<(ostream &out, const Derived &d)
	{
		out << '(' << d.a << ", " << d.b << ')';
		return out;
	}
private:
	int b;
};

void f(Derived &r, const Derived *p, Derived x)
{		// �βηֱ�Ϊ���ô��ݡ�ָ�봫�ݡ�ֵ����
	cout << "in f function..." << endl;
	cout << r << endl;
	r.Set(50, 80);			// ���ô��ݵĶ���ֵ������
	cout << *p << endl;		// ��ָ��p����Ŀ��Ϊ������
	cout << x << endl;
	x.Set(0, 0);
	cout << x << endl;
}

int Test0302()
{
	Derived d(100, 200);
	cout << "Calling f function..." << endl;
	f(d, &d, d);
	cout << "return to Operating System." << endl;
	return 0;
}
