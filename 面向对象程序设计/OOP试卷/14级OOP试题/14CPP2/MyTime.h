// MyTime.h
#ifndef MYTIME_H
#define MYTIME_H
#include <iostream>
#include <iomanip>
using namespace std;

class Time
{
public:
	Time(int hour=0, int minute=0, int second=0);
	Time & operator++();
	Time operator++(int);
	friend Time operator+(const Time &t, int n);
	friend ostream & operator<<(ostream &out, const Time &t);
	friend istream & operator>>(istream &in, Time &t);
protected:
	int h, m, s;
};

#endif
