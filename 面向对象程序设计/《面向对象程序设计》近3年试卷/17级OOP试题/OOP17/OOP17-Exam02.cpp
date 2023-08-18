// OOP17-Exam02.cpp
#include <iostream>
#include <cstring>
using namespace std;

void SWAP1R(char &x, char &y)	// �����ַ�
{
	char temp = x;
	x = y;
	y = temp;
}

void SWAP1P(char *x, char *y)	// �����ַ�
{
	char temp = *x;
	*x = *y;
	*y = temp;
}

void SWAP2R(char *&x, char *&y)	// �����ַ���ָ��
{
	char *temp = x;
	x = y;
	y = temp;
}

void SWAP2P(char **x, char **y)	// �����ַ���ָ��
{
	char *temp;
	temp = *x;
	*x = *y;
	*y = temp;
}

void SWAP_STR(char *const x, char *const y)	// �����ַ�������
{
	char *p = new char[strlen(x)+1];
	strcpy(p, x);
	strcpy(x, y);
	strcpy(y, p);
	delete [] p;
}

int main02()
{
	char c1='A', c2='B';
	char *p="Tom", *q="Jerry";			// ָ���������ַ��������ݲ��ܸ��ģ�
	char s[10]="Hello", t[10]="World";	// ������Ϊ��ַ����������ַ���ܸ��ģ�
	
	SWAP1R(c1, c2);
	cout << "c1 = " << c1 << ", c2 = " << c2 << endl;
	SWAP1P(&c1, &c2);
	cout << "c1 = " << c1 << ", c2 = " << c2 << endl;
	SWAP2R(p, q);
	cout << "p = " << p << ", q = " << q << endl;
	SWAP2P(&p, &q);
	cout << "p = " << p << ", q = " << q << endl;
	SWAP_STR(s, t);
	cout << "s = " << s << ", t = " << t << endl;
	return 0;
}
