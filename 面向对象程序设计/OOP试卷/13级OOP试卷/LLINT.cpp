// LLINT.cpp					Դ�����ļ�
#include "LLINT.h"
#include <iomanip>

const unsigned long long LLINT::BBILLION = 1000000000000000000ULL;
				// ��̬�������ݳ�Ա�Ķ��弰��ʼ����10^18��

LLINT::LLINT(unsigned long long x0, unsigned long long x1)
{				// ���캯��
	unsigned long long x = x0/BBILLION;
	a0 = x0 % BBILLION;
	a1 = x1 + x;
}

LLINT::LLINT(const char *str) 	// ת�����캯������C-�ַ���ת����
{
	*this = atoLLINT(str);			// ֱ�����ó�Ա����ʵ��ת������
}

LLINT LLINT::operator++(int) 		// ���������������
{
	LLINT temp(*this);
	++(*this);
	return temp;
}

LLINT operator+(const LLINT &x1, const LLINT &x2)
{
	LLINT s;
	unsigned long long c = x1.a0 + x2.a0;
	s.a0 = c % LLINT::BBILLION;
	s.a1 = x1.a1 + x2.a1 + c/LLINT::BBILLION;
	return s;
}

ostream & operator<<(ostream &out, const LLINT &x)
{
	if(x.a1!=0)
		out << x.a1 << setfill('0')<<setw(18)<< x.a0 << setfill(' ');
	else
		out << x.a0;
	return out;
}

istream & operator>>(istream &in, LLINT &x)
{
	char str[200];
	in >> str;
	x = atoLLINT(str);
	return in;
}

bool operator>(const LLINT &x1, const LLINT &x2)
{
	if(x1.a1 > x2.a1)
		return true;
	else if(x1.a1 == x2.a1)
		return x1.a0 > x2.a0;
	else
		return false;
}

bool operator<(const LLINT &x1, const LLINT &x2)
{
	if(x1.a1 < x2.a1)
		return true;
	else if(x1.a1 == x2.a1)
		return x1.a0 < x2.a0;
	else
		return false;
}

bool operator<=(const LLINT &x1, const LLINT &x2)
{
	if(x1.a1 < x2.a1)
		return true;
	else if(x1.a1 == x2.a1)
		return x1.a0 <= x2.a0;
	else
		return false;
}

LLINT::LLINT atoLLINT(const char *str)
{
	LLINT x;
	int i, j=0, n;
	unsigned long long p0=1, p1=1;
	for(n=0; str[n]; n++)
		;
	if(n==0) return x;
	for(i=n-1; i>=0; i--)
	{
		if('0'<=str[i] && str[i]<='9')
		{
			if(j<18)
			{
				x.a0 += p0*(str[i]-'0');
				p0 *= 10;
			}
			else if(j<36)
			{
				x.a1 += p1*(str[i]-'0');
				p1 *= 10;
			}
			j++;
		}
	}
	return x;
}
/////////////////////////
// �� (4��)ǰ�����������������
LLINT & LLINT::operator++()
{
	a0++;
	if(a0==BBILLION)
	{
		a0 = 0;
		a1++;
	}
	return *this;
}

// �� (4��)�Ӹ�ֵ�������������
LLINT & LLINT::operator+=(const LLINT &x)
{
	*this = *this + x;
	return *this;
}

// �� (4��)��ϵ����������ڻ���ڣ���������
bool operator>=(const LLINT &x1, const LLINT &x2)
{
	if(x1.a1 > x2.a1)
		return true;
	else if(x1.a1 == x2.a1)
		return x1.a0 >= x2.a0;
	else
		return false;
}

// �� (4��)��ϵ����������ڣ���������
bool operator==(const LLINT &x1, const LLINT &x2)
{
	return (x1.a1==x2.a1) && (x1.a0==x2.a0);
}

// �� (4��)��ϵ������������ڣ���������
bool operator!=(const LLINT &x1, const LLINT &x2)
{
	return (x1.a1!=x2.a1) || (x1.a0!=x2.a0);
}



