#include "Vector.h"

int main_test5()
{
	Vector v1, v2(5);
	
	cout << "v1 = " << v1 << ",\tv2 = " << v2 << endl;
	cin >> v1 >> v2;	// �磺���� (1, 2, 3, 4, 5, 6)(-1, 0, 1)
	cout << "v1 = " << v1 << ",\tv2 = " << v2 << endl;
	cout << "ִ�� v1 = v2;" << endl;
	cout << "v1 = " << (v1 = v2) << endl;
	cout << "ִ�� v1 *= 5;" << endl;
	v1 *= 5;
	cout << "v1 = " << v1 << endl;
	cout << "v1*v2 = " << v1*v2 << endl; 
	return 0;
}
