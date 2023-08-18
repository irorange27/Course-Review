/* IPv4.h
IPv4(Internet Protocol version 4)��ַ�ɱ�д���κα�ʾһ��32λ����ֵ����ʽ��
��Ϊ�˷������࣬��ͨ����д�����ʮ����(dotted-decimal notation)����ʽ
(���ĸ��ֽڱ��ֿ���ʮ����д�����м��õ�ָ�)��        */
#ifndef IP_V_4_H
#define IP_V_4_H
#include <iostream>
using namespace std;

class IPv4
{
public:
	IPv4(char *ip="127.0.0.1")
	{
		int i;
		a = b = c = d = 0;
		for(i=0; ip[i]!='.'; i++)
			if(ip[i]>='0' && ip[i]<='9')
				a = 10*a + ip[i]-'0';
		for(i++; ip[i]!='.'; i++)
			if(ip[i]>='0' && ip[i]<='9')
				b = 10*b + ip[i]-'0';
		for(i++; ip[i]!='.'; i++)
			if(ip[i]>='0' && ip[i]<='9')
				c = 10*c + ip[i]-'0';
		for(i++; ip[i]!='\0'; i++)
			if(ip[i]>='0' && ip[i]<='9')
				d = 10*d + ip[i]-'0';
	}
	IPv4 & operator++()
	{
		d++;
		if(d==256){ d=0; c++; }
		if(c==256){ c=0; b++; }
		if(b==256){ b=0; a++; }
		if(a==256){ a=0; }
		return *this;
	}
	IPv4 operator++(int)
	{
		IPv4 temp(*this);
		++(*this);
		return temp;
	}
	IPv4 & operator--()
	{
		d--;
		if(d==-1){ d=255; c--; }
		if(c==-1){ c=255; b--; }
		if(b==-1){ b=255; a--; }
		if(a==-1){ a=255; }
		return *this;
	}
	IPv4 operator--(int)
	{
		IPv4 temp(*this);
		--(*this);
		return temp;
	}
	int & operator[](int k)
	{
		switch(k)
		{
		case 0: return a;
		case 1: return b;
		case 2: return c;
		default:return d;
		}
	}
	unsigned long int get() const
	{
		unsigned long int n;
		n = d + 256*(c + 256*(b + 256*a));
		return n;
	}
	void set(unsigned long n)
	{
		d = n % 256;
		c = n/256 % 256;
		b = n/256/256 % 256;
		a = n/256/256/256 % 256;
	}
	IPv4 operator+(int n)
	{
		IPv4 temp;
		temp.set(get()+n);
		return temp;
	}
	IPv4 & operator+=(int n)
	{
		*this = *this + n;
		return *this;
	}
	IPv4 operator-(int n)
	{
		return *this+(-n);
	}
	IPv4 & operator-=(int n)
	{
		*this = *this + (-n);
		return *this;
	}
	int operator-(const IPv4 &ip)
	{
		return get() - ip.get();
	}
	friend bool operator> (const IPv4 &ip1, const IPv4 &ip2)
	{
		return ip1.get() > ip2.get();
	}
	friend bool operator>=(const IPv4 &ip1, const IPv4 &ip2)
	{
		return ip1.get() >= ip2.get();
	}
	friend bool operator< (const IPv4 &ip1, const IPv4 &ip2)
	{
		return ip1.get() < ip2.get();
	}
	friend bool operator<=(const IPv4 &ip1, const IPv4 &ip2)
	{
		return ip1.get() <= ip2.get();
	}
	friend bool operator==(const IPv4 &ip1, const IPv4 &ip2)
	{
		return ip1.get() == ip2.get();
	}
	friend bool operator!=(const IPv4 &ip1, const IPv4 &ip2)
	{
		return ip1.get() != ip2.get();
	}
	friend ostream & operator<<(ostream &out, const IPv4 &ip)
	{
		out << ip.a << '.' << ip.b << '.' << ip.c << '.' << ip.d;
		return out;
	}
	friend istream & operator>>(istream &in, IPv4 &ip)
	{
		char str[100];
		in.getline(str, 100);
		ip = str;
		return in;
	}
private:
	int a, b, c, d;
};

#endif
