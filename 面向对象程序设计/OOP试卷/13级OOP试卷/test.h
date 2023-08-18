// test.h
#include <iostream>
#include <cmath>
using namespace std;

class BASE
{
public:
	BASE(double x=0, double y=0): _x(x), _y(y) {}
	virtual void Show(ostream &out) const = 0;
protected:
	double _x, _y;
};

ostream & operator<<(ostream &out, const BASE &x)
{
	x.Show(out);
	return out;
}

class Complex : public BASE
{
public:
	Complex(double x=0, double y=0): BASE(x, y)
	{
	}
	void Show(ostream &out) const
	{
		if(_x!=0)
		{
			out << _x;
			if(_y>0) 		out << '+' << _y << 'i';
			else if(_y<0)	out << '-' << -_y << 'i';
		}
		else
		{
			if(_y!=0)
				cout << _y << 'i';
			else
				cout << _x;
		}
	}
	friend Complex operator+(const Complex &a, const Complex &b)
	{
		Complex c;
		c._x = a._x + b._x;
		c._y = a._y + b._y;
		return c;
	}
	friend Complex operator*(const Complex &a, const Complex &b)
	{
		Complex c;
		c._x = a._x*b._x - a._y*b._y;
		c._y = a._x*b._y + a._y*b._x;
		return c;
	}
	double abs()
	{
		return sqrt(_x*_x + _y*_y);
	}
};

class Point : public BASE
{
public:
	Point(double x=0, double y=0): BASE(x, y)
	{
	}
	void Show(ostream &out) const
	{
		out << '(' << _x << ", " << _y << ')';
	}
	friend Point operator+(const Point &a, const Point &b)
	{
		Point c;
		c._x = a._x + b._x;
		c._y = a._y + b._y;
		return c;
	}
};
