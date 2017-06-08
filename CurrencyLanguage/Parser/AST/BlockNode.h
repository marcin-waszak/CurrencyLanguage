#pragma once
#include "Node.h"
#include "Void.h"

#include <vector>

namespace ast {

class BlockNode : public Node {
public:
	BlockNode(std::vector<NodePtr>&& statements);
	BlockNode();

	ValuePtr Evaluate(Scope& scope) const override;

private:
	const std::vector<NodePtr> statements_;
};

} // namespace ast
