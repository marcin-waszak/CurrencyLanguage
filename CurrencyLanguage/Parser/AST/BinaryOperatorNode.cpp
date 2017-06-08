#include "BinaryOperatorNode.h"

#include "NumberValue.h"
#include "Void.h"

namespace ast {

BinaryOperatorNode::BinaryOperatorNode(Token::Type op, NodePtr&& lhs, NodePtr&& rhs)
	: op_(op) , lhs_(std::move(lhs)), rhs_(std::move(rhs)) {

}

ValuePtr BinaryOperatorNode::Evaluate(Scope& scope) const
{
    ValuePtr result;
    ValuePtr lhs_val = lhs_->Evaluate(scope);
    ValuePtr rhs_val = rhs_->Evaluate(scope);

    switch (op_) {
	case Token::Type::OR:
		result = Value::Make<NumberValue>((int)lhs_val->asNumber() || (int)rhs_val->asNumber());
		break;
	case Token::Type::AND:
		result = Value::Make<NumberValue>((int)lhs_val->asNumber() && (int)rhs_val->asNumber());
		break;
	case Token::Type::EQUAL:
		result = Value::Make<NumberValue>(*lhs_val == *rhs_val); //todo
		break;
	case Token::Type::UNEQUAL:
        result = Value::Make<NumberValue>(!(*lhs_val == *rhs_val)); // todo
        break;
	case Token::Type::LESS:
		result = Value::Make<NumberValue>(lhs_val->asNumber() < rhs_val->asNumber());
		break;
	case Token::Type::LESSEQ:
		result = Value::Make<NumberValue>(lhs_val->asNumber() <= rhs_val->asNumber());
		break;
	case Token::Type::GREATER:
		result = Value::Make<NumberValue>(lhs_val->asNumber() > rhs_val->asNumber());
		break;
	case Token::Type::GREATEREQ:
		result = Value::Make<NumberValue>(lhs_val->asNumber() >= rhs_val->asNumber());
		break;
	case Token::Type::PLUS:
        result = Value::Make<NumberValue>(lhs_val->asNumber() + rhs_val->asNumber());
        break;
	case Token::Type::MINUS:
        result = Value::Make<NumberValue>(lhs_val->asNumber() - rhs_val->asNumber());
        break;
	case Token::Type::MULTIPLY:
        result = Value::Make<NumberValue>(lhs_val->asNumber() * rhs_val->asNumber());
        break;
	case Token::Type::DIVIDE:
        result = Value::Make<NumberValue>(lhs_val->asNumber() / rhs_val->asNumber());
        break;
    default:
		throw std::runtime_error("Invalid operator");
    }

    return result;
}

} // namespace ast
