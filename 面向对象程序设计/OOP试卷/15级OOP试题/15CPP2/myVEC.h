// myVEC.h
#ifndef MY_VEC_H
#define MY_VEC_H
#include <iostream>
using namespace std;

template <typename T> class VECTOR	// 抽象向量类模板
{
public:
	VECTOR(int size=0, const T *x=NULL)	// 构造函数
	{
		num = (size>0)? size : 0;
		p = NULL;
		if(num>0)
		{
			p = new T[num];
			for(int i=0; i<num; i++)
				p[i] = (x!=NULL)? x[i] : 0;
		}
	}
	VECTOR(const VECTOR &v): num(0),p(NULL)	// 拷贝构造函数
	{
		*this = v;
	}
	virtual ~VECTOR()						// 虚析构函数
	{
		if(p!=NULL) delete [] p;
		num = 0;
		p = NULL;
	}
	VECTOR & operator=(const VECTOR &v)		// 赋值运算符函数
	{
		if(&v == this) return *this;
		if(p!=NULL) delete [] p;
		num = v.num;
		p = NULL;
		if(num>0)
		{
			p = new T[num];
			for(int i=0; i<num; i++)
				p[i] = v.p[i];
		}
		return *this;
	}
	T & operator[](int index) const			// 方括号运算符函数
	{
		return p[index];
	}
	virtual void Output(ostream &out) const = 0;	// 纯虚函数
protected:
	int num;
	T *p;
};

template <typename T> ostream & operator<<(ostream &out, const VECTOR<T> &v)
{
	v.Output(out);
	return out;
}
#endif
