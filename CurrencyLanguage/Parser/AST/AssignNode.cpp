#include "AssignNode.h"

namespace ast {

AssignNode::AssignNode(std::string& identifier, NodePtr&& value)
	: identifier_(identifier), value_(std::move(value)) {

}

ValuePtr AssignNode::Evaluate(Scope& scope) const {
	return scope.Lookup(identifier_) = EvaluateValue(scope);
}

ValuePtr AssignNode::EvaluateValue(Scope& scope) const {
	return value_->Evaluate(scope);
}

const std::string& AssignNode::GetIdentifier() const {
	return identifier_;
}

} // namespace ast
