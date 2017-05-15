#include "AssignNode.h"

namespace ast {

AssignNode::AssignNode(std::string& identifier, NodePtr&& value)
	: identifier_(identifier), value_(std::move(value)) {

}

} // namespace ast
