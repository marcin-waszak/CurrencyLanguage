#include "FunctionValue.h"

namespace ast {

FunctionValue::FunctionValue(const FunctionDefinitionNode* function_ptr)
    : Value(Value::Type::Function), function_ptr_(function_ptr) {

}

//bool FunctionValue::operator==(const Value& rhs) const {
//    return Value::operator==(rhs) && asNumber() == rhs.asNumber();
//}

const FunctionDefinitionNode* FunctionValue::asFunction() const {
	return function_ptr_;
}

//std::ostream& NumberValue::show(std::ostream& out) const {
//    return out << value_;
//}

} // namespace ast
