// Point_Line.h					// ͷ�ļ�
#include <iostream>
#include <cmath>
using namespace std;

class Line;							// ��ǰ����

class Point							// ��Ƶ���
{
public:
	Point(double x=0, double y=0) : u(x),v(y)		// ���캯��
	{			// ����operator<<���غ������������(*this)
		cout << "����һ���� " << *this << endl;
	}
	Point(const Point &p) : u(p.u),v(p.v)
	{
		cout << "���ƹ���һ���� " << *this << endl;
	}
	virtual ~Point(){ cout << "����һ���� " << *this << endl; }
	void MoveTo(double x, double y)
	{
		cout << "���� " << *this;
		u = x; v = y;
		cout << " �ƶ��� " << *this << endl;
	}
	friend class Line;				// ����LineΪ��Ԫ��
	friend ostream & operator<<(ostream &out, const Point &p)
	{
		out << "(" << p.u << ", " << p.v << ")";
		return out;
	}
private:
	double u, v;					// ��ĺ����꣬������
};

class Line
{
public:
	Line(double x1,double y1,double x2,double y2) : a(x1,y1),b(x2,y2)
	{
		cout << "����һ���߶� " << *this << endl;
	}
	Line(const Point &p1, const Point &p2): a(p1),b(p2)
	{
		cout << "����һ���߶� " << *this << endl;
	}
	virtual ~Line(){ cout << "����һ���߶� " << *this << endl; }
	double len()		// �����߶εĳ���
	{
		return sqrt((a.u-b.u)*(a.u-b.u)+(a.v-b.v)*(a.v-b.v));
	}
	friend ostream & operator<<(ostream &out, const Line &line)
	{
		out << line.a << "->" << line.b;
		return out;
	}
private:
	Point a, b;			// ��ϳ�Ա���߶������������
};
