// Complex.cpp
#include <iostream>
#include <cmath>
using namespace std;

class Complex
{
public:
	Complex(double real=0, double imag=0):re(real),im(imag){}

	double & Real(){ return re; }
	double & Imag(){ return im; }
	double Angle() const { return atan2(im, re); }
	double Abs() const { return sqrt(re*re + im*im); }

	Complex & operator-()
	{
		re = -re;
		im = -im;
		return *this;
	}
	friend Complex operator+(const Complex &c1, const Complex &c2)
	{
		Complex result(c1);
		result.re += c2.re;
		result.im += c2.im;
		return result;
	}
	friend Complex operator-(const Complex &c1, const Complex &c2)
	{
		Complex result(c1);
		result.re -= c2.re;
		result.im -= c2.im;
		return result;
	}
	friend Complex operator*(const Complex &c1, const Complex &c2)
	{
		Complex result;
		result.re = c1.re*c2.re - c1.im*c2.im;
		result.im = c1.re*c2.im + c1.im*c2.re;
		return result;
	}
	friend Complex operator/(const Complex &c1, const Complex &c2)
	{
		double z = c2.re*c2.re + c2.im*c2.im;
		Complex result;
		result.re = (c1.re*c2.re + c1.im*c2.im)/z;
		result.im = (c1.im*c2.re - c1.re*c2.im)/z;
		return result;
	}
	Complex & operator+=(const Complex &c)
	{
		re += c.re;
		im += c.im;
		return *this;
	}
	Complex & operator-=(const Complex &c)
	{
		re -= c.re;
		im -= c.im;
		return *this;
	}
	Complex & operator*=(const Complex &c)
	{
		double x = re*c.re - im*c.im;
		im = re*c.im + im*c.re;
		re = x;
		return *this;
	}
	Complex & operator/=(const Complex &c)
	{
		return *this = *this/c;
	}
	friend ostream & operator<<(ostream &out, const Complex &c)
	{
		out << '(' << c.re << ", " << c.im << ')';
		return out;
	}
	friend istream & operator>>(istream &in, Complex &c)
	{
		char str[100];
		in.getline(str, 100, '(');
		in.getline(str, 100, ',');
		c.re = atof(str);
		in.getline(str, 100, ')');
		c.im = atof(str);
		return in;
	}
protected:
	double re, im;
};

int ComplexTesting()
{
	Complex x(3,4), y(x), z;					// ��������
	cout << x << ", " << y << ", " << z << endl;// �������
	cout << x.Abs() << '\t';					// ���㸴����ģ��
	z.Real() = z.Imag() = 1;					// ���ø�����ʵ�����鲿
	cout << z.Angle()*180/M_PI << endl;			// ���㸴���ĽǶ�
	cout << x+z << '\t';						// �����ӷ�����
	cout << x*z << '\t';						// �����˷�����
	cout << (x*=x) << endl;						// ������ֵ*=
	return 0;
}
