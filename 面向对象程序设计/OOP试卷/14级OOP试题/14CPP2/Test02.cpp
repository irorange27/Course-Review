// Test02.cpp
#include <iostream>
#include <cstring>
#include <string>
using namespace std;

class String
{
public:
	String(const char *str="")
	{
		size = strlen(str);
		x = size>0 ? new char[size] : NULL;
		if(x==NULL) size = 0;
		for(int i=0; i<size; i++)
			x[i] = str[i];
	}
	String(const String &s) : x(NULL)
	{
		*this = s;	// 直接利用深赋值运算符函数
	}
	virtual ~String()
	{
		if(x!=NULL) delete [] x;
		size = 0;
	}
	String & operator=(const String &s)
	{
		if(&s == this) return *this;
		if(x!=NULL) delete [] x;
		size = s.size;
		x = new char[size];
		if(x==NULL) size = 0;
		for(int i=0; i<size; i++)
			x[i] = s.x[i];
		return *this;
	}
	char & operator[](int index)
	{
		return x[index];
	}
	friend ostream & operator<<(ostream &out, const String &s)
	{
		for(int i=0; i<s.size; i++)
			out << s.x[i];
		return out;
	}
	friend istream & operator>>(istream &in, String &s)
	{
		string str;
		in >> str;					// 利用C++字符串
		s = String(str.c_str());	// 利用深赋值运算符
		return in;
	}
	friend int Compare(const String &s1, const String &s2)
	{
		int i;
		for(i=0; i<s1.size && i<s2.size && s1.x[i]==s2.x[i]; i++)
			;
		if(i<s1.size && i<s2.size)
			return s1.x[i] > s2.x[i] ? 1 : -1;
		else if(i<s1.size && i==s2.size)
			return 1;
		else if(i==s1.size && i<s2.size)
			return -1;
		else
			return 0;
	}
	friend bool operator<(const String &s1, const String &s2)
	{
		return Compare(s1, s2) < 0;
	}
	friend bool operator<=(const String &s1, const String &s2)
	{
		return Compare(s1, s2) <= 0;
	}
	friend bool operator>(const String &s1, const String &s2)
	{
		return Compare(s1, s2) > 0;
	}
	friend bool operator>=(const String &s1, const String &s2)
	{
		return Compare(s1, s2) >= 0;
	}
	friend bool operator==(const String &s1, const String &s2)
	{
		return Compare(s1, s2) == 0;
	}
	friend bool operator!=(const String &s1, const String &s2)
	{
		return Compare(s1, s2) != 0;
	}
protected:
	char *x;
	int size;
};

void display(const String &s1, const String &s2)
{
	char *str[] = {"小于", "等于", "大于"};
	cout << "\"" << s1 << "\" " << str[1+Compare(s1, s2)]
		 << " \"" << s2 << "\"\t" << endl;
}

int Testing02()
{
	String s1("Hello world!"), s2(s1);
	display(s1, s2);
	s2[0] = 'h';
	display(s1, s2);
	s2 = "Hello world ";
	display(s1, s2);
	s2 = "Hello world";
	display(s1, s2);
	s1 = "";
	s2 = "";
	display(s1, s2);
	return 0;
}
