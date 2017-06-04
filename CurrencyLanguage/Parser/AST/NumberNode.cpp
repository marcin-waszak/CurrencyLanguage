#include "NumberNode.h"

namespace ast {

NumberNode::NumberNode(double number, const std::string currency_name)
	:  number_(number), currency_name_(currency_name) {

}

ValuePtr NumberNode::evaluate() const {

}

} // namespace ast
