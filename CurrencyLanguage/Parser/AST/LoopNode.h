#pragma once
#include "Node.h"

namespace ast {

class LoopNode : public Node
{
public:
	LoopNode(NodePtr&& condition, NodePtr&& block);

	ValuePtr evaluate(/*Scope& scope*/) const override;

private:
	const NodePtr condition_;
	const NodePtr block_;
};

} // namespace ast
