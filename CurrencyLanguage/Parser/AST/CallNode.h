#pragma once

#include "Node.h"

namespace ast {

class CallNode : public Node
{
public:
	CallNode(const std::string& name, std::vector<NodePtr>&& args);

	ValuePtr evaluate(/*Scope& scope*/) const override;

private:
	const NodePtr name_;
	const std::vector<std::string> args_;
};

} // namespace ast
