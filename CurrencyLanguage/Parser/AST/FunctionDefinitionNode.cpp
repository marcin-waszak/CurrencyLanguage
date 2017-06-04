#include "FunctionDefinitionNode.h"

ast::FunctionDefinitionNode::FunctionDefinitionNode(
	const std::string& name, std::vector<std::string>&& args, NodePtr&& block)
	: name_(name), args_(std::move(args)), block_(std::move(block))
{

}
