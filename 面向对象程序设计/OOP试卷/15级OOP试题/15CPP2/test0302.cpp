// test0302.cpp
#include <iostream>
using namespace std;

class Base
{
public:
	Base(int x=0) : a(x)
	{
		cout << "构造基类对象(" << a << ")\n";
	}
	Base(const Base &b) : a(b.a)
	{
		cout << "拷贝构造基类的对象(" << a << ")\n";
	}
	virtual ~Base()
	{
		cout << "析构基类对象(" << a << ")\n";
	}
protected:
	int a;
	static int num; 							// 静态数据成员
};

int Base::num = 0; 								// 静态数据成员定义及初始化

class Derived : public Base
{
public:
	Derived(int x=0, int y=0): Base(x), b(y)
	{				// 构造函数中输出了对象个数[num]，在园括号之前
		cout << "构造派生类的对象["
			 << ++num << "](" << a << ", " << b << ")\n";
	}
	Derived(const Derived &d):Base(d), b(d.b)
	{				// 拷贝构造函数中输出了对象个数[num]，在园括号之前
		cout << "拷贝构造派生类的对象["
			 << ++num << "](" << a << ", " << b << ")\n";
	}
	~Derived()
	{				// 析构函数中输出了对象个数[num]，在园括号之后
		cout << "析构派生类的对象("
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
{		// 形参分别为引用传递、指针传递、值传递
	cout << "in f function..." << endl;
	cout << r << endl;
	r.Set(50, 80);			// 引用传递的对象，值被重置
	cout << *p << endl;		// 从指针p看其目标为常对象
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
