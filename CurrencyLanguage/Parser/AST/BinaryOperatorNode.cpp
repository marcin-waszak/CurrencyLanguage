#include "BinaryOperatorNode.h"

//#include "ListValue.hpp"
//#include "NumberValue.hpp"
#include "Void.h"

namespace ast {

BinaryOperatorNode::BinaryOperatorNode(Token::Type op, NodePtr&& lhs, NodePtr&& rhs)
	: op_(op) , lhs_(std::move(lhs)), rhs_(std::move(rhs))
{ }

ValuePtr BinaryOperatorNode::evaluate(/*Scope& scope*/) const
{
    ValuePtr result;/*
    ValuePtr lhs_val = lhs_->evaluate(scope);
    ValuePtr rhs_val = rhs_->evaluate(scope);

    switch (op) {
    case Keyword::Equals:
        if (*lhs_val == *rhs_val) {
            result = Value::make<Void>();
        } else {
            result = Value::make<ListValue>();
        }
        break;
    case Keyword::NotEquals:
        result = Value::make<NumberValue>(!(*lhs_val == *rhs_val));
        break;
    case Keyword::Plus:
        result = Value::make<NumberValue>(lhs_val->asInt() + rhs_val->asInt());
        break;
    case Keyword::Minus:
        result = Value::make<NumberValue>(lhs_val->asInt() - rhs_val->asInt());
        break;
    case Keyword::Mult:
        result = Value::make<NumberValue>(lhs_val->asInt() * rhs_val->asInt());
        break;
    case Keyword::Div:
        result = Value::make<NumberValue>(lhs_val->asInt() / rhs_val->asInt());
        break;
    default:
        std::stringstream ss{"Invalid operator: "};
        ss << op;
        throw std::runtime_error(ss.str());
    }
	*/
    return result;
}

} // namespace ast
