#include "VarDefinitionNode.h"

ast::VarDefinitionNode::VarDefinitionNode(NodePtr&& assign)
	: assign_(std::move(assign))
{

}


ast::VarDefinitionNode::~VarDefinitionNode()
{

}
