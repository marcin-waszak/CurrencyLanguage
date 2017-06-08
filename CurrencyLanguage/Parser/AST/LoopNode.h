#pragma once
#include "Node.h"
#include "Void.h"

namespace ast {

class LoopNode : public Node
{
public:
	LoopNode(NodePtr&& condition, NodePtr&& block);

	ValuePtr Evaluate(Scope& scope) const override;

private:
	const NodePtr condition_;
	const NodePtr block_;
};

} // namespace ast
