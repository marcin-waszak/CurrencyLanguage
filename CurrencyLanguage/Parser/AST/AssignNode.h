#pragma once
#include "Node.h"
//#include "Void.h"

namespace ast {

class AssignNode : public Node
{
public:
	AssignNode(std::string& identifier, NodePtr&& value);

	ValuePtr Evaluate(Scope& scope) const override;
	ValuePtr EvaluateValue(Scope& scope) const;
	const std::string& GetIdentifier() const;

private:
	const std::string identifier_;
	const NodePtr value_;
};

} // namespace ast
