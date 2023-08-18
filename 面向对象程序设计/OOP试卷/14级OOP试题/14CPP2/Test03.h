// test03.h
#ifndef TEST03_H
#define TEST03_H
#include <iostream>
using namespace std;

class Test1
{
public:
	Test1(int a=0);
	Test1(const Test1 &t);
	virtual ~Test1();
	Test1 & operator=(const Test1 &t);
	static int Num();
	static int Sum();
	friend ostream & operator<<(ostream &out, const Test1 &t);
	friend istream & operator>>(istream &in, Test1 &t);
protected:
	static int num, sum;
	int x;
};

void Show();					// 普通的C++函数声明
#endif
