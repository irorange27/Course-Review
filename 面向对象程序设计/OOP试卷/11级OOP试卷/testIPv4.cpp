// testIPv4.cpp
#include "IPv4.h"
#include <iomanip>

int mainIPv4()
{
	IPv4 ip;
	
	cout << ip << endl;
	for(ip="127.0.0.254"; ip<"127.0.1.2"; ip++)
		cout << dec << ip << '\t'
			 << hex << ip.get() << dec << endl;
	cout << ip << endl;
	ip[0] = 192;
	ip[1] = 168;
	ip[2] = 100;
	ip[3] = 1;
	cout << ip << '\t' << ip[0] << '.'
		 << ip[1] << '.' << ip[2] << '.' << ip[3] << endl;
	cout << hex << ip << endl << ip.get() << dec << endl << ip.get() << endl;;
	return 0;
}
