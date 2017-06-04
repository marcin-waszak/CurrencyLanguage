#pragma once

#include "Node.h"

namespace ast {

class FunctionDefinitionNode : public Node
{
public:
	FunctionDefinitionNode(const std::string& name,
		std::vector<std::string>&& args, NodePtr&& block);

	ValuePtr evaluate(/*Scope& scope*/) const override;

private:
	const std::string name_;
	const std::vector<std::string> args_;
	NodePtr block_;
};

} // namespace ast
