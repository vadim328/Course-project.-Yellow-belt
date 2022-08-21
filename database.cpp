#include "database.h"
#include "condition_parser.h"
#include "node.h"

template <class T>
ostream& operator<<(ostream& os, vector<T> data) {
	for (const T& item : data) {
		os << item << " ";
	}
	os << endl;
	return os;
}
template <class T, class Q>
ostream& operator<<(ostream& os, map<T, Q> data) {
	for (const auto& item : data) {
		os << item.first << " " << item.second;
	}
	os << endl;
	return os;
}

void Database::Add(const Date& date, const string& event) {
	if (data.count(date) == 0) {
		data[date].push_back(event);
	}
	else {
		int q = count(data.at(date).begin(), data.at(date).end(), event);
		if (q == 0) {
			data[date].push_back(event);
		}
	}
}

ostream& Database::Print(ostream& os) {
	for (auto item : data) {
		os << item.first << " " << item.second;
	}
	return os;
}


int Database::RemoveIf(function<bool(const Date&, const string&)>
	predicate) {
	int N = 0;

	for (auto& item : data) {
		const Date& date = item.first;

		auto it = stable_partition((item.second).begin(), (item.second).end(),
			[date, predicate](string& event) {
				return predicate(date, event);
			});

		N += it - begin(item.second);
		if (N != 0) {
			(item.second).erase((item.second).begin(), it);
		}
	}

	return N;
}


map<Date, vector<string>> Database::FindIf(function<bool(const Date&, const string&)> predicate) {
	map<Date, vector<string>> result;
	for (auto item : data) {
		const Date& date = item.first;

		auto it = stable_partition((item.second).begin(), (item.second).end(),
			[date, predicate](const string& event_) {

				if (predicate(date, event_)) {
					return true;
				}
				else
					return false;
			});

		if (it != (item.second).begin()) {
			result[item.first] = vector<string>((item.second).begin(), it);
		}

	}
	return result;
}

map<Date, string> Database::Last(const Date& date) {
	map<Date, string> result;
	auto it = data.lower_bound(date);
	if (it->first == date) {
		result[it->first] = it->second.back();
		return result;
	}
	else {
		--it;
		result[it->first] = it->second.back();
		return result;
	}
}
