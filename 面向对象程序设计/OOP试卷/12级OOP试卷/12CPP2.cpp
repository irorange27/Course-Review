// 12CPP2.cpp
#include <iostream>
using namespace std;

int main_test2(); 
int main_test31(), main_test32(), main_test33(), main_test34();
int main_test35(), main_test36(), main_test37(), main_test38();
int main_test41(), main_test42(), main_test43(), main_test44(), main_test45();
int main_test5();

int main()
{
	int choice;
	while(true)
	{
		cout << "\n2, 31-38, 41-45, 5, 0--exit: ";
		cin >> choice;
		if(choice<=0) break;
		switch(choice)
		{
		case  2: main_test2(); break;

		case 31: main_test31(); break;
		case 32: main_test32(); break;
		case 33: main_test33(); break;
		case 34: main_test34(); break;
		case 35: main_test35(); break;
		case 36: main_test36(); break;
		case 37: main_test37(); break;
		case 38: main_test38(); break;

		case 41: main_test41(); break;
		case 42: main_test42(); break;
		case 43: main_test43(); break;
		case 44: main_test44(); break;
		case 45: main_test45(); break;

		case  5: main_test5(); break;
		}
	}
	return 0;
}
