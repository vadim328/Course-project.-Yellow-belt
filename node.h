#pragma once

#include "date.h"


#include <string>
#include <iostream>
#include <exception>
#include <memory>

using namespace std;


enum class Comparison {
	Less,
	LessOrEqual,
	Greater,
	GreaterOrEqual,
	Equal,
	NotEqual,
};

enum class LogicalOperation {
	Or,
	And,
};

class Node {
public:
	virtual bool Evaluate(const Date& DATE, const string& EVENT) const = 0;

};

class EventComparisonNode : public Node {
public:

	EventComparisonNode(const Comparison& cmp, const string& event);
	bool Evaluate(const Date& DATE, const string& EVENT) const override;


private:
	const Comparison op_;
	const string event_to_comp;
};

class DateComparisonNode : public Node {
public:
	DateComparisonNode(const Comparison& cmp, const Date& date);
	bool Evaluate(const Date& DATE, const string& EVENT) const override;

private:
	const Comparison op_;
	const Date date_to_comp;
};

class EmptyNode : public Node {
public:
	EmptyNode();
	bool Evaluate(const Date& DATE, const string& EVENT) const override;
};


class LogicalOperationNode : public Node {
public:
	LogicalOperationNode(LogicalOperation log_op, shared_ptr<Node> left, shared_ptr<Node> right);
	bool Evaluate(const Date& DATE, const string& EVENT) const override;


private:
	shared_ptr<Node> right_, left_;
	const LogicalOperation log_op_;
};