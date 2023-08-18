// testMatrix.cpp
#include "matrix.h"

int mainMatrix()
{
	Matrix<int> a(3, 4);
	Matrix<char> c(2, 5, "HelloWorld");

	cout << c << endl;
	cout << a << endl;
	for(int i=0; i<a.Row(); i++)
	{
		for(int j=0; j<a.Col(); j++)
			a[i][j] = i+j;
	}
	cout << a << endl;
	return 0;
}
