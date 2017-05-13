#include "ConditionNode.h"

ConditionNode::ConditionNode(NodePtr&& condition, NodePtr&& block, NodePtr&& else_block)
	: condition_(std::move(condition)),
	block_(std::move(block)),
	else_block_(std::move(else_block))
{

}

ConditionNode::ConditionNode(NodePtr&& condition, NodePtr&& block)
	: ConditionNode(
	std::move(condition),
	std::move(block),
	Node::make<Void>())
{

}

ValuePtr ConditionNode::evaluate() const
{
//	Scope new_scope{ scope };
	if (*condition_->evaluate(/*new_scope*/)) {
		return block_->evaluate(/*new_scope*/);
	}
	else {
		return else_block_->evaluate(/*new_scope*/);
	}
}
