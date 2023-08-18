// Vector.h
#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
using namespace std;

class Vector
{
public:
	Vector(int dim=1, double *a=NULL) : x(NULL),n(dim)
	{
		if(n<=0) n=1;		// ������0ά������������ά������Ϊ1
		x = new double[n];
		for(int i=0; i<n; i++)
			x[i] = (a==NULL)? 0 : a[i];
	}
	Vector(const Vector &v) : x(NULL),n(0)
	{
		*this = v;
	}
	virtual ~Vector()
	{
		if(x!=NULL) delete [] x;
	}
	Vector & operator=(const Vector &v)
	{
		if(&v == this) return *this;
		if(x!=NULL) delete [] x;
		n = v.n;
		x = new double[n];
		for(int i=0; i<n; i++)
			x[i] = v.x[i];
		return *this;
	}
	Vector & operator*=(double k)
	{
		for(int i=0; i<n; i++)
			x[i] *= k;
		return *this;
	}
	double operator*(const Vector &v)
	{
		double result=0;
		for(int i=0; i<n; i++)
			result += x[i]*v.x[i];
		return result;
	}
	friend ostream & operator<<(ostream &out, const Vector &v)
	{
		out << '(' << v.x[0];
		for(int i=1; i<v.n; i++)
			out << ", " << v.x[i];
		out << ')';
		return out;
	}
	friend istream & operator>>(istream &in, Vector &v)
	{
		char str[200];
		int i, n;
		in.getline(str, 200, '(');
		in.getline(str, 200, ')');
		for(i=n=0; str[i]!='\0'; i++)
			if(str[i]==',') n++;		// ������n�����ţ�˵����n+1ά����
		if(v.n != n+1)					// ���ά���б仯�������
		{
			if(v.x!=NULL) delete [] v.x;// �ͷ�ԭ����Դ
			v.n = n+1;
			v.x = new double[v.n];		// ���������ʵ������Ķ��ڴ浥Ԫ
		}
		int *index = new int[v.n];		// ���붯̬���飬���ÿ�����ź��һ���ַ����±�
		index[0] = 0;					// ��һ���ַ�����"�׵�ַ"��ԭ����ͬ
		for(i=0,n=1; str[i]!='\0'; i++)
		{
			if(str[i]==',')
			{
				str[i] = '\0';			// ��ԭ�ַ���str�еĶ��Ż���'\0'�������n���ַ���
				index[n++] = i+1;		// ��¼��ÿ���ַ������׵�ַ�����±�
			}
		}
		for(i=0; i<v.n; i++)
			v.x[i] = atof(str+index[i]);
		delete [] index;
		return in;
	}
private:
	double *x;
	int n;
};

#endif
