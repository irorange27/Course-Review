// Test03.cpp
#include "Test03.h"

int Test1::num=0, Test1::sum=0;	// 静态数据成员定义及初始化

Test1::Test1(int a):x(a)
{
	num++; sum+=x;
}

Test1::Test1(const Test1 &t):x(t.x)
{
	num++; sum+=x;
}

Test1::~Test1()
{
	num--; sum-=x;
}

Test1 & Test1::operator=(const Test1 &t)
{
	sum += t.x - x;
	x = t.x;
	return *this;
}

int Test1::Num() {return num;}

int Test1::Sum() {return sum;}

ostream & operator<<(ostream &out, const Test1 &t)
{
	out << t.x;
	return out;
}

istream & operator>>(istream &in, Test1 &t)
{
	int temp;
	in >> temp;
	Test1::sum += temp - t.x;
	t.x = temp;
	return in;
}

void Show()
{
	cout << "Num = " << Test1::Num()
		 << ",\tSum = " << Test1::Sum() << endl;
}
////////////////////////////

#define TESTING_GLOBAL

#ifdef TESTING_GLOBAL
	Test1 x(100);		// 创建一个全局对象
	void f(Test1 t)
	{
		Show();
	}
	
	int Testing0302()
	{
		Show();
		f(x);
		Show();
		return 0;
	}
#else
	int Testing0301()
	{
		Show();
		return 0;
	}

	void f(Test1 &t)
	{
		Show();
	}

	int Testing0303()
	{
		Test1 x(100);	// 创建一个全局对象
		Show();
		f(x);
		Show();
		return 0;
	}

	int Testing0304()
	{
		Test1 x(10),y(20),a[]={x,y};
		Show();
		Test1 *p = new Test1;
		*p = 30;
		Show();
		delete p;
		Show();
		return 0;
	}
#endif

int Testing03()
{
	#ifdef TESTING_GLOBAL
		Testing0302();
	#else
		Testing0301();
		Testing0303();
		Testing0304();
	#endif
	return 0;
}
