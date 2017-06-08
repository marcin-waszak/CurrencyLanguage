#include "ExrateNode.h"

#include "Void.h"

namespace ast {

ExrateNode::ExrateNode(NodePtr&& assign)
	: assign_(std::move(assign))
{

}

ValuePtr ast::ExrateNode::Evaluate(Scope& scope) const
{
	return Value::Make<Void>();
}

}