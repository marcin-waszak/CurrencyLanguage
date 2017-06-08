#include "LoopNode.h"

namespace ast {

LoopNode::LoopNode(NodePtr&& condition, NodePtr&& block)
	: condition_(std::move(condition)), block_(std::move(block)) {

}

ValuePtr LoopNode::Evaluate(Scope& scope) const {
	Scope new_scope{ scope };

	while (condition_->Evaluate(new_scope))
		block_->Evaluate(new_scope);

	return Value::Make<Void>();
}

} // namespace ast
