#pragma once

#include "Node.h"

namespace ast {

class VarDefinitionNode : public Node
{
public:
	VarDefinitionNode(NodePtr&& assign);

	ValuePtr evaluate(/*Scope& scope*/) const override;

private:
	const NodePtr assign_;
};

} // namespace ast
