#pragma once
#include "date.h"
#include "database.h"
#include "condition_parser.h"
#include "node.h"

#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
#include <utility>
#include <functional>


using namespace std;

class Database {
public:
	void Add(const Date& date, const string& event);
	ostream& Print(ostream& os);

	int RemoveIf(function<bool(const Date&, const string&)> predicate);


	map<Date, vector<string>> FindIf(function<bool(const Date&, const string&)> predicate);
	map<Date, string> Last(const Date& date);

private:
	map<Date, vector<string>> data;
};


template <class T, class Q>
bool operator<(pair<T, Q> lh, pair<T, Q> rh) {
	return lh.first < rh.first;
}
