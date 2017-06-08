#include "ConditionNode.h"

namespace ast {

ConditionNode::ConditionNode(NodePtr&& condition, NodePtr&& block, NodePtr&& else_block)
	: condition_(std::move(condition)),
	block_(std::move(block)),
	else_block_(std::move(else_block)) {

}

ConditionNode::ConditionNode(NodePtr&& condition, NodePtr&& block)
	: ConditionNode(
		std::move(condition),
		std::move(block),
		Node::Make<Void>()) {

}

ValuePtr ConditionNode::Evaluate(Scope& scope) const {
	Scope new_scope{ scope };
	if (*condition_->Evaluate(new_scope))
		return block_->Evaluate(new_scope);
	else
		return else_block_->Evaluate(new_scope);
}

} // namespace ast
