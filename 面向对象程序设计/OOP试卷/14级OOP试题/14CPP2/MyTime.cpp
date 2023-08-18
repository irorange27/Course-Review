// MyTime.cpp
#include "MyTime.h"
Time::Time(int hour, int minute, int second)
				: h(hour), m(minute), s(second)
{
}

Time & Time::operator++()
{
	s++;
	if(s==60){	s = 0; m++;	}
	if(m==60){	m = 0; h++;	}
	if(h==24)	h = 0;
	return *this;
}

Time Time::operator++(int)
{
	Time temp(*this);
	++(*this);
	return temp;
}

Time operator+(const Time &t, int n)
{
	Time result(t);
	int x = (t.h*60 + t.m)*60 + t.s + n;
	while(x<0)
		x += 24*60*60;
	x %= 24*60*60;
	result.s = x % 60;
	result.m = x/60 % 60;
	result.h = x/3600;
	return result;
}

ostream & operator<<(ostream &out, const Time &t)
{
	out << setfill('0') << setw(2) << t.h << ':'
		<< setw(2) << t.m << ':' << setw(2) << t.s << setfill(' ');
	return out;
}
istream & operator>>(istream &in, Time &t)
{
	char str[200];
	in.getline(str, 200, ':');
	t.h = atoi(str);
	in.getline(str, 200, ':');
	t.m = atoi(str);
	in.getline(str, 200);
	t.s = atoi(str);
	return in;
}

///////////////////////////////////////////
int Testing03a()
{
	Time t0(23,59,50), t;
	t=t0; cout << ++t << endl;
	t=t0; ++t; 	 cout << t << endl;
	t=t0; ++++t; cout << t << endl;
	t=t0; cout << t++ << endl;
	t=t0; t++;	 cout << t << endl;
	t=t0; t++++; cout << t << endl;
	t=t0; t=t+(-3600); cout << t << endl;
	cout << "ÇëÊäÈëÊ±¼ä(hh:mm:ss) : ";
	cin >> t;
	cout << t << endl;
	cout << ++t << endl;
	cout << t + (10*60+20)*60+30 << endl;
	return 0;
}
