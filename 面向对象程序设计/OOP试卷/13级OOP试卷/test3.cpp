#include <iostream>
using namespace std;

class Test
{
public:
	Test(int a=0, int b=0): x(a), y(b) {}
	~Test()
	{
		if(x==y)
			cout << "数据成员的值相同，都等于 " << x << endl;
		else
			cout << "数据成员的值不同，分别为 " << x << ", " << y << endl;
	}
	friend ostream & operator<<(ostream &out, const Test &t)
	{
		out << "(" << t.x << ", " << t.y << ")";
		return out;
	}
private:
	int x, y;
};

int main_test31()
{
	Test *p, t1;
	p = new Test(10);
	Test t2(2, 3);
	cout << *p << '\n'
		   << t1 << '\n'
		   << t2 << endl;
	delete p;
	cout << "退出程序，返回操作系统" << endl;
	return 0;
}

#include "test.h"
int main_test32()
{
	Complex x(1,2), y(3,4), z1(0,1), z2(10);
	cout << x << '\n' << y << '\n'
		 << z1 << '\n' << z2 << endl;
	cout << "y.abs(): " << y.abs() << endl;
	z1 = x+y;
	z2 = x*y;
	cout << z1 << '\n' << z2 << endl;
	
	Point a(1, 2), b(3, 4);
	cout << a << '\n' << b << endl;
	cout << a+b << endl;
	return 0;
}

int main_test33()
{
	Complex x(1, 2), y, z;
	y = 5+x;
	z = 5*x;
	cout << x <<'\n'<< y <<'\n'<< z << endl;
	cout << x+x << endl;

	Point a(1, 2), b, c;
	b = a + 1;
	c = 1 + a;
	cout << a <<'\n'<< b <<'\n'<< c << endl;
	a = a + a;
	cout << a+a << endl;
	return 0;
}
