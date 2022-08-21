#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>

using namespace std;

class Date {
public:
	Date(int year_, int month_, int day_);
	Date();

	int GetYear() const;
	int GetMonth() const;
	int GetDay() const;

	void SetDate(int new_year, int new_month, int new_day);

private:
	int year;
	int month;
	int day;
};

Date ParseDate(istream& is);

ostream& operator<<(ostream& os, const Date& date);

bool operator<(const Date& l_date, const Date& r_date);

bool operator>(const Date& l_date, const Date& r_date);

bool operator<=(const Date& l_date, const Date& r_date);

bool operator>=(const Date& l_date, const Date& r_date);

bool operator==(const Date& l_date, const Date& r_date);