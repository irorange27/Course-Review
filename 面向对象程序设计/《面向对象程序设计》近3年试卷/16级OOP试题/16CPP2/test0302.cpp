// test0302.cpp
#include <iostream>
using namespace std;

class Language
{
public:
	virtual void SayHello() const
	{
		cout << "How are you!" << endl;
	}
	virtual void SayByebye() const
	{
		cout << "Goodbye!" << endl;	
	}
};

class Chinese : public Language
{
public:
	void SayHello() const
	{
		cout << "��ã�" << endl;
	}
	void SayByebye() const
	{
		cout << "�ټ���" << endl;
	}
};

class Japanese : public Language
{
public:
	void SayHello() const
	{
		cout << "����ˤ���!" << endl;
	}
	void SayByebye() const
	{
		cout << "���褦�ʤ�!" << endl;
	}
};

class English : public Language
{
public:
	void SayHello() const
	{
		cout << "Hello!" << endl;
	}
	void SayByebye() const
	{
		cout << "Bye-bye!" << endl;
	}
};

int test0302A(const Language &p)
{
	p.SayHello();
	p.SayByebye();
	return 0;
}

int test0302B(const Language *p)
{
	p->SayHello();
	p->SayByebye();
	return 0;
}

int test0302C(const Language p)
{
	p.SayHello();
	p.SayByebye();
	return 0;
}

int Test0302()
{
	Chinese c;
	Japanese j;
	English e;
	
	test0302A(c);
	test0302A(j);
	test0302A(e);

	test0302B(&c);
	test0302C(c);
	return 0;
}
