// test0301.cpp
#include <iostream>
using namespace std;

class ctest
{
public:
	ctest(int x=0):a(x){cout << "构造对象(" << a << ")\n";}
	~ctest(){ cout << "析构对象(" << a << ")\n";}
	ctest & Add()
	{
		++a;
		return *this;
	}
	ctest add()
	{
		ctest temp(*this);
		++a;
		return temp;
	}
	friend ostream & operator<<(ostream &out, const ctest &c)
	{
		out << c.a;
		return out;
	}
private:
	int a;
};

int Test0301()
{
	ctest a(100), b(200);
	cout << a << ", " << b << endl;	// 第3行输出
	a.Add().Add();
	b.add().add();		// 注意：拷贝构造临时无名对象无输出
	cout << a << ", " << b << endl;	// 第6行输出
	a.~ctest();			// 主动调用析构函数，并不销毁对象
	b.~ctest();			// 主动调用析构函数，并不销毁对象
	cout << a << ", " << b << endl;	// 第9行输出
	cout << "返回操作系统。" << endl;	// 第10行输出
	return 0;
}
