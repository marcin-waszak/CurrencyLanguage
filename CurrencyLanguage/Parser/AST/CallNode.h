#pragma once

#include "Node.h"

namespace ast {

class CallNode : public Node
{
public:
	CallNode(const std::string& name, std::vector<NodePtr>&& args);

	ValuePtr Evaluate(Scope& scope) const override;

private:
	const std::string name_;
	const std::vector<NodePtr> args_;
};

} // namespace ast
