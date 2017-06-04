#include "PrintvCallNode.h"

ast::PrintvCallNode::PrintvCallNode(NodePtr&& value)
	: value_(std::move(value)) {

}
