// myVEC.h
#ifndef MY_VEC_H
#define MY_VEC_H
#include <iostream>
using namespace std;

template <typename T> class VECTOR	// ����������ģ��
{
public:
	VECTOR(int size=0, const T *x=NULL)	// ���캯��
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
	VECTOR(const VECTOR &v): num(0),p(NULL)	// �������캯��
	{
		*this = v;
	}
	virtual ~VECTOR()						// ����������
	{
		if(p!=NULL) delete [] p;
		num = 0;
		p = NULL;
	}
	VECTOR & operator=(const VECTOR &v)		// ��ֵ���������
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
	T & operator[](int index) const			// ���������������
	{
		return p[index];
	}
	virtual void Output(ostream &out) const = 0;	// ���麯��
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
