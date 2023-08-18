// OOP17-Exam03.cpp
#include <iostream>
using namespace std;

#define MAX_STACK 5
template <typename T> class ArrayStack
{
public:
	ArrayStack():top(-1){}	// ���캯��
	int Size() const;		// ��ȡջ�е�ǰӵ�е�Ԫ�ظ���
	bool Empty() const;		// ��ջΪ��ʱ����true�����򷵻�false
	bool Top(T &t) const;	// ��ջΪ�ǿ�ʱ����true����ͨ��������ȡջ��Ԫ�أ����򷵻�false
	bool Push(const T &t);	// ��ջ����ʱ����false�����򷵻�true�������� t ѹջ
	bool Pop(T &t);			// ��ջΪ��ʱ����false�����򷵻�true����ջ��Ԫ�س�ջ��ջ��Ԫ�ش��� t��
private:
	T x[MAX_STACK];
	int top;
};

template <typename T> int ArrayStack<T>::Size() const
{
    return top + 1;
}

template <typename T> bool ArrayStack<T>::Empty() const
{
	return top == -1;
}

template <typename T> bool ArrayStack<T>::Top(T &t) const
{
	if(top >= 0)
	{
		t = x[top];
		return true;
	}
	return false;
}

template <typename T> bool ArrayStack<T>::Push(const T &t)
{
	if(top < MAX_STACK-1)
	{
		x[++top] = t;
		return true;
	}
	return false;
}

template <typename T> bool ArrayStack<T>::Pop(T &t)
{
	if(top >= 0)
	{
		t = x[top--];
		return true;
	}
	return false;
}

//////////////////////////////////
int main0301()
{
	int x[] = {0, 1, 1, 1, 1, 1, 1, 0, 0, 0};
	int y[] = {47, 26, 71, 38, 69, 12, 67, 99, 35, 94};
	int n = sizeof(x)/sizeof(*x);
	int m = sizeof(y)/sizeof(*y);
	ArrayStack<int> s;
	int i, j, z;
	
	for(i=j=0; i<n; i++,j%=m)
	{
		if(x[i]==1)
		{
			if(s.Push(y[j]))
				cout << y[j++] << " ��ջ" << endl;
			else
				cout << "ջ�������޷���ջ" << endl;
		}
		else
		{
			if(s.Pop(z))
				cout << z << " ��ջ" << endl;
			else
				cout << "ջ�ѿգ���Ԫ�س�ջ" << endl;
		}
	}
	return 0;
}

//////////////////////////////////
bool Trans(unsigned int n, int Base=2)	// ʮ���ƷǸ�����ת����Base����(Base��Ϊ2,3,...,36)
{
	if(n==0)
	{
		cout << 0 << endl;
		return true;
	}
	char BASE[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int x;
	ArrayStack<int> s;
	for( ; n!=0; n/=Base)
		if(!s.Push(n%Base))
			return false;
	while(s.Size()>0)
	{
		s.Pop(x);
		cout << BASE[x];
	}
	return true;
}

int main0302()
{
	int base[] = {2, 3, 4, 5, 8, 10, 16, 36};
	int n = sizeof(base)/sizeof(*base), x=255;
	for(int i=0; i<n; i++)
	{
		cout << '(' << x << ")_10 = (";
		if(!Trans(x, base[i]))
			cout << "ջ������޷�ת��";
		cout << ")_" << base[i] << endl;
	}
	return 0;
}

////////////////////////////////////////////
int Pos(char c, const char *str)
{
	for(int i=0; str[i]!='\0'; i++)
		if(c == str[i])
			return i;
	return -1;
}

int Matching(const char *str)
{
	ArrayStack<char> s;
	char c;

	for(int i=0; str[i]!='\0'; i++)
	{
		if(Pos(str[i], "([{")>=0)
		{
			if(s.Push(str[i])==false)	// ջ���
				return -1;
		}
		if(Pos(str[i], ")]}")>=0)
		{
			if(s.Pop(c)==false)			// ջ�ѿ�
				return -2;
			if(str[i]==')' && c!='(' || str[i]==']' && c!='[' || str[i]=='}' && c!='{')
				return -3;				// ���Ų�ƥ��
		}
	}
	return s.Empty()?0:-4;	// �ַ����Ѵ�����ϣ���ջ���Ƿ�������δƥ������Ŷ���
}

int main0303()
{
	char a[][100] = {"(())abc{[(])}", "(()))abc{[]}", "((((((((((()",
					 ")(", "(()()abc{[]}", "(())abc{[]()}", "abc",
					"int main()\n{\n\tint array[10];\n\treturn(0);\n}\n" };
	int n = sizeof(a)/sizeof(*a);

	for(int i=0; i<n; i++)
	{
		cout << a[i];
		switch(Matching(a[i]))
		{
		case -1:	cout << " ջ�ռ�̫С����������޷��жϡ�" << endl; break;
		case -2:	cout << " ջ�ѿգ�˵����ʱ�����Ŷ��������š�" << endl; break;
		case -3:	cout << " �������಻ƥ�䡣" << endl; break;
		case -4:	cout << " �ַ���������ϣ�������������û��ƥ���ꡣ" << endl; break;
		default:	cout << " ����ƥ����ȷ��" << endl; break;
		}
	}
	return 0;
}

//////////////////////////////////
#include <cmath>
double cube(double x)
{
	return x*x*x;
}
int main0304()	// ָ������ָ�����
{
	ArrayStack<double(*)(double)> fs;
	double (*f)(double);// ����ָ�����f������ָ��ĳһ�ຯ������ڵ�ַ���˴�f����ָ��һ��double�βΣ��ҷ�������Ϊdouble���ĺ���
	fs.Push(sin);		// ������Ϊ��������ڵ�ַ
	fs.Push(cos);
	fs.Push(sqrt);
	fs.Push(exp);
	fs.Push(cube);
	fs.Pop(f); cout << f(2) << endl;
	fs.Pop(f); cout << f(1) << endl;
	fs.Pop(f); cout << f(2) << endl;
	fs.Pop(f); cout << f(0) << endl;
	fs.Pop(f); cout << f(0) << endl;
	return 0;
}

int main03()
{
	main0301();	cout << endl;
	main0302();	cout << endl;
	main0303();	cout << endl;
	main0304();	cout << endl;
	return 0;
}
