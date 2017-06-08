#pragma once

#include "Node.h"
#include <iostream>

namespace ast {

class PrintvCallNode : public Node
{
public:
	PrintvCallNode(NodePtr&& value);

	ValuePtr Evaluate(Scope& scope) const override;

private:
	const NodePtr value_;
};

} // namespace ast
