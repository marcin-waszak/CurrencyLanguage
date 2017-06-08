#pragma once

#include "Node.h"
#include <iostream>

namespace ast {

class PrintsCallNode : public Node
{
public:
	PrintsCallNode(const std::string& text);

	ValuePtr Evaluate(Scope& scope) const override;

private:
	const std::string text_;
};

} // namespace ast
