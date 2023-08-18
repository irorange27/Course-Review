// 13CPP2.cpp
#include <iostream>
using namespace std;

int main_test2(); 
int main_test31(), main_test32(), main_test33();
int main_test4();

int main()
{
	int choice;
	while(true)
	{
		cout << "\n2, 31, 32, 33, 4, 0--exit: ";
		cin >> choice;
		if(choice<=0) break;
		switch(choice)
		{
		case  2: main_test2(); break;

		case 31: main_test31(); break;
		case 32: main_test32(); break;
		case 33: main_test33(); break;

		case  4: main_test4(); break;
		}
	}
	return 0;
}
