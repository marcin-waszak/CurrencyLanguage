#include "LoopNode.h"

namespace ast {

LoopNode::LoopNode(NodePtr&& condition, NodePtr&& block)
	: condition_(std::move(condition)), block_(std::move(block))
{

}

ValuePtr LoopNode::evaluate() const
{
	//	Scope new_scope{ scope };
}

} // namespace ast
