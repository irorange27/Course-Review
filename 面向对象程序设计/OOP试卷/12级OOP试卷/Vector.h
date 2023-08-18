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
		if(n<=0) n=1;		// 不允许0维向量，向量的维数至少为1
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
			if(str[i]==',') n++;		// 读到了n个逗号，说明是n+1维向量
		if(v.n != n+1)					// 如果维数有变化，则调整
		{
			if(v.x!=NULL) delete [] v.x;// 释放原有资源
			v.n = n+1;
			v.x = new double[v.n];		// 重新申请适当容量的堆内存单元
		}
		int *index = new int[v.n];		// 申请动态数组，存放每个逗号后的一个字符的下标
		index[0] = 0;					// 第一个字符串的"首地址"与原串相同
		for(i=0,n=1; str[i]!='\0'; i++)
		{
			if(str[i]==',')
			{
				str[i] = '\0';			// 将原字符串str中的逗号换成'\0'，即拆成n个字符串
				index[n++] = i+1;		// 记录下每个字符串”首地址”的下标
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
