#pragma once

#include "Node.h"
#include "AssignNode.h"

namespace ast {

class VarDefinitionNode : public Node
{
public:
	VarDefinitionNode(std::unique_ptr<AssignNode>&& assign);

	ValuePtr Evaluate(Scope& scope) const override;

private:
	const std::unique_ptr<const AssignNode> assign_;
};

} // namespace ast
