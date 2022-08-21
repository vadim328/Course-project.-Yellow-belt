#include "date.h"
#include "node.h"

EventComparisonNode::EventComparisonNode(const Comparison& cmp, const string& event) :
	op_(cmp), event_to_comp(event) {}

bool EventComparisonNode::Evaluate(const Date& DATE, const string& EVENT) const {
	if (op_ == Comparison::Equal) {
		return EVENT == event_to_comp;
	}
	else {
		return EVENT != event_to_comp;
	}
}


DateComparisonNode::DateComparisonNode(const Comparison& cmp, const Date& date) :
	op_(cmp), date_to_comp(date) {}

bool DateComparisonNode::Evaluate(const Date& DATE, const string& EVENT) const {
	if (op_ == Comparison::Equal) {
		return DATE == date_to_comp;
	}
	else if (op_ == Comparison::NotEqual) {
		return !(DATE == date_to_comp);
	}
	else if (op_ == Comparison::Greater) {
		return DATE > date_to_comp;
	}
	else if (op_ == Comparison::GreaterOrEqual) {
		return DATE >= date_to_comp;
	}
	else if (op_ == Comparison::Less) {
		return DATE < date_to_comp;
	}
	else {
		return DATE <= date_to_comp;
	}
}


EmptyNode::EmptyNode() {}
bool EmptyNode::Evaluate(const Date& DATE, const string& EVENT) const {
	return true;
};


LogicalOperationNode::LogicalOperationNode(LogicalOperation log_op, shared_ptr<Node> left, shared_ptr<Node> right) : log_op_(log_op), left_(left), right_(right) {}

bool LogicalOperationNode::Evaluate(const Date& DATE, const string& EVENT) const {
	if (log_op_ == LogicalOperation::And) {
		return (left_->Evaluate(DATE, EVENT) == true &&
			right_->Evaluate(DATE, EVENT) == true);
	}
	else
		return (left_->Evaluate(DATE, EVENT) == true ||
			right_->Evaluate(DATE, EVENT) == true);
}