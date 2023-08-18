#include "Point_Line.h"

int main_test41()
{
	Point a;	// 创建局部自动对象，其生命期到本函数返回后结束
	cout << "Return to Operating System." << endl;
	return 0;
}

/////////////////////////
int main_test42()
{
	Point b(3,4), c(b);	// 创建2个局部自动对象
	cout << "Return to Operating System." << endl;
	return 0;
}

/////////////////////////
int main_test43()
{
	Point *p;
	p = new Point;
	p->MoveTo(6, 8);
	delete p;
	cout << "Return to Operating System." << endl;	
	return 0;
}

/////////////////////////
int main_test44()
{
	Line line(0, 0, 6, 8);
	cout << "线段的长度为 " << line.len() << endl;
	cout << "Return to Operating System." << endl;
	return 0;
}

/////////////////////////
int main_test45()
{
	Point a, b(1, 1);
	Line line(a, b);		// 利用两个点对象创建一个线段对象
	cout << "线段的长度为 " << line.len() << endl;
	cout << "Return to Operating System." << endl;
	return 0;
}
