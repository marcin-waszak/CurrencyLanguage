#include "FunctionDefinitionNode.h"

namespace ast {

FunctionDefinitionNode::FunctionDefinitionNode(
	const std::string& name, std::vector<std::string>&& args, NodePtr&& block)
	: name_(name), args_(std::move(args)), block_(std::move(block)) {

}

ValuePtr FunctionDefinitionNode::Evaluate(Scope& scope) const
{
	scope.Add(name_) = std::make_unique<FunctionValue>(this);
	return Value::Make<Void>();
}

ValuePtr FunctionDefinitionNode::Call(Scope& scope, const std::vector<ValuePtr>& arg_values) const {
	if (args_.size() != arg_values.size()) {
		std::runtime_error("Bad arguments number");
	}

	Scope new_scope{ scope };
	for (size_t i = 0; i < args_.size(); ++i)
		new_scope.Add(args_[i]) = arg_values[i];

	try {
		return block_->Evaluate(new_scope);
	}
	catch (ReturnNode::ReturnHelper& ret) {
		return std::move(ret.return_value);
	}
}

} //ast
