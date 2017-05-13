#pragma once
#include "Node.h"
#include "Value.h"

class Void : public Node, public Value
{
public:
	Void();

	ValuePtr evaluate(/*Scope& scope*/) const override;

	//std::ostream& show(std::ostream& out) const override;
};

