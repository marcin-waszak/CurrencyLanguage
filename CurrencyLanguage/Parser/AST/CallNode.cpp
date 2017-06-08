#include "CallNode.h"
#include "FunctionDefinitionNode.h"

namespace ast {

CallNode::CallNode(const std::string& name, std::vector<NodePtr>&& args)
	: name_(name), args_(std::move(args)) {

}

ValuePtr CallNode::Evaluate(Scope& scope) const
{
	std::vector<ValuePtr> eval_expressions;

	for (auto& arg : args_)
		eval_expressions.push_back(arg->Evaluate(scope));

	ValuePtr fun = scope.Lookup(name_);
	return fun->asFunction()->Call(scope, eval_expressions);
}

}