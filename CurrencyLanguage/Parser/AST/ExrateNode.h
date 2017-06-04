#pragma once

#include "Node.h"

namespace ast {

class ExrateNode : public Node
{
public:
	ExrateNode(NodePtr&& assign);

	ValuePtr evaluate(/*Scope& scope*/) const override;

private:
	const NodePtr assign_;
};

} // namespace ast
