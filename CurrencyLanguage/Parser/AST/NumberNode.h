#pragma once
#include "Node.h"
#include "NumberValue.h"

namespace ast {

class NumberNode : public Node
{
public:
	NumberNode(double number, const std::string currency_name = "");

	ValuePtr Evaluate(Scope& scope) const override;

private:
	const double number_;
	const std::string currency_name_;
};

} // namespace ast
