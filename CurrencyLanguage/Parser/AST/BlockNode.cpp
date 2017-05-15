#include "BlockNode.h"

namespace ast {
	BlockNode::BlockNode(std::vector<NodePtr>&& subtrees)
		: subtrees_(std::move(subtrees)) {

	}

	BlockNode::BlockNode() {

	}
} // namespace ast
