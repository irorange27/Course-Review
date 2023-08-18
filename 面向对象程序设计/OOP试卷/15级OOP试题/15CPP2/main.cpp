// main.cpp
#include <iostream>
#include <conio.h>
using namespace std;
	
int Test02(), Test0301(), Test0302(), Test0303(), Test04();

int main()
{
	int (*f[])() = {Test02, Test0301, Test0302, Test0303, Test04};
	int n = sizeof(f)/sizeof(*f), choice;

	while(true)
	{
		cout << "Testing 1 -- " << n << ", (0--exit): ";
		choice = getche()-'0';
		cin.sync();
		cout << endl;
		if(choice<=0)
			break;
		if(choice<=n)
			f[choice-1]();
	}
	return 0;
}
