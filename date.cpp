#include "date.h"

Date ParseDate(istream& is) {
	Date date;
	int year, month, day;
	is >> year;
	is.ignore(1);
	is >> month;
	is.ignore(1);
	is >> day;

	date.SetDate(year, month, day);

	return date;
}

Date::Date(int year_, int month_, int day_) : year(year_), month(month_), day(day_) {}
Date::Date() {}

int Date::GetYear() const {
	return year;
}

int Date::GetMonth() const {
	return month;
}

int Date::GetDay() const {
	return day;
}

void Date::SetDate(int new_year, int new_month, int new_day) {
	year = new_year;
	month = new_month;
	day = new_day;
}


ostream& operator<<(ostream& os, const Date& date) {
	os << setfill('0');
	os << setw(4) << date.GetYear();
	os << "-";
	os << setw(2) << date.GetMonth();
	os << "-";
	os << setw(2) << date.GetDay();
	return os;
}


bool operator<(const Date& l_date, const Date& r_date) {
	if (l_date.GetYear() < r_date.GetYear()) {
		return true;
	}
	else if (l_date.GetYear() > r_date.GetYear()) {
		return false;
	}
	else {
		if (l_date.GetMonth() < r_date.GetMonth()) {
			return true;
		}
		else if (l_date.GetMonth() > r_date.GetMonth()) {
			return false;
		}
		else {
			if (l_date.GetDay() < r_date.GetDay()) {
				return true;
			}
			else
				return false;
		}
	}
}

bool operator>(const Date& l_date, const Date& r_date) {
	if (l_date.GetYear() > r_date.GetYear()) {
		return true;
	}
	else if (l_date.GetYear() < r_date.GetYear()) {
		return false;
	}
	else {
		if (l_date.GetMonth() > r_date.GetMonth()) {
			return true;
		}
		else if (l_date.GetMonth() < r_date.GetMonth()) {
			return false;
		}
		else {
			if (l_date.GetDay() > r_date.GetDay()) {
				return true;
			}
			else
				return false;
		}
	}
}

bool operator<=(const Date& l_date, const Date& r_date) {
	if (l_date.GetYear() < r_date.GetYear()) {
		return true;
	}
	else if (l_date.GetYear() > r_date.GetYear()) {
		return false;
	}
	else {
		if (l_date.GetMonth() < r_date.GetMonth()) {
			return true;
		}
		else if (l_date.GetMonth() > r_date.GetMonth()) {
			return false;
		}
		else {
			if (l_date.GetDay() <= r_date.GetDay()) {
				return true;
			}
			else
				return false;
		}
	}
}

bool operator>=(const Date& l_date, const Date& r_date) {
	if (l_date.GetYear() > r_date.GetYear()) {
		return true;
	}
	else if (l_date.GetYear() < r_date.GetYear()) {
		return false;
	}
	else {
		if (l_date.GetMonth() > r_date.GetMonth()) {
			return true;
		}
		else if (l_date.GetMonth() < r_date.GetMonth()) {
			return false;
		}
		else {
			if (l_date.GetDay() >= r_date.GetDay()) {
				return true;
			}
			else
				return false;
		}
	}
}

bool operator==(const Date& l_date, const Date& r_date) {
	if (l_date.GetYear() != r_date.GetYear()) {
		return false;
	}

	else {
		if (l_date.GetMonth() != r_date.GetMonth()) {
			return false;
		}

		else {
			if (l_date.GetDay() == r_date.GetDay()) {
				return true;
			}
			else
				return false;
		}
	}
}

