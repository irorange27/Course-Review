#include "Point_Line.h"

int main_test41()
{
	Point a;	// �����ֲ��Զ������������ڵ����������غ����
	cout << "Return to Operating System." << endl;
	return 0;
}

/////////////////////////
int main_test42()
{
	Point b(3,4), c(b);	// ����2���ֲ��Զ�����
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
	cout << "�߶εĳ���Ϊ " << line.len() << endl;
	cout << "Return to Operating System." << endl;
	return 0;
}

/////////////////////////
int main_test45()
{
	Point a, b(1, 1);
	Line line(a, b);		// ������������󴴽�һ���߶ζ���
	cout << "�߶εĳ���Ϊ " << line.len() << endl;
	cout << "Return to Operating System." << endl;
	return 0;
}
