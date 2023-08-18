// test03.cpp
#include <iostream>
using namespace std;

class Complex
{
public:
	Complex(double real=0, double imag=0) : re(real), im(imag) { }
	double Real()const { return re; }
	double Imag()const { return im; }
	void Set(double real, double imag) { re=real; im=imag; }
	friend ostream & operator<<(ostream &out, const Complex &c)
	{
		out << "(" << c.re << ", " << c.im << ")";
		return out;
	}
	friend istream & operator>>(istream &in, Complex &c)
	{
		double real, imag;
		char str[100];
		in.getline(str, 100, '(');
		in.getline(str, 100, ',');
		real = atof(str);
		in.getline(str, 100, ')');
		imag = atof(str);
		c.Set(real, imag);
		return in;
	}
	Complex operator+(const Complex &c)
	{
		Complex temp;
		temp.re = re + c.re;
		temp.im = im + c.im;
		return temp;
	}
	Complex & operator++()
	{
		re++;
		return *this;
	}
	Complex operator++(int)
	{
		Complex temp(*this);
		re++;
		return temp;
	}
	#if(1)		// 将此行改成 #if(1) 或 #if(0) 使用如下两个函数
		Complex & operator*=(const Complex &c)		// 此函数错误
		{
			Complex temp(*this);
			re = temp.re * c.re - temp.im * c.im;
			im = temp.re * c.im + temp.im * c.re;
			return *this;
		}
	#else
		Complex & operator*=(const Complex &c)		// 此函数正确
		{
			Complex temp;
			temp.re = re * c.re - im * c.im;
			temp.im = re * c.im + im * c.re;
			*this = temp;
			return *this;
		}
	#endif
private:
	double re, im;
};

int ComplexTest01()
{
	Complex c1, c2 = 2, c3(2, 3);
	cout << c1 << '\t' << c2 << '\t' << c3 << endl;
	c1 = c2 + c3;
	c2 *= c2;				// 请严格按operator*=函数计算
	c3 *= c3;				// 请严格按operator*=函数计算
	cout << c1 << endl;
	cout << c2 << endl;
	cout << c3 << endl;
	return 0;
}

int ComplexTest02()
{
	Complex c(2, 3), d(c);
	cout << ++c << '\t';	// 此处无换行
	cout << c << endl;
	cout << d++ << '\t';	// 此处无换行
	cout << d << endl;
	c.Set(2, 3);
	d.Set(2, 3);
	cout << ++++c << '\t';	// 此处无换行
	cout << c << endl;
	cout << d++++ << '\t';	// 此处无换行
	cout << d << endl;
	return 0;
}

int ComplexTest03()
{
	Complex c1, c2(2, 3), *p;
	cout << (c1=c2) << endl;
	cout << c2 << endl;
	p = new Complex(4, 5);
	cout << *p << endl;
	delete p;
	p = &c1;
	cout << *p << endl;
	return 0;
}

int mainComplex()
{
	cout << "============" << endl;
	ComplexTest01();
	cout << "============" << endl;
	ComplexTest02();
	cout << "============" << endl;
	ComplexTest03();
	cout << "============" << endl;
	return 0;
}

/////////////////////////////////////
class Base
{
public:
	Base(int a, int b=1) : x(a), y(b) { }
	virtual void Show(ostream &out) const = 0;
protected:
	int x, y;
};

ostream &operator<<(ostream &out, const Base &b)
{
	b.Show(out);
	return out;
}

class Derived : public Base
{
public:
	Derived(int a, int b, int c) : Base(a, b), z(c) { }
	Derived &operator+=(const Derived &d)
	{
		x += d.x;
		y += d.y;
		z += d.z;
		return *this;
	}
	void Show(ostream &out) const
	{
		out << "[(" << x << ", " << y << "), " << z << "]";
	}
private:
	int z;
};

class RationalNumber : public Base
{
public:
	RationalNumber(int a, int b=1) : Base(a, b) { }
	RationalNumber &operator+=(const RationalNumber &r)
	{
		int temp = x*r.y + y*r.x;
		y *= r.y;
		x = temp;
		return *this;
	}
	void Show(ostream &out) const
	{
		out << x << '/' << y;
	}
};

int mainDerived()
{
	Derived d1(3, 2, 1), d2(4, 5, 6);
	RationalNumber r1(3, 2), r2(2, 3);
	cout << d1 << endl;
	cout << d2 << endl;
	d1 += d2;
	cout << d1 << endl;
	cout << r1 << endl;
	cout << r2 << endl;
	r1 += r2;
	cout << r1 << endl;
	return 0;
}
