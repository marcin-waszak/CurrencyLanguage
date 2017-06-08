#include "Node.h"
#include "ReturnNode.h"

namespace ast {

Node::Node() {

}


Node::~Node() {

}

ValuePtr Node::Run() const {
	Scope root_scope;
	try {
		return Evaluate(root_scope);
	}
	catch (const ReturnNode::ReturnHelper& early_return) {
		return early_return.return_value;
	}
}

} // namespace ast
