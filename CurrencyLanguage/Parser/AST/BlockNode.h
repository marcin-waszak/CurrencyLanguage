#pragma once
#include "Node.h"
#include "Void.h"

#include <vector>

namespace ast {

class BlockNode : public Node {
public:
	BlockNode(std::vector<NodePtr>&& subtrees);
	BlockNode();

	ValuePtr evaluate(/*Scope& scope*/) const override;

private:
	const std::vector<NodePtr> subtrees_;
};

} // namespace ast
