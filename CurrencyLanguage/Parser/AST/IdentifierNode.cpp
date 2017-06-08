#include "IdentifierNode.h"

namespace ast {

IdentifierNode::IdentifierNode(const std::string& name)
	: name_(name) {

}

ValuePtr IdentifierNode::Evaluate(Scope& scope) const {
	return scope.Lookup(name_);
}

} // namespace ast
