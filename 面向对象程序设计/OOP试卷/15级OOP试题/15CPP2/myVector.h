// myVector.h
#ifndef MY_VECTOR_H
#define MY_VECTOR_H
#include <cstring>
#include "myVEC.h"

template <typename T> class Vector : public VECTOR<T>
{
public:
	Vector(int size=0, const T *x=NULL):VECTOR<T>(size, x)
	{			// ���캯��
	}
	void Output(ostream &out) const
	{
		if(this->num==0)
			out << "()";
		else
		{
			out << '(' << this->p[0];
			for(int i=1; i<this->num; i++)
				out << ", " << this->p[i];
			out << ')';
		}
	}
};

// ������ģ�壨���þ������� char ��ȫ�ػ���ʽ�������� T��
template <> class Vector<char> : public VECTOR<char>
{			// ��Vector<char>�ദ������������־���ַ���
public:
	Vector<char>(const char *x=""):VECTOR<char>(strlen(x), x)
	{				// ���캯��
	}
	void Output(ostream &out) const
	{
		for(int i=0; i<num; i++)
			out << p[i];
	}
};
#endif
