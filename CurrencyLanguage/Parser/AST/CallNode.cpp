#include "CallNode.h"

ast::CallNode::CallNode(const std::string& name, std::vector<NodePtr>&& args)
	: name_(name), args_(std::move(args)) {

}
