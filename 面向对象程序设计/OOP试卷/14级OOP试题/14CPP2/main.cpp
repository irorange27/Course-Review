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
		cout << "\n��ע���޸�Test03.cpp�ļ��е�54�б�ʶ��TESTING_GLOBAL�ĺ궨�塣" << endl;
		cout << "�Ƿ��иú궨�壬ʵΪ������ͬ�ĳ��򣬷ֱ������ȫ�ֶ������ȫ�ֶ�������Ρ�" << endl;
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
