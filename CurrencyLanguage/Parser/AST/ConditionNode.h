#pragma once
#include "Node.h"
#include "Void.h"

class ConditionNode : public Node
{
public:
	ConditionNode(NodePtr&& condition, NodePtr&& block, NodePtr&& else_block);
	ConditionNode(NodePtr&& condition, NodePtr&& block);

	ValuePtr evaluate(/*Scope& scope*/) const override;

private:
	const NodePtr condition_;
	const NodePtr block_;
	const NodePtr else_block_;
};
