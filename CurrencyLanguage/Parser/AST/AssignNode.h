#pragma once
#include "Node.h"
#include "Void.h"

namespace ast {

class AssignNode : public Node
{
public:
	AssignNode(std::string& identifier, NodePtr&& value);

	ValuePtr evaluate(/*Scope& scope*/) const override;

private:
	const std::string identifier_;
	const NodePtr value_;
};

} // namespace ast
