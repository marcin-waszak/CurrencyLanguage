#include "PrintsCallNode.h"
#include "Void.h"

namespace ast {

PrintsCallNode::PrintsCallNode(const std::string& text)
	: text_(text) {

}

ValuePtr ast::PrintsCallNode::Evaluate(Scope& scope) const {
	std::cout << text_;
	return Value::Make<Void>();
}

} //ast
