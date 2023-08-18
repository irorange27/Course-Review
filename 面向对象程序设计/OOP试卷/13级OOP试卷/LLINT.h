// LLINT.h						ͷ�ļ�
#ifndef LLINT_H
#define LLINT_H
#include <iostream>
using namespace std;

class LLINT
{
public:
	LLINT(unsigned long long x0=0, unsigned long long x1=0);
							// ��һ����Ϊ��λ
	LLINT(const char *str);
	LLINT & operator++();
	LLINT operator++(int);
	friend LLINT operator+(const LLINT &x1, const LLINT &x2);
	LLINT & operator+=(const LLINT &x);
	friend ostream & operator<<(ostream &out, const LLINT &x);
	friend LLINT atoLLINT(const char *str);
	friend istream & operator>>(istream &in, LLINT &x);
	friend bool operator> (const LLINT &x1, const LLINT &x2);
	friend bool operator>=(const LLINT &x1, const LLINT &x2);
	friend bool operator< (const LLINT &x1, const LLINT &x2);
	friend bool operator<=(const LLINT &x1, const LLINT &x2);
	friend bool operator==(const LLINT &x1, const LLINT &x2);
	friend bool operator!=(const LLINT &x1, const LLINT &x2);
protected:
	static const unsigned long long BBILLION;
	unsigned long long a1, a0;
	//a1*1 000 000 000 000 000 000 + a0�ɱ�ʾ36~37λʮ���ƷǸ�����
};
#endif
