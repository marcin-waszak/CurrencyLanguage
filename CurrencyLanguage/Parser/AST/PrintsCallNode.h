#pragma once

#include "Node.h"

namespace ast {

class PrintsCallNode : public Node
{
public:
	PrintsCallNode(const std::string& text);

	ValuePtr evaluate(/*Scope& scope*/) const override;

private:
	const NodePtr text_;
};

} // namespace ast
