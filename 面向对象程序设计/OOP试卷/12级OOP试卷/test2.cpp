#include <iostream>
using namespace std;

void Swap(int &a, int &b)
{
	int temp;
	temp = a; a = b; b = temp;
}

void Swap_p(double *x, double *y)
{
	double temp  ;
	temp = *x; *x = *y; *y = temp;
}

int main_test2()
{
	int x = 3, y = 5;
	double a = 3.3, b = 5.5;
	Swap(x, y);
	Swap_p(&a, &b);
	cout << x << ", " << y << '\n'
		 << a << ", " << b << endl;
	return 0;
}
