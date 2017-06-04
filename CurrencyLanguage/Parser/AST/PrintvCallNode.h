#pragma once

#include "Node.h"

namespace ast {

class PrintvCallNode : public Node
{
public:
	PrintvCallNode(NodePtr&& value);

	ValuePtr evaluate(/*Scope& scope*/) const override;

private:
	const NodePtr value_;
};

} // namespace ast
