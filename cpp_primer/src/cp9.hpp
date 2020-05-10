#pragma once
#include "common.hpp"

class Date {
private:
	unsigned _year;
	unsigned _month;
	unsigned _day;

public:
	Date(const string &s);
};

void cp9_loop(void);
