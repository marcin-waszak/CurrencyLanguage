#pragma once

#include "Node.h"
#include "Void.h"
#include "FunctionValue.h"
#include "ReturnNode.h"

namespace ast {

class FunctionDefinitionNode : public Node
{
public:
	FunctionDefinitionNode(const std::string& name,
		std::vector<std::string>&& args, NodePtr&& block);

	ValuePtr Evaluate(Scope& scope) const override;
	ValuePtr Call(Scope& scope, const std::vector<ValuePtr>& arg_values) const;

private:
	const std::string name_;
	const std::vector<std::string> args_;
	NodePtr block_;
};

} // namespace ast
