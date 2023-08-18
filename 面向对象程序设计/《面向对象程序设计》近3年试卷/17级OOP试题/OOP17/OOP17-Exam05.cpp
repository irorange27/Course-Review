// OOP17-Exam05.cpp
#include <iostream>
using namespace std;

template <typename T> class Stack
{
private:
	T *x;
	int top, max;
public:
	Stack(int Max=5);					// �ٹ��캯��
	Stack(const Stack &s);				// �ڿ������캯��
	~Stack();							// ����������
	Stack & operator=(const Stack &s);	// �ܸ�ֵ�������������
	int Size() const;					// �ݻ�ȡջ�е�ǰӵ�е�Ԫ�ظ���
	bool Empty() const;		// �޵�ջΪ��ʱ����true�����򷵻�false
	bool Top(T &t) const;	// �ߵ�ջΪ�ǿ�ʱ����true����ͨ��������ȡջ��Ԫ�أ����򷵻�false
	bool Push(const T &t);	// �൱ջ����ʱ����false�����򷵻�true�������� t ѹջ
	bool Pop(T &t);			// �ᵱջΪ��ʱ����false�����򷵻�true����ջ��Ԫ�س�ջ��ջ��Ԫ�ش��� t��
};

//////////////////////////////////
template <typename T> Stack<T>::Stack(int Max): x(NULL),top(-1),max(0)			// �ٹ��캯��
{
	if(Max<=0) return;
	x = new T[max=Max];
}
template <typename T> Stack<T>::Stack(const Stack &s): x(NULL),top(-1),max(0)	// �ڿ������캯��
{
	*this = s;
}
template <typename T> Stack<T>::~Stack()										// ����������
{
	if(x!=NULL) delete [] x;
	top = -1;
	max = 0;
}
template <typename T> Stack<T> & Stack<T>::operator=(const Stack<T> &s)			// �ܸ�ֵ�������������
{
	if(this==&s) return *this;
	if(x!=NULL) delete [] x;
	top = s.top;
	max = s.max;
	if(s.x!=NULL)
	{
		x = new T[max];
		for(int i=0; i<=top; i++)	// ջ�����ϵ����븴��
			x[i] = s.x[i];
	}
	else
		x = NULL;
}
template <typename T> int Stack<T>::Size() const		// �ݻ�ȡջ�е�ǰӵ�е�Ԫ�ظ���
{
	return top + 1;
}
template <typename T> bool Stack<T>::Empty() const		// �޵�ջΪ��ʱ����true�����򷵻�false
{
	return top == -1;
}
template <typename T> bool Stack<T>::Top(T &t) const	// �ߵ�ջΪ�ǿ�ʱ����true����ͨ��������ȡջ��Ԫ�أ����򷵻�false
{
	if(top >= 0)
	{
		t = x[top];
		return true;
	}
	return false;
}
template <typename T> bool Stack<T>::Push(const T &t)	// �൱ջ����ʱ����false�����򷵻�true�������� t ѹջ
{
	if(top < max-1)
	{
		x[++top] = t;
		return true;
	}
	return false;
}
template <typename T> bool Stack<T>::Pop(T &t)			// �ᵱջΪ��ʱ����false�����򷵻�true����ջ��Ԫ�س�ջ��ջ��Ԫ�ش��� t��
{
	if(top >= 0)
	{
		t = x[top--];
		return true;
	}
	return false;
}

//////////////////////////////////////////
int main0501()
{
	int x[] = {0, 1, 1, 1, 1, 1, 1, 0, 0, 0};
	int y[] = {47, 26, 71, 38, 69, 12, 67, 99, 35, 94};
	int n = sizeof(x)/sizeof(*x);
	int m = sizeof(y)/sizeof(*y);
	Stack<int> s;
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

//////////////////////////////////////////
bool Trans1(unsigned int n, int Base=2)	// ʮ���ƷǸ�����ת����Base����(Base��Ϊ2,3,...,36)
{
	if(n==0)
	{
		cout << 0 << endl;
		return true;
	}
	char BASE[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int x;
	Stack<int> s;
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
int main0502()
{
	int base[] = {2, 3, 4, 5, 8, 10, 16, 36};
	int n = sizeof(base)/sizeof(*base), x=255;
	for(int i=0; i<n; i++)
	{
		cout << '(' << x << ")_10 = (";
		if(!Trans1(x, base[i]))
			cout << "ջ������޷�ת��";
		cout << ")_" << base[i] << endl;
	}
	return 0;
}

////////////////////////////////////////////
int Pos(char c, const char *str);		// �������Ѿ����壬�˴���������

int Matching1(const char *str)
{
	Stack<char> s;
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
int main0503()
{
	char a[][100] = {"(())abc{[(])}", "(()))abc{[]}", "((((((((((()",
					 ")(", "(()()abc{[]}", "(())abc{[]()}", "abc",
					"int main()\n{\n\tint array[10];\n\treturn(0);\n}\n" };
	int n = sizeof(a)/sizeof(*a);

	for(int i=0; i<n; i++)
	{
		cout << a[i];
		switch(Matching1(a[i]))
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

////////////////////////////////////////
#include <cmath>
double cube(double x);
int main0504()	// ָ������ָ�����
{
	Stack<double(*)(double)> fs;
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

int main05()
{
	main0501();	cout << endl;
	main0502();	cout << endl;
	main0503();	cout << endl;
	main0504();	cout << endl;
	return 0;
}
