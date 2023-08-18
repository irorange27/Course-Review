#include "LLINT.h"
int main_test4()
{
	LLINT x("888 777 666 555 444 333 234 567 890 987 654 321  "), y(100), z;
	cout << x << '\n' << y << '\n' << z << endl;
	z = "999 999 999 999 999 999";
	cout << z++ << endl;
	cout << z << endl;
	return 0;
}
