#include "ReturnNode.h"
#include "Void.h"

namespace ast {

ReturnNode::ReturnNode(NodePtr&& expression)
	: expression_(std::move(expression)) {

}

ReturnNode::ReturnNode()
	: expression_(Node::Make<Void>()) {

}

ValuePtr ReturnNode::Evaluate(Scope& scope) const {
	throw ReturnHelper(expression_->Evaluate(scope));
}

} // namespace ast
