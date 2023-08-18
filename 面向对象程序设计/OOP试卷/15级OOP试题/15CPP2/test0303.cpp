// test0303.cpp
#include "myVector.h"

int Test0303()
{
	double a[] = {1.414, 2.718, 3.14};
	int n = sizeof(a)/sizeof(*a);
	Vector<double> v0, v1(1), v2(2, a), v3(n, a), v[]={v0, v1, v2, v3};
	n = sizeof(v)/sizeof(*v);
	// ����������
	Vector<Vector<double> > d2(n, v);	// ��ͬ�ھ���������е�ά����һ����ͬ��

	for(int i=0; i<n; i++)
		cout << v[i] << endl;
	cout << d2 << endl;

	// �ַ���������ַ�������
	Vector<char> s0("Hello"), s1("World!"), s[] = {s0, s1};
	n = sizeof(s)/sizeof(*s);
	Vector<Vector<char> > v_str(n, s);	// �ַ�������

	for(int i=0; i<n; i++)
		cout << v_str[i] << endl;
	cout << "[" << v_str << "]" << endl;
	swap(v_str[0], v_str[1]);
	v_str[0] = "WORLD";
	v_str[1][0] = 'h';
	cout << "[" << v_str << "]" << endl;
	cout << s[0] << " " << s[1] << endl;
	return 0;
}
