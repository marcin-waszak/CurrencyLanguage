#pragma once
#include "Node.h"

namespace ast {

class IdentifierNode : public Node
{
public:
	IdentifierNode(const std::string& name);

	ValuePtr evaluate(/*Scope& scope*/) const override;

private:
	const std::string& name_;
};

} // namespace ast
