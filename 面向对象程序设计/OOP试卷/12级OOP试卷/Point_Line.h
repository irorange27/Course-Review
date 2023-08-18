// Point_Line.h					// 头文件
#include <iostream>
#include <cmath>
using namespace std;

class Line;							// 提前声明

class Point							// 设计点类
{
public:
	Point(double x=0, double y=0) : u(x),v(y)		// 构造函数
	{			// 利用operator<<重载函数输出本对象(*this)
		cout << "构造一个点 " << *this << endl;
	}
	Point(const Point &p) : u(p.u),v(p.v)
	{
		cout << "复制构造一个点 " << *this << endl;
	}
	virtual ~Point(){ cout << "析构一个点 " << *this << endl; }
	void MoveTo(double x, double y)
	{
		cout << "将点 " << *this;
		u = x; v = y;
		cout << " 移动到 " << *this << endl;
	}
	friend class Line;				// 声明Line为友元类
	friend ostream & operator<<(ostream &out, const Point &p)
	{
		out << "(" << p.u << ", " << p.v << ")";
		return out;
	}
private:
	double u, v;					// 点的横坐标，纵坐标
};

class Line
{
public:
	Line(double x1,double y1,double x2,double y2) : a(x1,y1),b(x2,y2)
	{
		cout << "构造一条线段 " << *this << endl;
	}
	Line(const Point &p1, const Point &p2): a(p1),b(p2)
	{
		cout << "构造一条线段 " << *this << endl;
	}
	virtual ~Line(){ cout << "析构一条线段 " << *this << endl; }
	double len()		// 计算线段的长度
	{
		return sqrt((a.u-b.u)*(a.u-b.u)+(a.v-b.v)*(a.v-b.v));
	}
	friend ostream & operator<<(ostream &out, const Line &line)
	{
		out << line.a << "->" << line.b;
		return out;
	}
private:
	Point a, b;			// 组合成员。线段由两个点决定
};
