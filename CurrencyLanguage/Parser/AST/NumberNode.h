#pragma once
#include "Node.h"

namespace ast {

class NumberNode : public Node
{
public:
	NumberNode(double number, const std::string currency_name = "");

	ValuePtr evaluate(/*Scope& scope*/) const override;

private:
	const double number_;
	const std::string currency_name_;
};

} // namespace ast
