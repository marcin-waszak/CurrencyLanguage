#include "VarDefinitionNode.h"

namespace ast {
	VarDefinitionNode::VarDefinitionNode(std::unique_ptr<AssignNode>&& assign)
		: assign_(std::move(assign)) {

	}

	ValuePtr VarDefinitionNode::Evaluate(Scope& scope) const {
		ValuePtr result = assign_->EvaluateValue(scope);
		return scope.AddVariable(assign_->GetIdentifier()) = std::move(result);
	}
}
