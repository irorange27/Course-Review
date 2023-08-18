// exchange.cpp
#include <iostream>
#include <cstring>
using namespace std;

void Exchange(const char *&str1, const char *&str2)
{	// 形参不使用二级指针，而使用指针的常引用（常量指针的别名）
	const char *temp;
	temp = str1;
	str1 = str2;
	str2 = temp;
}

void Swap(char * const str1, char * const str2)
{	// 形参为锁定目标的指针（即指针常量，亦即指针的指向不能改变，内容可更改）
	int n = strlen(str1) + 1;
	char *temp = new char[n];
	strcpy(temp, str1);
	strcpy(str1, str2);
	strcpy(str2, temp);
	delete [] temp;
}

int Test02()
{
	char str1[80] = "Tom", str2[80] = "Jerry";
	const char *p1 = "Tom", *p2 = "Jerry";
	cout << str1 << '\t' << str2 << endl;
	cout << p1 << '\t' << p2 << endl;
	Exchange(p1, p2);
	Swap(str1, str2);
	cout << str1 << '\t' << str2 << endl;
	cout << p1 << '\t' << p2 << endl;
	return 0;
}
