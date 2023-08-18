// 11OOP.cpp
#include <iostream>
using namespace std;

int mainIPv4(), mainMatrix(), mainComplex(), mainDerived();

int main()
{
	int choice;
	while(true)
	{
		cout << "1 ---- Matrix\n"
			 << "2 ---- Complex\n"
			 << "3 ---- Base & Derived\n"
			 << "4 ---- IPv4\n"
			 << "0 ---- Quit" << endl;
		cin >> choice;
		if(choice<=0)
			break;
		switch(choice)
		{
		case 1: mainMatrix(); break;
		case 2: mainComplex(); break;
		case 3: mainDerived(); break;
		case 4: mainIPv4(); break;
		}
	}
	return 0;
}
