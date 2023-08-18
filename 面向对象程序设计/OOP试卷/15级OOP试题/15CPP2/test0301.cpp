// test0301.cpp
#include <iostream>
using namespace std;

class ctest
{
public:
	ctest(int x=0):a(x){cout << "�������(" << a << ")\n";}
	~ctest(){ cout << "��������(" << a << ")\n";}
	ctest & Add()
	{
		++a;
		return *this;
	}
	ctest add()
	{
		ctest temp(*this);
		++a;
		return temp;
	}
	friend ostream & operator<<(ostream &out, const ctest &c)
	{
		out << c.a;
		return out;
	}
private:
	int a;
};

int Test0301()
{
	ctest a(100), b(200);
	cout << a << ", " << b << endl;	// ��3�����
	a.Add().Add();
	b.add().add();		// ע�⣺����������ʱ�������������
	cout << a << ", " << b << endl;	// ��6�����
	a.~ctest();			// �������������������������ٶ���
	b.~ctest();			// �������������������������ٶ���
	cout << a << ", " << b << endl;	// ��9�����
	cout << "���ز���ϵͳ��" << endl;	// ��10�����
	return 0;
}
