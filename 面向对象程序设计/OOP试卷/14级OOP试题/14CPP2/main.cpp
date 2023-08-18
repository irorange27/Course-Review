// main.cpp
#include <iostream>
#include <conio.h>
using namespace std;

int Testing02(), Testing03a(), Testing03(), ComplexTesting();

int main()
{
	int (*f[])() = {Testing02, Testing03a, Testing03, ComplexTesting};
	int n = sizeof(f)/sizeof(*f), choice;

	while(true)
	{
		cout << "\n请注意修改Test03.cpp文件中第54行标识符TESTING_GLOBAL的宏定义。" << endl;
		cout << "是否有该宏定义，实为两个不同的程序，分别测试有全局对象和无全局对象的情形。" << endl;
		cout << "Testing 1 -- " << n << ", (0--exit): ";
		choice = getch()-'0';
		cout << endl;
		if(choice<=0)
			break;
		if(choice<=n)
			f[choice-1]();
	}
	return 0;
}
