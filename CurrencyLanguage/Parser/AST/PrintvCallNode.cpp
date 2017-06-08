#include "PrintvCallNode.h"
#include "Void.h"

namespace ast {

PrintvCallNode::PrintvCallNode(NodePtr&& value)
	: value_(std::move(value)) {

}

ValuePtr ast::PrintvCallNode::Evaluate(Scope& scope) const {
	auto evaluated = value_->Evaluate(scope);
	std::cout << evaluated->asNumber();
	return Value::Make<Void>();
}

}