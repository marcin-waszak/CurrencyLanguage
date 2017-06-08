#include "BlockNode.h"

namespace ast {
	BlockNode::BlockNode(std::vector<NodePtr>&& statements)
		: statements_(std::move(statements)) {

	}

	BlockNode::BlockNode() {

	}

	ValuePtr BlockNode::Evaluate(Scope& scope) const
	{
		ValuePtr result = Value::Make<Void>();

		Scope new_scope{ scope };

		for (auto& statement : statements_)
			result = statement->Evaluate(new_scope);

		return result;
	}
} // namespace ast
