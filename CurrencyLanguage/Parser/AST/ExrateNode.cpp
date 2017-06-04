#include "ExrateNode.h"

ast::ExrateNode::ExrateNode(NodePtr&& assign)
	: assign_(std::move(assign))
{

}


ast::ExrateNode::~ExrateNode()
{

}
