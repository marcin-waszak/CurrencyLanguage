#pragma once
#include "Node.h"

namespace ast {

class AsNode : public Node
{
public:
	AsNode(NodePtr&& expression, const std::string currency_name);

	ValuePtr Evaluate(Scope& scope) const override;

private:
	const NodePtr expression_;
	const std::string currency_name_;
};

} // namespace ast
