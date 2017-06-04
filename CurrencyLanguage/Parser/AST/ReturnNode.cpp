#include "ReturnNode.h"
#include "Void.h"

namespace ast {

ReturnNode::ReturnNode(NodePtr&& expression)
	: expression_(std::move(expression)) {

}

ReturnNode::ReturnNode()
	: expression_(Node::Make<Void>()) {

}

ValuePtr ReturnNode::evaluate(/*Scope& scope*/) const {
	/*throw UglyHack(expression_->evaluate(scope));*/
}

} // namespace ast
